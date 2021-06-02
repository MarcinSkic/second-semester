#! /bin/bash
function showInfo(){    #Used to show first prompt
    printf "\nDysk info:\n"
    echo "Dysk-------------------------- $diskName"
    echo "Partycja---------------------- $directory"
    echo "Zuzycie dysku----------------- $currentUsage%"
    echo "Maksymalne zuzycie------------ $maxSize%"
    printf 'Ile miejsca nalezy zwolnic---- %s' "$totalSizeToDeleteInK"
    echo "K"
}
function showSingleFile(){  #Used to show number, size and path of file in one line + \n
    printf '%d. ' "$i"
    printf '%s' "$fileSize"
    printf "K " 
    echo $filePath
}
function getDirectory(){    #Used to get from user directory in which this program should search for files to delete
    while ((1)) 
    do
        echo "Podaj partycje ktora mam sledzic: [/home/<yourEntry>]"
        read userDirectory
        if [[ -d /home/$userDirectory ]]
        then
            directory=/home/$userDirectory
            break
        else
            echo "Taka sciezka nie istnieje, podaj jeszcze raz"
        fi
    done
}

function checkIfLimitIsCorrect(){   #Checks if user given right value of limit as parameter, if not asks him to enter it again
    maxSize=$1
    while ((1))
    do
        if ((maxSize < 10 || maxSize > 90))
        then
            echo "Zla wartosc granicy zuzycia podaj jeszcze raz (miedzy 10 a 90):"
            read maxSize
        else
            break
        fi
    done
}

function readEssentialData(){   #Sets all essential values into variables for future use in program
    currentUsage=$(df -h $directory | awk 'NR == 2 {print substr($5, 1, length($5)-1)}')    #Sets percentage of used space
    diskName=$(df -h $directory | awk 'NR == 2 {print $1}') #Sets disk name
    currentUsageInK=$(df $directory | awk 'NR == 2 {print $3}') #Sets usage of space in K
    availableSpaceInK=$(df $directory | awk 'NR == 2 {print $4}')   #Sets free space in K
    maxDiskSizeInK=$((currentUsageInK+availableSpaceInK))   #Calculates and sets total space in K
    totalSizeToDeleteInK=$(( $currentUsageInK - ($maxDiskSizeInK*$maxSize)/100 ))   #Calculates and sets how much data program has to delete
}

function deleteFiles(){ #Deletes all files stored in "confirmedFilesToDelete" and saves their paths in "saveFile" 
    for i in "${confirmedFilesToDelete[@]}"
    do
        rm -i $i

        if [ $? = 0 ] #This doesn't work as I imagined, are there solutions to this problem? I wish it gave info if user decided to delete or spare file
        then
            echo $i >> $saveFile
        fi
    done
    echo "Pliki usuniete z sukcesem, wracam do monitorowania"
}

getDirectory

checkIfLimitIsCorrect $1    #passing argument from user of the max disk usage in %

while ((1))
do
    sleep 60

    readEssentialData
    
    if ((currentUsage > maxSize))
    then
        

        showInfo

        while ((1)) #Asks user if he wants to do cleaning and waits for correct input
        do
            printf "\nPrzekroczono maksymalne zuzycie dysku, czy chcesz przeprowadzic czyszczenie? [y/n]"
            read choice
            if [[ ${choice^^} == "Y" ]]
            then
                returnedYesChoice=1
                break
            elif [[ ${choice^^} == "N" ]]
            then
                returnedYesChoice=0
                break
            else
                echo "Zly wybor, sprobuj jeszcze raz"
            fi
        done

        if ((!returnedYesChoice))
        then
            continue
        fi
   
        foundSizeToDeleteInK=0
        confirmedSizeToDeleteInK=0
        breakAtEnd=0

        declare -a filesToDelete
        declare -a confirmedFilesToDelete
        declare -a filesToPreserve

        while ((confirmedSizeToDeleteInK < totalSizeToDeleteInK))   #Loops as long as files waiting for delete are smaller than size needed to be deleted
        do
            echo

            echo "Pliki wybrane do usuniecia: "
            for f in "${confirmedFilesToDelete[@]}"
            do
                echo $f
            done
            echo "Pliki wybrane do zachowania: "
            for f in "${filesToPreserve[@]}"
            do
                echo $f
            done

            echo "Znalezione pliki: "
            exec 3< <(find $directory -type f -ls |  sort -k 2 -r -n )  #The outcome is list of all files in given directory sorted by size

            i=1
            while read line
            do

                fileSize="$(printf '%s' "$line" | awk '{printf "%s",$2}')"  #Gets size of file in line
                filePath="$(echo -n $line | awk '{print$11}')"  #Gets path of file in line

                if [[ " ${confirmedFilesToDelete[*]} " =~ ${filePath} || " ${filesToPreserve[*]} " =~ ${filePath} ]]    #Checks if file isn't already flagged for removal or preservation
                then
                    continue
                fi

                foundSizeToDeleteInK=$((foundSizeToDeleteInK + fileSize))
                filesToDelete+=("$filePath")

                showSingleFile  
                
                i=$((i+1))

                if (((foundSizeToDeleteInK+confirmedSizeToDeleteInK) >= totalSizeToDeleteInK))
                then
                    break
                fi            
            done <&3
            exec 3<&-
            
            if (((foundSizeToDeleteInK+confirmedSizeToDeleteInK) < totalSizeToDeleteInK))   #If program went through all files in directory and didn't found enough to clear space then it will break from the loop at the end
            then
                printf "\n\nNie istnieje tutaj wystarczajaco plikow do usuniecia zeby spelnic granice!\nProgram kontynuuje prace\n\n"
                breakAtEnd=1
                sleep 1
            fi

            while ((1)) #Asks user if he wants to choose files or delete everything and waits for correct input
            do
                printf "\nOto sugerowane pliki do usuniecia, czy chcesz je wybrac recznie? (w innym wypadku zostana usuniete wszystkie) [y/n]"
                read choice
                if [[ ${choice^^} == "Y" ]]
                then
                    returnedYesChoice=1
                    break
                elif [[ ${choice^^} == "N" ]]
                then
                    returnedYesChoice=0
                    break
                else
                    echo "Zly wybor, sprobuj jeszcze raz"
                fi
            done

            if ((returnedYesChoice == 0))   #Flags all found files to delete...
            then
                confirmedFilesToDelete+=("${filesToDelete[@]}")
                confirmedSizeToDeleteInK=$((confirmedSizeToDeleteInK+foundSizeToDeleteInK))
            else    #..or lets user choose which to delete
                echo "Podaj numery plikow do usuniecia: [np. 2 3 5 8 9 12]"
                read chosenNumbers
                
                for number in $chosenNumbers    #Loops through all numbers given by user
                do

                    if [[ ! $number =~ ^[0-9]+$ || $number -gt $((i-1)) || $number -lt 1 ]] #Checks if input is valid (it is number and is in range)
                    then
                        continue
                    fi

                    confirmedFilesToDelete+=("${filesToDelete[$((number-1))]}") #Flags file to delete
                    temp=$(du "${filesToDelete[$((number-1))]}" | awk '{print $1}')
                    confirmedSizeToDeleteInK=$((confirmedSizeToDeleteInK+temp))
                    unset "filesToDelete[$((number-1))]"

                done
                for f in "${filesToDelete[@]}"  #Files not chosen are flagged as files to preserve
                do
                    filesToPreserve+=("$f")
                done

            fi

            filesToDelete=()
            foundSizeToDeleteInK=0

            if ((breakAtEnd == 1))
            then
                break
            fi

        done

        saveFile="hdguard_$(date +'%m_%d_%y')_$(date +'%T').deleted"    #Creation of save file
        touch $saveFile

        deleteFiles #Deletes flagged files

        confirmedFilesToDelete=()
        confirmedSizeToDeleteInK=0
        filesToPreserve=()
    fi
done
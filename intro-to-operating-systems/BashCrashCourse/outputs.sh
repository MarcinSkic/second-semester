#! /bin/bash

ls -al 1>file1.txt 2>file2.txt
ls +al >file1.txt 2>&1  #Makes one file take both outputs standard and error
ls +al >& file1.txt #Same as above
.SUFFIXES: .c .o .a

%.o: %.c
	gcc -c $<
%: %.o
	gcc -o $@ $^

Code2: Code2.o libarea.a libvolume.a
Code2.o: Code2.c libarea.h libvolume.h
rectangleArea.o: rectangleArea.c
cuboidArea.o: cuboidArea.c
cuboidVolume.o: cuboidVolume.c
libarea.a: rectangleArea.o cuboidArea.o
	ar rs $@ $^ 
libvolume.a: cuboidVolume.o
	ar rs $@ $^
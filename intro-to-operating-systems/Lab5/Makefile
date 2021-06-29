
.SUFFIXES: .c .o .a
vpath %.c src
vpath %.h include
vpath lib%.a lib
vpath % bin
#VPATH = include src lib bin
%.o: %.c
	gcc -c $<
%: %.o
	gcc -o $@ $^ 
#-L./lib -I./include

thebeatles: thebeatles.o libjp.a libgr.a
thebeatles.o: thebeatles.c libjp.h libgr.h
pj.o: pj.c
pp.o: pp.c
pg.o: pg.c
pr.o: pr.c
libjp.a: pj.o pp.o
	ar rs $@ $^ 
libgr.a: pg.o pr.o
	ar rs $@ $^

CC=gcc
AR=ar
FLAGS= -O3 -fPIC -g -Wall -Werror


all:libmyBank.so libmyBank.a maind mains


maind: main.o libmyBank.so
	 $(CC) $(FLAGS)  -o maind main.o ./libmyBank.so
mains:  main.o libmyBank.a
	$(CC) $(FLAGS) -o mains main.o libmyBank.a

libmyBank.so: myBank.o
	$(CC) -shared -o libmyBank.so myBank.o

libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a myBank.o

main.o: myBank.h main.c
	  $(CC) $(FLAGS) -c main.c

myBank.o: myBank.h myBank.c
	 $(CC) $(FLAGS) -c myBank.c


.PHONY:clean all
clean:
	rm -f *.o *.a *.so mains maind 


CC = gcc
CFLAGS = -Wall
AR = ar  

all: StrList 

StrList: main.o libStrList.a
	$(CC) $(CFLAGS) -o $@ $^

libStrList.a: StrList.o
	$(AR) -rcs $@ $^

main.o: main.c StrList.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean all  

clean:  
	rm -f *.o *.a  StrList

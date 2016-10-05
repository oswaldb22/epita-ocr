# EPITA Project S3 - 2016/2017 
# Makefile 
# TODO : Put names  

# Compilers and options 
CC=gcc 
CPPFLAGS= -MMD 
CFLAGS= -Wall -Wextra -std=c99 -pedantic -O2 
LDFLAGS= 
LDLIBS=  

SRC = main.c
OBJ = src/${SRC:.c=.o} 
DEP = src/${SRC:.c=.d}  

all: main  

main: ${OBJ} build

-include ${DEP}

build:
	gcc src/main.o -o main

clean:      
	rm -f ${OBJ} ${DEP}
	rm -f main

# END

# EPITA Project S3 - 2016/2017 
# Makefile 
# TODO : Put names  

# Compilers and options 
CC=gcc 
CPPFLAGS= -MMD 
CFLAGS= -Wall -Wextra -std=c99 -pedantic -O2 
LDFLAGS= 
LDLIBS=  

# Linker
LINKER   = gcc -o
LFLAGS   = -Wall -I. -lm

# make 			-> Build the project
# make remove 	-> Remove .o and exe
# make clean 	-> Remove .o only

# ========== NO TOUCHY UNDER THE LINEY ========== #

# Directories
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

# Target
TARGET = main

# Sources
SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
# END

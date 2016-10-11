# EPITA Project S3 - 2016/2017 
# Makefile 
# TODO : Put names  

# Compilers and options 
CC=gcc 
CPPFLAGS= -MMD 
CFLAGS= -Wall -Wextra -std=c99 -pedantic -O2 
LDFLAGS= 
LDLIBS=`pkg-config --libs sdl` -lSDL_image

# Linker
LINKER   = gcc -o
LFLAGS   = -Wall -I. -lm

# make		-> Build the project
# make remove 	-> Remove .o .d and exe
# make clean 	-> Remove .o only
# make remdep	-> Remove .d only

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
DEPENDS  := $(wildcard $(OBJDIR)/*.d)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

all: makedirs $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

makedirs:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)
	@echo "Created directories : $(BINDIR) $(OBJDIR)"

.PHONEY: clean
clean:
	$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
	
.PHONEY: remdep
remdep:
	$(rm) $(DEPENDS)
	@echo "Dependencies removed!"
# END

# EPITA Project S3 - 2016/2017 
# Makefile 
# TODO : Put names  

# Compilers and options 
CC=gcc 
CPPFLAGS= `pkg-config --cflags sdl` -MMD 
CFLAGS= -Wall -Wextra -std=c99 -pedantic -O2 
LDFLAGS= 
LDLIBS=`pkg-config --libs sdl` -lSDL -lSDL_image

# make		-> Build the project
# make clean 	-> Remove .o .d and exe
# make remove 	-> Remove .o only
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
	@$(CC) $(OBJECTS) $(LDLIBS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

makedirs:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)
	@echo "Created directories : $(BINDIR) $(OBJDIR)"

.PHONEY: clean
clean: remove
	$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

.PHONEY: remove
remove:
	$(rm) $(OBJECTS)
	@echo "Cleanup complete!"
	
.PHONEY: remdep
remdep:
	$(rm) $(DEPENDS)
	@echo "Dependencies removed!"
# END

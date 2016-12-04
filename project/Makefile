# EPITA Project S3 - 2016/2017
# Makefile
# TODO : Put names

# Compilers and options
CC=gcc
CPPFLAGS= `pkg-config --cflags sdl gtk+-3.0` -MMD
CFLAGS= -Wall -Wextra -std=c99 -pedantic -O2
LDFLAGS=
LDLIBS=`pkg-config --libs sdl` `pkg-config  --libs gtk+-3.0 gmodule-2.0` -lSDL -lSDL_image -lm 

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
	@$(CC) $(OBJECTS) $(LDLIBS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo -e "[\e[92mOK\e[0m] Compiled "$<""

makedirs:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)
	@echo -e "[\e[92mOK\e[0m] Created directories : $(BINDIR) $(OBJDIR)"

.PHONEY: remove
remove:
	$(rm) $(OBJECTS)
	@echo -e "[\e[92mOK\e[0m] Cleanup complete!"

.PHONEY: clean
clean: remove remdep
	$(rm) $(BINDIR)/$(TARGET)
	@echo -e "[\e[92mOK\e[0m] Executable removed!"

.PHONEY: remdep
remdep:
	$(rm) $(DEPENDS)
	@echo "Dependencies removed!"
# END

#Define the C compiler to use
CC=gcc

#Define any compile -time flag
CFLAGS=-Wall -g #-Wall: Enable all warning messages, -g: Add debugging information

#Define the target executable name
TARGET=Lab2

#'all' is the default target. It's customary to have it as the first target.
#This target will be executed when you just type 'make' in the terminal
all: $(TARGET)

#This is the rule for creating the target executable.
#It depends on the source file (Target.c). If the source file is changed
#The target will be rebuilt when 'make' is run
$TARGET: $TARGET.C 
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c 

#Compile the source file into an executable
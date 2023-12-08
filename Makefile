# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: myprog.exe

# define a target to link the application
#
myprog.exe: myprog.o
	g++ -g -lm myprog.o -o myprog.exe

# define a target to clean the directory
#
clean:
	rm -f myprog.o myprog.exe

#
# end of file



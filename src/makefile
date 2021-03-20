#variables
CFLAGS = -Wall
EXE = stringTagReplace

#target exe
all: pointer_proj_small.o fileio.o stringmanip.o
	g++ -g $(CFLAGS) -o $(EXE) pointer_proj_small.o fileio.o stringmanip.o 

	
#rebuild object file if fileio.cpp, or fileio.h or constants.h changes
#compile the .cpp file to an object file (-c)
fileio.o: ../fileio/fileio.cpp ../includes/fileio.h ../includes/constants.h
	g++ $(CFLAGS) -c ../fileio/fileio.cpp
	
# stringmanip
stringmanip.o: ../parser/stringmanip.cpp ../includes/stringmanip.h ../includes/constants.h
	g++ $(CFLAGS) -c ../parser/stringmanip.cpp
	

# Main
pointer_proj_small.o: pointer_proj_small.cpp	
	g++ $(CFLAGS) -c ../src/pointer_proj_small.cpp

#type 'make clean' to remove following	
clean:
	rm -f *.o $(EXE)
	clear
	
# memcheck
memcheck:
	clear
	valgrind --tool=memcheck --leak-check=full -s ./$(EXE) ../data/test2 ../data/test_actual_out 'large' 'really large' 
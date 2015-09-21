CC = g++
PROGRAM = sortTesting 
OBJECTS = main.o
FLAGS = -Wall -g -std=c++0x -pthread

$(PROGRAM) : $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(PROGRAM)

%.o : %.cpp
	$(CC) $(FLAGS) -c $<

clean : 
	rm -f $(OBJECTS) $(PROGRAM)

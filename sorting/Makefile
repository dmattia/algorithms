CC = g++
PROGRAM = sortTesting 
OBJECTS = main.o

$(PROGRAM) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM)

%.o : %.cpp
	$(CC) -c $<

clean : 
	rm -f $(OBJECTS) $(PROGRAM)

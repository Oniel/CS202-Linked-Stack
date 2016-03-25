#Oniel Toledo        Assignment 13 makefile        CS202
#makefile for the provided stackTesting client program and
#the self created eval program

#current compiler
cc = g++
#objects to be created
OBJS1 = stackTesting.o
OBJS2 = eval.o
#linkedStack is the only dependecy all implementation
#definitions are found in the header file
DEPS1 = linkedStack.h

all: stackTesting eval

#create the stackTesting executable
stackTesting: $(OBJS1)
	$(cc) -o stackTesting $(OBJS1)

stackTesting.o: stackTesting.cpp $(DEPS1)
	$(cc) -c -g stackTesting.cpp

#create the eval executable
eval: $(OBJS2)
	$(cc) -o eval $(OBJS2)

eval.o: eval.cpp $(DEPS1)
	$(cc) -c -g eval.cpp

#remove objects 
clean:
	rm $(OBJS1)
	rm $(OBJS2)
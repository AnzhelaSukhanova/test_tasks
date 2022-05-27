all: main

CXXFLAGS=-O3 -w

main.o:
	$(CXX) -c main.cpp $(CXXFLAGS)
	
tasks.o:
	$(CXX) -c tasks.cpp $(CXXFLAGS)

main: main.o tasks.o
	$(CXX) $^ $(CXXFLAGS) -o $@
	rm -f *.o
	
clean:
	rm -f *.o main

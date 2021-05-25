CCC = g++ -std=c++11 -fopenmp

all: clean build

clean:
	rm -f BFS.o
	rm -f byte_matrix.o
	rm -f loadsave.o
	rm -f make_byte_matrix

build: BFS.o byte_matrix.o loadsave.o
	$(CCC) -o make_byte_matrix main.cpp BFS.o byte_matrix.o loadsave.o

BFS.o:
	$(CCC) -c BFS.cpp -o BFS.o

byte_matrix.o:
	$(CCC) -c byte_matrix.cpp -o byte_matrix.o

loadsave.o:
	$(CCC) -c loadsave.cpp -o loadsave.o

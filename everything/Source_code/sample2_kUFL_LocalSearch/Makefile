CCC = g++ -std=c++11 -fopenmp

all: clean build

clean:
	rm -f AlgoByJoachimAndKamyar.o
	rm -f vectorEkUFL_LocalSearch.o
	rm -f evaluateTwitter.o
	rm -f kMSolution.o
	rm -f loadsave.o
	rm -f fixedDouble.o
	rm -f SampleData.o
	rm -f BFS.o
	rm -f sample2_kUFL_LocalSearch

build: evaluateTwitter.o kMSolution.o loadsave.o AlgoByJoachimAndKamyar.o vectorEkUFL_LocalSearch.o fixedDouble.o SampleData.o BFS.o
	$(CCC) -o sample2_kUFL_LocalSearch main.cpp evaluateTwitter.o vectorEkUFL_LocalSearch.o AlgoByJoachimAndKamyar.o kMSolution.o loadsave.o fixedDouble.o BFS.o SampleData.o

AlgoByJoachimAndKamyar.o:
	$(CCC) -c AlgoByJoachimAndKamyar.cpp -o AlgoByJoachimAndKamyar.o

vectorEkUFL_LocalSearch.o:
	$(CCC) -c vectorEkUFL_LocalSearch.cpp -o vectorEkUFL_LocalSearch.o

evaluateTwitter.o:
	$(CCC) -c evaluateTwitter.cpp -o evaluateTwitter.o

kMSolution.o:
	$(CCC) -c kMSolution.cpp -o kMSolution.o

loadsave.o:
	$(CCC) -c loadsave.cpp -o loadsave.o

fixedDouble.o:
	$(CCC) -c fixedDouble.cpp -o fixedDouble.o

SampleData.o:
	$(CCC) -c SampleData.cpp -o SampleData.o

BFS.o:
	$(CCC) -c BFS.cpp -o BFS.o

CCC = g++ -std=c++11 -fopenmp

all: clean build

clean:
	rm -f AlgoByJoachimAndKamyar.o
	rm -f vectorEkUFL_LocalSearch.o
	rm -f evaluateTwitter.o
	rm -f kMSolution.o
	rm -f loadsave.o
	rm -f fixedDouble.o
	rm -f kUFL_LocalSearch

build: evaluateTwitter.o kMSolution.o loadsave.o AlgoByJoachimAndKamyar.o vectorEkUFL_LocalSearch.o fixedDouble.o
	$(CCC) -o kUFL_LocalSearch main.cpp evaluateTwitter.o vectorEkUFL_LocalSearch.o AlgoByJoachimAndKamyar.o kMSolution.o loadsave.o fixedDouble.o

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

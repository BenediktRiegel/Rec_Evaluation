all: clean build

clean:
	rm -f AlgoByJoachimAndKamyar.o
	rm -f vectorEkUFL_LocalSearch.o
	rm -f evaluateTwitter.o
	rm -f kMSolution.o
	rm -f loadsave.o
	rm -f fixedDouble.o
	rm -f sample_kUFL_LocalSearch

build: evaluateTwitter.o kMSolution.o loadsave.o AlgoByJoachimAndKamyar.o vectorEkUFL_LocalSearch.o fixedDouble.o
	g++ -fopenmp -o sample_kUFL_LocalSearch main.cpp evaluateTwitter.o vectorEkUFL_LocalSearch.o AlgoByJoachimAndKamyar.o kMSolution.o loadsave.o fixedDouble.o

AlgoByJoachimAndKamyar.o:
	g++ -fopenmp -c AlgoByJoachimAndKamyar.cpp -o AlgoByJoachimAndKamyar.o

vectorEkUFL_LocalSearch.o:
	g++ -c vectorEkUFL_LocalSearch.cpp -o vectorEkUFL_LocalSearch.o

evaluateTwitter.o:
	g++ -c evaluateTwitter.cpp -o evaluateTwitter.o

kMSolution.o:
	g++ -c kMSolution.cpp -o kMSolution.o

loadsave.o:
	g++ -c loadsave.cpp -o loadsave.o

fixedDouble.o:
	g++ -c fixedDouble.cpp -o fixedDouble.o

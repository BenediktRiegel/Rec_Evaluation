all: clean build

clean:
	rm -f evaluateTwitter.o
	rm -f fixedDouble.o
	rm -f kMSolution.o
	rm -f loadsave.o
	rm -f vectorRec_LocalSearch.o
	rm -f sample_RecLocalSearchEval

build: evaluateTwitter.o
	g++ -fopenmp -o sample_RecLocalSearchEval main.cpp evaluateTwitter.o Rec_sampling.o vectorRec_LocalSearch.o fixedDouble.o kMSolution.o loadsave.o

evaluateTwitter.o: Rec_sampling.o loadsave.o
	g++ -fopenmp -c evaluateTwitter.cpp -o evaluateTwitter.o

Rec_sampling.o: vectorRec_LocalSearch.o
	g++ -fopenmp -c Rec_sampling.cpp -o Rec_sampling.o

vectorRec_LocalSearch.o: fixedDouble.o kMSolution.o
	g++ -fopenmp -c vectorRec_LocalSearch.cpp -o vectorRec_LocalSearch.o

fixedDouble.o:
	g++ -fopenmp -c fixedDouble.cpp -o fixedDouble.o

kMSolution.o:
	g++ -fopenmp -c kMSolution.cpp -o kMSolution.o

loadsave.o:
	g++ -fopenmp -c loadsave.cpp -o loadsave.o

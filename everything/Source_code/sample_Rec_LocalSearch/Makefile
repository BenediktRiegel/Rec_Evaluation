CCC = g++ -std=c++11 -fopenmp

all: clean build

clean:
	rm -f evaluateTwitter.o
	rm -f fixedDouble.o
	rm -f kMSolution.o
	rm -f loadsave.o
	rm -f vectorRec_LocalSearch.o
	rm -f sample_RecLocalSearchEval

build: evaluateTwitter.o
	$(CCC) -o sample_RecLocalSearchEval main.cpp evaluateTwitter.o Rec_sampling.o vectorRec_LocalSearch.o fixedDouble.o kMSolution.o loadsave.o

evaluateTwitter.o: Rec_sampling.o loadsave.o
	$(CCC) -c evaluateTwitter.cpp -o evaluateTwitter.o

Rec_sampling.o: vectorRec_LocalSearch.o
	$(CCC) -c Rec_sampling.cpp -o Rec_sampling.o

vectorRec_LocalSearch.o: fixedDouble.o kMSolution.o
	$(CCC) -c vectorRec_LocalSearch.cpp -o vectorRec_LocalSearch.o

fixedDouble.o:
	$(CCC) -c fixedDouble.cpp -o fixedDouble.o

kMSolution.o:
	$(CCC) -c kMSolution.cpp -o kMSolution.o

loadsave.o:
	$(CCC) -c loadsave.cpp -o loadsave.o

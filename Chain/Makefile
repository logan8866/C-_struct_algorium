Run:chain.h chain.cpp main.cpp main5.cpp chain5.cpp josephus.h josephus.cpp josephus_run.cpp
	g++ -c chain.cpp
	g++ -c main.cpp 
	g++ -c chain5.cpp
	g++ -c main5.cpp
	g++ -c josephus.cpp
	g++ -c josephus_run.cpp
	g++ -o Run5 chain.o chain5.o main5.o
	g++ -o Run chain.o main.o
	g++ -o Run_josephus chain.o josephus_run.o josephus.o

clear:
	rm *.o
	rm Run
	rm Run5


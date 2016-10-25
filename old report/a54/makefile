OBJ = arguments.o process.o printprocess.o

#memory/memory.ih.gch: memory/memory.ih
#	g++ -std=c++11 -x c++-header $<

%.o: %.cc main.ih
	g++ -std=c++11 -Wall -c -o $@ $<

main: main.cc $(OBJ) main.h
	g++ -std=c++11 -Wall -o main main.cc $(OBJ) main.h

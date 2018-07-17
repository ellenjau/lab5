all:lab5

lab5:practice.o main.o
	g++ -o lab5 practice.o main.o
practice.o:practice.cpp practice.h
	g++ -c practice.cpp
main.o:main.cpp practice.h
	g++ -c main.cpp
clean:
	rm lab5 *.o

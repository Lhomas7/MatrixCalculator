#this is the makefile for the matrix calculator

compile:
	g++ -Wall Matrix.cpp main.cpp -o calculate.out

run:
	./calculate.out

clean:
	rm *.out

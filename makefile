#this is the makefile for the matrix calculator
#AUTHOR: Landon Thomas

#compile command to compile files
compile:
	g++ -Wall Matrix.cpp main.cpp -o calculate.out

#run command to execute .out file
run:
	./calculate.out

#clean command to remove .out files once finished
clean:
	rm *.out

//This is the header file for the matrix class.
//
#include <iostream>
#include <vector>
using namespace std;
#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
	protected:
		int rows;
		int cols;
		int** matrix;
	public:
		Matrix();
		Matrix(int row, int col);
		~Matrix();
		void setRow(int row) {this->rows = row;}
		void setCol(int col) {this->cols = col;}
		int getRow(){return this->rows;}
		int getCol(){return this->cols;}
		int** getMatrix() {return this->matrix;}
		void fillMatrix(int row, int col, int num);
		void printMatrix();
		int** operator+(const Matrix& matrix2);
		Matrix operator-(const Matrix& matrix2);
		//Matrix operator*(Matrix& matrix2 const);
		bool operator=(const Matrix& matrix2);
};

#endif

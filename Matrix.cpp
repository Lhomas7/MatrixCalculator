#include "Matrix.h"

Matrix::Matrix() {
	this->rows = 3;
	this->cols = 3;

	matrix = new int*[3];

	for (int i = 0; i < 3; ++i) {
		matrix[i] = new int[3];
	}
}

Matrix::Matrix(int row, int col) {
	this->rows = row;
	this->cols = col;

	matrix = new int*[rows];

	for (int i = 0; i < cols; ++i) {
		matrix[i] = new int[cols];
	}
}


void Matrix::fillMatrix(int row, int col, int num) {
	this->matrix[row - 1][col - 1] = num;
}

void Matrix::printMatrix() {
	for(int i = 0; i < rows; i++) {
		cout << "|";
		for (int j = 0; j < cols - 1; j++) {
			cout << this->matrix[i][j] << " ";
		}
		cout << this->matrix[i][cols - 1] << "|" << endl;
	}
}

Matrix Matrix::operator+(const Matrix& matrix2) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			this->matrix[i][j] += matrix2.matrix[i][j];
		}
	}

	return *this;
}

Matrix Matrix::operator-(const Matrix& matrix2) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			this->matrix[i][j] -= matrix2.matrix[i][j];
		}
	}

	return *this;
}

//Matrix Matrix::operator*(Matrix& matrix2 const) {}

bool Matrix::operator=(const Matrix& matrix2) {
	if (this->matrix == matrix2.matrix) {
		return true;
	}
	return false;
}

Matrix::~Matrix() {
	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}

	delete[] matrix;
}



			
	

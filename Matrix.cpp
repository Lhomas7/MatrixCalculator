#include "Matrix.h"
//Matrix base constructor
Matrix::Matrix() {
	//by default set rows and columns to 3 for
	//3x3 matrix
	this->rows = 3;
	this->cols = 3;
	
	//allocate space for 3 rows
	matrix = new int*[3];
 
	//int each row, allocate space for each column
	for (int i = 0; i < 3; ++i) {
		matrix[i] = new int[3];
	}
}

//Matrix overloaded constructor
Matrix::Matrix(int row, int col) {
	//set number of rows and columns to rows and columns passed
	//in parameters
	this->rows = row;
	this->cols = col;

	//allocate space for number of rows
	matrix = new int*[rows];

	//for each row, allocate enough space for
	//columns
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new int[cols];
	}
}

//fill matrix member function
void Matrix::fillMatrix(int row, int col, int num) {

	//place the number in parameter into the 
	//position input 
	this->matrix[row - 1][col - 1] = num;
}

//function to display the matrix
void Matrix::printMatrix() {

	//iterate through rows of the matrix
	for(int i = 0; i < rows; i++) {
		//output the side of matrix art beginning of each row
		cout << "|";

		//iterate through the columns stopping at second to last index
		//output each entry followed by a space
		for (int j = 0; j < cols - 1; j++) {
			cout << this->matrix[i][j] << " ";
		}
		//output rightside of the matrix
		cout << this->matrix[i][cols - 1] << "|" << endl;
	}
}

//overload matrix addition
int** Matrix::operator+(const Matrix& matrix2) {

	//allocate space for a new matrix to hold added
	//values
	int** newMatrix = new int*[rows];
	for (int i = 0; i < rows; ++i) {
		newMatrix[i] = new int[cols];
	}

	//iterate through both matrices summing the 
	//corresponding row column coordinates and
	//placing the result into the new matrix at
	//the same coordinates
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			newMatrix[i][j] = matrix[i][j] + matrix2.matrix[i][j];
		}
	}

	//iterate through the rows of the original matrix
	//and deallocate the memory
	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	
	//deallocate the memory of the whole matrix
	delete[] matrix;

	//reassign the old matrix to the new added matrix
	this->matrix = newMatrix;

	//return the matrix
	return this->matrix;
}

//member function that overloads subtraction operator
int** Matrix::operator-(const Matrix& matrix2) {

	//allocate memory for a new matrix to hold
	//subtracted values
	int** newMatrix = new int*[rows];
	for (int i = 0; i < rows; ++i) {
		newMatrix[i] = new int[cols];
	}

	//iterate through the matrices, subtracting the corresponding
	//values in the second matrix from the first, and placing
	//the result in the new matrix
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			newMatrix[i][j] = this->matrix[i][j] - matrix2.matrix[i][j];
		}
	}


	//iterate through the rows of the original matrix and deallocate 
	//the memory
	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	//deallocate memory of the whole matrix
	delete[] matrix;

	//reassign the original matrix to the new one
	this->matrix = newMatrix;

	//return the matrix
	return this->matrix;
}
//TODO: implement matrix multiplication operator overload
//Matrix Matrix::operator*(Matrix& matrix2 const) {}


//member function to overload equals operator
bool Matrix::operator==(const Matrix& matrix2) {
	if (this->matrix == matrix2.matrix) {
		return true;
	}
	return false;
}

//Matrix destructor member function
Matrix::~Matrix() {
	//when finished using the matrix object, iterate
	//through the rows of matrix and deallocate each row
	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}

	//lastly, deallocate the whole matrix
	delete[] matrix;
}



			
	

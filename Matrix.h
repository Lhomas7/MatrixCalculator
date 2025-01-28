//This is the header file for the matrix class.
//
/*AUTHOR: Landon Thomas
 * PersonalProjects
 * Matrix Calculator
 */

#include <iostream>
using namespace std;
#ifndef MATRIX_H
#define MATRIX_H

/*Matrix Class
 * stores the number of rows and columns of a given matrix,
 * and contains a number of member functions that perform operations on 
 * the matrix. Currently utilizes matrix addition and subtraction
 */
class Matrix {
	//private variables
	private:
		int rows;
		int cols;
		int** matrix;
	//public variables
	public:
		/*Parameters: none
		 * Return value: none
		 * This is the constructor of the Matrix class, it will by default 
		 * make a 3 by 3 matrix array and set the number of rows and columns to 
		 * 3 as well.
		 */
		Matrix();

		/*Parameters: int row- number of rows in the matrix
		 * 	      int col- number of columns in the matrix
		 * Return value: none
		 * This is the overloaded matrix constructor which initializes
		 * the number of rows and columns of the matrix given as parameters
		 * and creates a matrix of those proportions
		 */
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
		int** operator-(const Matrix& matrix2);
		//Matrix operator*(Matrix& matrix2 const);
		bool operator=(const Matrix& matrix2);
};

#endif

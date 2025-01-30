//This is the header file for the matrix class.
//
/*AUTHOR: Landon Thomas
 * PersonalProjects
 * Matrix Calculator
 */
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

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

		/*Parameters: None
		 * Return value: none
		 * This is the destructor for the Matrix class, which will free
		 * all allocated data contained within an object of the class's
		 * matrix pointer
		 */
		~Matrix();

		/*Parameters: int row - the number of rows for a given matrix
		 * return value: none
		 * This is the setter function for the object's row attribute,
		 * which sets the number of rows
		 */
		void setRow(int row) {this->rows = row;}

		/*Parameters: int col- number of columns for a given matrix
		 * return value: none
		 * This is the setter for the columns attribute in the matrix
		 * class
		 */
		void setCol(int col) {this->cols = col;}

		/*Parameters: none
		 * return value: int rows- number of rows in the matrix
		 * This is the getter member function for the matrix's rows
		 */
		int getRow(){return this->rows;}

		/*Parameters: none
		 * return value: int cols- number of columns in the matrix
		 * This is the getter member function for the matrix's columns
		 */
		int getCol(){return this->cols;}

		/*Parameters: none
		 * return value: int** matrix - returns a double int pointer to a 2D array
		 * This is the getter for the Matrix's array member variable
		 */
		int** getMatrix() {return this->matrix;}

		/*Parameters: int row - index of row in matrix object
		 * 	      int col - index of column in a matrix object
		 * 	      int num - number to place at a spot in the matrix
		 * return value: none
		 * This function will place an integer given as input into a specific
		 * spot in the matrix given as a row and column index in the parameter
		 * as well
		 */
		void fillMatrix(int row, int col, int num);

		/*Parameters: none
		 * return value: none
		 * This member function will print out the matrix in a typical
		 * form one might see on paper
		 */
		void printMatrix();

		/*Parameters: Matrix matrix2 - second matrix object
		 * return value: int** - returns a double int pointer or 2D array
		 * This member function overloads the + operator to perform
		 * matrix addition between two matrix classes.
		 */
		int** operator+(const Matrix& matrix2);

		/*Parameters: Matrix matrix2 - second matrix object
		 * return value: int** - returns a double int pointer or 2D array
		 * This member function overloads the - operator to perform
		 * matrix subtraction between two given matrix objects
		 */ 
		int** operator-(const Matrix& matrix2);

		//TO BE IMPLEMENTED: Matrix Multiplication
		//Matrix operator*(Matrix& matrix2 const);
		
		/*Parameters: Matrix matrix2 - second matrix object
		 * return value: bool- returns true or false
		 * This member function will overload the = operator
		 * to check if a matrix can be multiplied by another matrix
		 * by seeing if the number of rows in matrix2 matches
		 * the number of columns in the calling matrix object
		 */
		bool operator==(const Matrix& matrix2);
};

#endif

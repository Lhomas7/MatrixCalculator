#include "Matrix.h"

/*AUTHOR: Landon Thomas
 * Personal Project
 * Matrix Calculator
 */


//main function acting as a driver for the matrix operations
int main() {

	//set quit variable to false to use later when determining if
	//user wants to exit program
	bool quit = false;

	//Welcome message
	cout << "Welcome to the Matrix calculator!" << endl;
	cout << "***Currently only implements matrix addition and subtraction for integer matrices***" <<< endl;

	//menu is based on a while loop to ensure program keeps running
	//as long as user intends
	while (!quit) {

		//menu display to show options for altering matrices
		cout << "Please select one of the options below: " << endl;
		char choice;
		cout << "[A] Matrix addition" << endl;
		cout << "[B] Matrix subtraction" << endl;
		//cout << "[C] Matrix Multiplication" << endl;
		//cout << "[D] Print Matrix" << endl;
		cout << "[E] Quit" << endl;

		//get the user-inputting opetion and set it to lowercase
		cin >> choice;
		choice = tolower(choice);

		//switch statement to evaluate what operation to do based on the user's choice
		switch (choice) {
			//if choice is 'a' for addition, evaluate here
			case 'a': {
				//declare int and col variables to take in the dimensions of the matrices
				int row, col;
				//get the user input for dimensions
				cout << "Please give the dimensions of the matrices: ";
				cin >> row >> col;

				//allocate space to hold a matrix of dimensions row and col
				Matrix* matrix1 = new Matrix(row, col);

				//loop through the matrix
				for (int i = 1; i <= row; ++i) {
					for (int j = 1;j <= col; ++j) {
						//ask for userinput for each index in the matrix
						cout << "Please enter the value for row " << i << " column " << j << ": ";

						//take in input and call matrix fill function to place value at specified 
						//coordinates
						int value;
						cin >> value;
						matrix1->fillMatrix(i, j, value);

					}
					//print out the matrix after each row is filled, with uninitialized rows being 
					//all zeros
					matrix1->printMatrix();
				}

				//allocate space for second matrix to add to first
				Matrix* matrix2 = new Matrix(row, col);

				//iterate through second matrix of same dimensions
				for (int i = 1; i <= row; ++i) {
					for (int j = 1; j <= col; ++j) {
						//take in value for each index in the matrix
						cout << "Please enter the value for row " << i << " column " << j << ": ";
						int value;
						cin >> value;

						//place value in matrix using fillmatrix member function
						matrix2->fillMatrix(i, j, value);
					}
					//print out matrix after each row is filled, with uninitialized rows being all zeros
					matrix2->printMatrix();
				}

				//add two matrices together to overload + operator
				(*matrix1) + (*matrix2);

				//print out resulting matrix
				cout << "your resulting matrix is: " << endl;
				matrix1->printMatrix();

				//free allocated memory to both matrices
				free(matrix1);
				free(matrix2);
				
				//break out of case
				break;
			}
			//case b for matrix subtraction 
			case 'b': {
				//declare row and col variables to hold dimensions of matrices
				int row, col;

				//ask user for dimensions and take in these values
				cout << "Please give the dimensions of the matrices: ";
				cin >> row >> col;

				//allocate memory for the first matrix
				Matrix*	matrix_1 = new Matrix(row, col);

				//iterate through the first matrix
				for (int i = 1; i <= row; ++i) {
					for (int j = 1; j <= col; ++j) {
						//ask user to input each value at each index in the matrix and take in the values
						cout << "Please enter the value for row " << i << " column " << j << ": ";
						int value;
						cin >> value;

						//place value in the corresponding index in the matrix
						matrix_1->fillMatrix(i, j, value);
					}
					//print the matrix after each row with uninitialized rows being all zeros
					matrix_1->printMatrix();
				}

				//allocate space for a second matrix of the same dimensions
				Matrix* matrix_2 = new Matrix(row, col);

				//iterate through second matrix
				for (int i = 1; i <= row; ++i) {
					for (int j = 1; j <= col; ++j) {
						//ask for each value at each index in matrix and take in that value from the user
						cout << "Please enter the value for row " << i << " column " << j << ": ";
						int value;
						cin >> value;

						//place value in the matrix at its corresponding coordinates
						matrix_2->fillMatrix(i, j, value);
					}
					//print matrix out after each row is filled, with unfilled rows being all zeros
					matrix_2->printMatrix();
				}

				//perform the matrix subtraction by calling the - overloading operator
				(*matrix_1) - (*matrix_2);

				//print out resulting matrix
				cout << "your resulting matrix is: " << endl;
				matrix_1->printMatrix();

				//free allocated memory to each matrix
				free(matrix_1);
				free(matrix_2);

				//break out of case
				break;
			}
			//case 'e' for exitting program
			case 'e': {
				//set quit to true, ending the while loop and menu
				quit = true;

				//print out goodbye statement
				cout << "thanks for using the matrix calculator!" << endl;

				//break out of case
				break;
			}
		}
	}
	//return 0 when finshed to exit code
	return 0;
}


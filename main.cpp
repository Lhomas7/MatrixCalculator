#include "Matrix.h"

/*AUTHOR: Landon Thomas
 * Personal Project
 * Matrix Calculator
 */


//main function acting as a driver for the matrix operations
int main() {

	bool quit = false;
	cout << "Welcome to the Matrix calculator!" << endl;

	while (!quit) {
		cout << "Please select one of the options below: " << endl;
		char choice;
		cout << "[A] Matrix addition" << endl;
		cout << "[B] Matrix subtraction" << endl;
		//cout << "[C] Matrix Multiplication" << endl;
		//cout << "[D] Print Matrix" << endl;
		cout << "[E] Quit" << endl;

		cin >> choice;

		choice = tolower(choice);

		switch (choice) {
			case 'a': {
				int row, col;
				cout << "Please give the dimensions of the matrices: ";
				cin >> row >> col;

				Matrix* matrix1 = new Matrix(row, col);

				//cout << "Please type the values for the matrix: ";
				for (int i = 1; i <= row; ++i) {
					for (int j = 1;j <= col; ++j) {
						cout << "Please enter the value for row " << i << " column " << j << ": ";
						int value;
						cin >> value;
						matrix1->fillMatrix(i, j, value);

					}
					matrix1->printMatrix();
				}

				//cout << "Please give the dimensions of the second matrix: ";
				//cin >> row >> col;

				Matrix* matrix2 = new Matrix(row, col);

				//cout << "Please type the values for the matrix: ";
				for (int i = 1; i <= row; ++i) {
					for (int j = 1; j <= col; ++j) {
						cout << "Please enter the value for row " << i << " column " << j << ": ";
						int value;
						cin >> value;
						matrix2->fillMatrix(i, j, value);
					}
					matrix2->printMatrix();
				}

				(*matrix1) + (*matrix2);


				cout << "your resulting matrix is: " << endl;

				matrix1->printMatrix();
				free(matrix1);
				free(matrix2);
				break;
			}
			case 'b': {
				int row, col;
				cout << "Please give the dimensions of the matrices: ";
				cin >> row >> col;

				Matrix*	matrix_1 = new Matrix(row, col);

				//cout << "Please type the values for the matrix: ";
				for (int i = 1; i <= row; ++i) {
					for (int j = 1; j <= col; ++j) {
						cout << "Please enter the value for row " << i << " column " << j << ": ";
						int value;
						cin >> value;
						matrix_1->fillMatrix(i, j, value);
					}
					matrix_1->printMatrix();
				}

				Matrix* matrix_2 = new Matrix(row, col);

				//cout << "Please type the values for the matrix: ";
				for (int i = 1; i <= row; ++i) {
					for (int j = 1; j <= col; ++j) {
						cout << "Please enter the value for row " << i << " column " << j << ": ";
						int value;
						cin >> value;
						matrix_2->fillMatrix(i, j, value);
					}
					matrix_2->printMatrix();
				}

				(*matrix_1) - (*matrix_2);

				cout << "your resulting matrix is: " << endl;

				matrix_1->printMatrix();
				free(matrix_1);
				free(matrix_2);
				break;
			}
			case 'e': {
				quit = true;
				cout << "thanks for using the matrix calculator!" << endl;
				break;
			}
		}
	}
					
	return 0;
}


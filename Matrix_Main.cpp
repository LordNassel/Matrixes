#include "Matrix.h"
#include "vld.h"
#include "vld_def.h"
#include <iostream>
#include <fstream>

using namespace std;

/*GLOBAL FUNCTION*/
Matrix* GlobalFunction(int Size)
{
	Matrix* Identity = new Matrix(Size, Size);
	return Identity;
}

/*MAIN FUNCTION*/
int main(int argc, char* argv[])
{
	cout << "\n\n\t\t\t\t\t\t"<< "Welcome User!" <<"\n\n" <<endl;
	cout << "Step One:" << endl;
	cout << "[PRESS 1] to scan your Matrixes from alread given files OR [PRESS 2] to give your Own." << endl;

	int number = 0;
	int OtherNumber = 0;

	/*SWITCH*/
	do 
	{
		if (!(cin >> number))
		{
			cerr << "It was not a correct unit, try again!" << endl;
			cin.clear(); //clears the error flag on cin (so that future I/O operations will work correctly)
			cin.ignore(10000, '\n'); //Skips to the next newline.
		}
		if(number!= 1 && number!=2)
		cerr << "It was not a correct number, try again!" << endl;
	}while ((number!=1 && number!=2));


	
	if (number == 1)
	{
		Matrix A;
		A.Upload_From_File();
		A.Print_Matrix(A);

		cout << "Other Matrix:" << endl;
		Matrix B;
		B.Upload_From_File_2();
		B.Print_Matrix(B);
		
		OtherNumber = (A.Operand(A, B));

		if (OtherNumber == 1)
		{
			A.operator*(B);
			cout << "Result of Multiply:" << endl;
			A.Print_Matrix(A);
			A.Print_to_file(A);
		}

		if (OtherNumber == 2)
		{
			A.operator+(B);
			cout << "Result of Add:" << endl;
			A.Print_Matrix(A);
			A.Print_to_file(A);
		}

		if (OtherNumber == 3)
		{
			A.operator-(B);
			cout << "Result of Extract:" << endl;
			A.Print_Matrix(A);
			A.Print_to_file(A);
		}
	}


	if (number == 2)
	{
		unsigned int data;
		unsigned int data2;
		cout << "You choosed to upload manually!" << endl;
		cout << "Rows:" << endl;
		do
		{
			if (!(std::cin >> data))
			{
				cerr << "It was not a correct unit, try again!" << endl;
				std::cin.clear(); //clears the error flag on cin (so that future I/O operations will work correctly)
				std::cin.ignore(10000, '\n'); //Skips to the next newline.
			}
			if (data <= 0)
				cerr << "It was not a correct number, try again!" << endl;
		} while (data <= 0); 

		cout << "Columns:" << endl;
		do
		{
			if (!(std::cin >> data2))
			{
				cerr << "It was not a correct unit, try again!" << endl;
				std::cin.clear(); //clears the error flag on cin (so that future I/O operations will work correctly)
				std::cin.ignore(10000, '\n'); //Skips to the next newline.
			}
			if (data2 <= 0)
				cerr << "It was not a correct number, try again!" << endl;
		} while (data2 <= 0); 

		/*|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|*/
		Matrix A = Matrix(data, data2);
		A.Upload();
		A.Print_to_file(A);
		A.Print_Matrix(A);
		/*|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|*/

		cout << "Other Matrix:" << endl;
		cout << "Rows:" << endl;
		do
		{
			if (!(std::cin >> data))
			{
				cerr << "It was not a correct unit, try again!" << endl;
				std::cin.clear(); //clears the error flag on cin (so that future I/O operations will work correctly)
				std::cin.ignore(10000, '\n'); //Skips to the next newline.
			}
			if (data <= 0)
				cerr << "It was not a correct number, try again!" << endl;
		} while (data <= 0);

		cout << "Columns:" << endl;
		do
		{
			if (!(std::cin >> data2))
			{
				cerr << "It was not a correct unit, try again!" << endl;
				std::cin.clear(); //clears the error flag on cin (so that future I/O operations will work correctly)
				std::cin.ignore(10000, '\n'); //Skips to the next newline.
			}
			if (data2 <= 0)
				cerr << "It was not a correct number, try again!" << endl;
		} while (data2 <= 0);

		/*|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|*/
		Matrix B(data,data2);
		B.Upload();
		B.Print_to_file(B);
		B.Print_Matrix(B);
		/*|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|\|*/

		OtherNumber=(A.Operand(A, B));	

		if (OtherNumber == 1)
		{
			A.operator*(B);
			cout << "Result of Multiply:" << endl;
			A.Print_Matrix(A);
			A.Print_to_file(A);
		}

		if (OtherNumber == 2)
		{
			A.operator+(B);
			cout << "Result of Add:" << endl;
			A.Print_Matrix(A);
			A.Print_to_file(A);
		}

		if (OtherNumber == 3)
		{
			A.operator-(B);
			cout << "Result of Extract:" << endl;
			A.Print_Matrix(A);
			A.Print_to_file(A);
		}
	}



	/*GLOBAL IDENTITY MATRIX*/
	cout << "Step three:" << endl;
	cout << "Please give the parameter of the Identity Matrix here:" << endl;
	
	do
	{
		if (!(cin >> number))
		{
			cerr << "It was not a correct unit, try again!" << endl;
			cin.clear(); //clears the error flag on cin (so that future I/O operations will work correctly)
			cin.ignore(10000, '\n'); //Skips to the next newline.
		}
		cout << "It was not a correct number, try again!" << endl;
	} while (number<=0);

	
	Matrix* Identity = GlobalFunction(number);

	getchar();
	return 0;
}
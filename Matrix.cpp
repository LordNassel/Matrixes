#include "Matrix.h"
#include "vld.h"
#include "vld_def.h"
#include<iostream>
#include<fstream>

using namespace std;

/*Copy Constructor*/
Basic_Data::Basic_Data(const Basic_Data & Object)
{
	for (unsigned int k = 0; k < this->rows; ++k)
	{
		for (unsigned int l = 0; l < this->cols; ++l)
		{
			Object.tp[k][l] = this->tp[k][l];
		}
	}
}

void Basic_Data::SetRows(unsigned int RightData)
{
	this->rows = RightData;
}

inline void Basic_Data::SetCols(unsigned int RightData)
{
	this->cols = RightData;
}

void Basic_Data::Upload()
{
	double value=0; 
	int shortcut = 0;
	cout << "Upload the Matrix:" << endl;
	for (unsigned int k = 0; k < rows; ++k)
	{
		for (unsigned int l = 0; l < cols; ++l)
		{
			do
			{
				
				if (!(cin >> value))
				{
					cerr << "It was not a correct unit, try again!" << endl;
					cin.clear(); //clears the error flag on cin (so that future I/O operations will work correctly)
					cin.ignore(10000, '\n'); //Skips to the next newline.
					shortcut = 0;
				}
				else
				{
					shortcut = 1;
				}

			} while (shortcut!=1);
			this->tp[k][l] =value; 
		}
	}
}


void Basic_Data::Upload_From_File()
{
	double value;
	cout << "Uploading from file: [Source1]!" << endl;
	ifstream filename;
	filename.open("Source1.txt");
	if (filename.fail())
		cerr << "File could not be opened!" << endl;

	if (filename.is_open())
	{
		while (!filename.eof())
		{
			filename >> rows >> cols;
			this->rows = rows;
			this->cols = cols;
			for (unsigned int k = 0; k < rows; ++k)
			{
				for (unsigned int l = 0; l < cols; ++l)
				{
					filename >> value;
					this->tp[k][l] = value;
				}
			}
		}
	}

	filename.close();
	if (filename.fail()) 
	{
		cerr << "File could not be closed!" << endl;
	}
}


void Basic_Data::Upload_From_File_2()
{
	double value;
	cout << "Uploading from file: [Source2]!" << endl;
	ifstream filename;
	filename.open("Source2.txt");
	if (filename.fail())
		cerr << "File could not be opened!" << endl;

	if (filename.is_open())
	{
		while (!filename.eof())
		{
			filename >> rows >> cols;
			this->rows = rows;
			this->cols = cols;
			for (unsigned int k = 0; k < rows; ++k)
			{
				for (unsigned int l = 0; l < cols; ++l)
				{
					filename >> value;
					this->tp[k][l] = value;
				}
			}
		}
	}

	filename.close();
	if (filename.fail())
	{
		cerr << "File could not be closed!" << endl;
	}
}


void Print_BD::Print_Matrix(Print_BD& Data)
{
		cout << "Your Matrix:" << endl;
		double value;
		for (unsigned int m = 0; m < rows; ++m)
		{
			for (unsigned int n = 0; n < cols; ++n)
			{
				value = tp[m][n];
				cout << "\t" << value; //It makes things look better.
			}
			cout << endl;
		}
}


void Print_BD::Print_to_file(Print_BD& Data) 
{
	double DataIn;

	ofstream filename;
	filename.open("Result.txt");
	if (filename.fail())
		cerr << "File could not be opened!" << endl;
	
	filename << "Rows: " << Data.rows << " Cols: " << Data.cols << "\n" << endl; //First line in file.
	for (unsigned int i = 0; i < Data.rows; i++) 
	{
		for (unsigned int j = 0; j < Data.cols; j++)
		{
			DataIn = Data.tp[rows][cols];
			filename << DataIn << "\t"; //Makes staff readable!
		}
		filename << endl; //New line
	}
	filename << endl; //Creating an empty row

	filename.close(); 
	if (filename.fail()) 
	{
		cerr << "File could not be closed!" << endl;
	}
}


void Print_BD::Print_to_file_2(Print_BD& Data)
{
	double DataIn;

	ofstream filename;
	filename.open("Result2.txt");
	if (filename.fail())
		cerr << "File could not be opened!" << endl;

	filename << "Rows: " << Data.rows << " Cols: " << Data.cols << "\n" << endl; //First line in file.
	for (unsigned int i = 0; i < Data.rows; i++)
	{
		for (unsigned int j = 0; j < Data.cols; j++)
		{
			DataIn = Data.tp[rows][cols];
			filename << DataIn << "\t"; //Makes staff readable!
		}
		filename << endl; //New line
	}
	filename << endl; //Creating an empty row

	filename.close();
	if (filename.fail())
	{
		cerr << "File could not be closed!" << endl;
	}
}


int Print_BD::Operand(Print_BD& A, Print_BD& B)
{
	cout << "Step Two:" << endl;
	cout << "Choose a number (1-3), what would you like to do. If the number does not dissappear, NOPE will!" << endl;
	if (A.cols == B.rows)
	{
		cout << "[PRESS 1]-Multiply ";
	}
	if (A.cols == B.cols && A.rows == B.rows)
	{
		cout << "[PRESS 2]-Add " << endl;
		cout << "[PRESS 3]-Extract " << endl;
	}
	if ((A.cols != B.rows) || (A.cols != B.cols && A.rows != B.rows))
	{
		cout << "[NOPE]-Nothing could be done here! No operations will be saved into file!" << endl;
	}

	int number = 0;
	
	do
	{
		if (!(std::cin >> number))
		{
			cerr << "It was not a correct unit, try again!" << endl;
			std::cin.clear(); //clears the error flag on cin (so that future I/O operations will work correctly)
			std::cin.ignore(10000, '\n'); //Skips to the next newline.
		}
		if (number != 1 && number != 2 && number!=3)
			cerr << "It was not a correct number, try again!" << endl;
	} while ((number != 1 && number != 2 && number!=3)); 

	if(number == 1 || number==2 || number==3)
	{
		A.Print_to_file(A);
		B.Print_to_file(B);
	}
	return number;
}


//Operator overload

//ADD//
void Matrix::operator+(const Matrix& M)
{
	if (this->rows == M.rows && this->cols == M.cols)
	{
		cout << "A muvelet elvegezheto!" << endl;

		for (unsigned int i = 0; i < this->rows; i++)
		{
			for (unsigned int j = 0; j < this->cols; j++)
				this->tp[i][j] += M.tp[i][j];
		}
	}
	else
		cerr << "A muvelet nem vegezheto el" << endl;
}
//EXTRACT//
void Matrix::operator-(const Matrix& M)
{
	if (this->rows == M.rows && this->cols == M.cols)
	{
		cout << "+ Could be done!" << endl;
		for (unsigned int i = 0; i < this->rows; i++)
		{
			for (unsigned int j = 0; j < this->cols; j++)
				this->tp[i][j] -= M.tp[i][j];
		}
	}
	else
		cerr << "+ Could not be done!" << endl;
}
//MULTIPLY//
void Matrix::operator*(const Matrix& M)
{
	if (this->cols == M.rows)
	{
		cout << "* Could be done!" << endl;

		Matrix Other(this->rows, M.cols); //C=TEMPORARY MATRIX

		for (unsigned int i = 0; i < Other.cols; i++)
		{
			for (unsigned int j = 0; j < Other.rows; j++)
			{
				Other.tp[i][j] = 0;
			}
		}

		/*MULTIPLY*/

		for (unsigned int j = 0; j<this->rows; j++)
		{
			for (unsigned int i = 0; i<M.cols; i++) 
			{
				for (unsigned int oszlopsor = 0; oszlopsor < this->cols; oszlopsor++)
				{
					Other.tp[j][i] += this->tp[j][oszlopsor] * M.tp[oszlopsor][i];
				}
			}
		}
	}
	else
		cerr << "* Could not be done!" << endl;

}
//EQUAL//
void Matrix::operator=(const Matrix& M)
{
	if (this->rows == M.rows && this->cols == M.cols)
	{
		cout << "= Could be done!" << endl;
		for (unsigned int i = 0; i < this->rows; i++)
		{
			for (unsigned int j = 0; j < this->cols; j++)
				this->tp[i][j] = M.tp[i][j];
		}
	}
	else
		cerr << "= Could not be done!" << endl;
}

// IDENTITY MATRIX UPLOAD AND WRITE TO SCREEN // 
void Matrix::Identity_Matrix_Upload_Write(const unsigned int Unit)
{
	for (unsigned int i = 0; i < Unit; i++)
	{
		cout << endl;
		for (unsigned int j = 0; j < Unit; j++)
		{
			if (j == i)
			{
				this->tp[i][j] = 1;
			}
			else
			{
				this->tp[i][j] = 0;
			}
			cout << this->tp[i][j];
		}
	}
}
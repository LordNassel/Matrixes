#ifndef MATRIX_H
#define MATRIX_H

#include "vld_def.h"
#include <iostream>
#include <fstream>

using namespace std;

class Basic_Data
{
public: 
	unsigned int rows;
	unsigned int cols;
	double **tp;

public: 
	Basic_Data(unsigned int r=10, unsigned int c=10) :rows(r), cols(c) 

	{
			tp = new double* [rows];
			for (unsigned int i = 0; i < rows; i++)
				tp[i] = new double[cols];
	}

	//EXAMPLE

	void Feltolt()
	{
		double a, b, c, d;
		a = 1;
		b = 2;
		c = 3;
		d = 4;

		tp[0][0] = a;
		tp[0][1] = b;
		tp[1][0] = c;
		tp[1][1] = d;
	}

		//Copy Constructor//
	Basic_Data(const Basic_Data& Object);


	inline void SetRows(unsigned int RightData); 
	inline void SetCols(unsigned int RightData);
	inline unsigned int GetRows()const { return rows; }
	inline unsigned int GetColt()const { return cols; }

		//Upload Matrix //

	void Upload();
	void Upload_From_File();
	void Upload_From_File_2();

		//Destructor//

	~Basic_Data()
	{
		for (unsigned int i = 0; i < rows; ++i)
			delete[] tp[i];
		delete[] tp;
	}

};

class Print_BD : public Basic_Data
{
public:
	Print_BD(unsigned int r=10, unsigned int c=10):Basic_Data(r, c) {}
	virtual void Print_Matrix(Print_BD& Data);
	virtual void Print_to_file(Print_BD& Data);
	virtual void Print_to_file_2(Print_BD& Data);
	virtual int Operand(Print_BD& A, Print_BD& B);
};

class Matrix : public Print_BD
{
public:
	Matrix(unsigned int r=10, unsigned int c=10):Print_BD(r, c){}
	void Identity_Matrix_Upload_Write(const unsigned int Unit);
	void operator+(const Matrix& M);
	void operator-(const Matrix& M);
	void operator*(const Matrix& M);
	void operator=(const Matrix& M);
};

#endif //!MATRIX_H
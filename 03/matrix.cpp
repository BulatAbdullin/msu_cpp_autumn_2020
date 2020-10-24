#include "matrix.hpp"
#include <stdexcept>

Matrix::Matrix(int num_rows, int num_columns)
	: num_rows(num_rows)
	, num_columns(num_columns)
{
	if (num_rows <= 0 || num_columns <=0) {
		throw std::invalid_argument("Only positive numbers allowed");
	}
	data = new int[num_rows * num_columns];
}

Matrix::~Matrix()
{
	delete[] data;
}

const Matrix& Matrix::operator*=(int coefficient)
{
	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_columns; j++) {
			this->getElement(i, j) *= coefficient;
		}
	}
	return *this;
}

bool Matrix::operator==(const Matrix& another_matrix) const
{
	if (num_rows != another_matrix.num_rows
			|| num_columns != another_matrix.num_columns) {
		return false;
	}
	bool are_equal = true;
	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_columns; j++) {
			if (this->getElement(i, j) != another_matrix.getElement(i, j)) {
				are_equal = false;
				goto endfor;
			}
		}
	}
endfor:
	return are_equal;
}

bool Matrix::operator!=(const Matrix& another_matrix) const
{
	return !(*this == another_matrix);
}

Matrix Matrix::operator+(const Matrix& another_matrix) const
{
	if (num_rows != another_matrix.num_rows
			|| num_columns != another_matrix.num_columns) {
		throw std::invalid_argument("Inconsistent shapes");
	}
	Matrix sum(num_rows, num_columns);
	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_columns; j++) {
			sum.getElement(i, j) = this->getElement(i, j)
				+ another_matrix.getElement(i, j);
		}
	}
	return sum;
}

std::ostream& operator<<(std::ostream& out, const Matrix& A)
{
	for (int i = 0; i < A.num_rows; i++) {
		for (int j = 0; j < A.num_columns - 1; j++) {
			out << A.getElement(i, j) << " ";
		}
		out << A.getElement(i, A.num_columns - 1) << std::endl;
	}
	return out;
}

Matrix::Row::Row(const Matrix& A, int i)
	: num_columns(A.num_columns)
	, data(A.data + i * num_columns)
{}

int& Matrix::Row::operator[](int j) 
{
	if (j >= num_columns || j < 0) {
		throw std::out_of_range("Wrong column");
	}
	return data[j];
}

Matrix::Row Matrix::operator[](int i) 
{
	if (i >= num_rows || i < 0) {
		throw std::out_of_range("Wrong row");
	}
	return Row(*this, i);
}

#ifndef TESTS_CPP
#define TESTS_CPP

#include "matrix.hpp"
#include <sstream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

void initialize()
{
	int num_rows = 10, num_columns = 15;
	Matrix m(num_rows, num_columns);
	assert(m.getRows() == num_rows && m.getColumns() == num_columns);
	try {
		m = Matrix(-1 , num_columns);
	} catch (const std::invalid_argument&) {
	}
}

void equality()
{
	int num_rows = 10, num_columns = 15;
	Matrix m1(num_rows, num_columns);
	Matrix m2(num_rows, num_columns);
	srand(time(NULL));
	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_columns; j++) {
			m1[i][j] = m2[i][j] = rand();
		}
	}
	assert(m1 == m2);
	m1[0][0] = m2[0][0] - 1;
	Matrix m3(1, 1);
	assert(m1 != m3);
}

void multiply()
{
	int num_rows = 10, num_columns = 15, coefficient = 3;
	Matrix m1(num_rows, num_columns);
	Matrix m2(num_rows, num_columns);
	srand(time(NULL));
	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_columns; j++) {
			m1[i][j] = rand();
			m2[i][j] = m1[i][j] * coefficient;
		}
	}
	m1 *= coefficient;
	assert(m1 == m2);
}

void add()
{
	int num_rows = 10, num_columns = 15;
	Matrix m1(num_rows, num_columns);
	Matrix m2(num_rows, num_columns);
	Matrix sum(num_rows, num_columns);
	srand(time(NULL));
	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_columns; j++) {
			m1[i][j] = rand();
			m2[i][j] = rand();
			sum[i][j] = m1[i][j] + m2[i][j];
		}
	}
	assert(sum == m1 + m2);
}

void output()
{
	int num_rows = 53, num_columns = 97;
	Matrix m(num_rows, num_columns);
	srand(time(NULL));
	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_columns; j++) {
			m[i][j] = rand();
		}
	}
	std::stringstream matrix_stream;
	matrix_stream << m;
	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_columns; j++) {
			int element;
			matrix_stream >> element;
			assert(element == m[i][j]);
		}
	}
}

#endif

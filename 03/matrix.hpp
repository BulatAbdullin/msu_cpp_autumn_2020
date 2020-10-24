#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <ostream>

class Matrix
{
private:
	int num_rows, num_columns;
	int *data;

	inline int& getElement(int i, int j) const
	{
		return data[i * num_columns + j];
	}
public:
	Matrix(int num_rows, int num_columns);
	~Matrix();
	const Matrix& operator*=(int);
	bool operator==(const Matrix&) const;
	bool operator!=(const Matrix&) const;
	Matrix operator+(const Matrix&) const;
	friend std::ostream& operator<<(std::ostream&, const Matrix&);

	/* Proxy class in order to use double indexing A[i][j] */
	class Row
	{
	private:
		int num_columns;
		int *data;
	public:
		Row(const Matrix&, int i);
		int& operator[](int);
	};

	Row operator[](int);

	inline int getRows() const
	{
		return this->num_rows;
	}

	inline int getColumns() const
	{
		return this->num_columns;
	}
};

#endif

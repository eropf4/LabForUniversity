#include "MatrixXnX.h"
#include <time.h>
#include <cstdlib>
#include <climits>

MatrixXnX::MatrixXnX(const int iDim) :dimension(iDim)
{
	matrix = new int[iDim * iDim]; //I decided to use linear array because this will be easier and you avoid from
								  //creating pointers
	for (auto i = 0; i < iDim * iDim; i++)
		matrix[i] = 0;
}

MatrixXnX::~MatrixXnX()
{
	delete[] matrix;
}

int MatrixXnX::element(const int i, const int j) const
{
	return matrix[i * dimension + j];
}

void MatrixXnX::fillRandomElements(const int minVal, const int maxVal)
{
	srand(time(0));
	for (auto i = 0; i < dimension * dimension; i++)
		matrix[i] = minVal + rand() % (maxVal - minVal + 1);
}

void MatrixXnX::setElement(const int i, const int j, const int value)
{
	matrix[i * dimension + j] = value;
}

int MatrixXnX::sumPrincipalDiag() const
{
	int sum = 0;
	for (auto i = 0; i < dimension; i++)
		sum += matrix[i * dimension + i];
	return sum;
}

int MatrixXnX::sumSecondaryDiag() const
{
	int sum = 0;
	for (auto i = 0; i < dimension; i++)
		sum += matrix[i * dimension + (dimension - 1 - i)];
	return sum;
}

int MatrixXnX::productPrincipalDiag() const
{
	int product = 1;
	for (auto i = 0; i < dimension; i++)
		product *= matrix[i * dimension + i];

	return product;
}

int MatrixXnX::productSecondaryDiag() const
{
	int product = 1;
	for (auto i = 0; i < dimension; i++)
		product *= matrix[i * dimension + (dimension - 1 - i)];
	return product;
}

int MatrixXnX::sumRow(const int iRow) const
{
	int sum = 0;
	for (auto j = 0; j < dimension; j++)
		sum += matrix[iRow * dimension + j];
	return sum;
}

int MatrixXnX::minColumn(const int iCol) const
{
	int min = INT_MAX;
	for (auto i = 0; i < dimension; i++)
		if (matrix[i * dimension + iCol] < min)
			min = matrix[i * dimension + iCol];
	return min;
}

int MatrixXnX::maxColumn(const int iCol) const
{
	int max = INT_MIN;
	for (auto i = 0; i < dimension; i++)
		if (matrix[i * dimension + iCol] > max)
			max = matrix[i * dimension + iCol];
	return max;
}

int MatrixXnX::getDimension() const
{
	return dimension;
}

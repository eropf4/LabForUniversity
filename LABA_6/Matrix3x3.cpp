#include "Matrix3x3.h"
#include <time.h>
#include <cstdlib>
#include <climits>

int Matrix3x3::element(const int i, const int j) const
{
	return matrix[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value)
{
	matrix[i][j] = value;
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal)
{
	srand(time(0));
	for (auto i = 0; i < n; i++)
		for (auto j = 0; j < n; j++)
			matrix[i][j] = minVal + rand() % (maxVal - minVal + 1);
}

int Matrix3x3::sumPrincipalDiag() const
{
	int sum = 0;
	for (auto i = 0; i < n; i++)
		sum += matrix[i][i];
	return sum;
}

int Matrix3x3::sumSecondaryDiag() const
{
	int sum = 0;
	for (auto i = 0; i < n; i++)
		sum += matrix[i][2 - i];
	return sum;
}
int Matrix3x3::productPrincipalDiag() const
{
	int product = 1;
	for (auto i = 0; i < n; i++)
		product *= matrix[i][i];
	return product;
}
int Matrix3x3::productSecondaryDiag() const
{
	int product = 1;
	for (auto i = 0; i < n; i++)
		product *= matrix[i][2 - i];
	return product;
}
int Matrix3x3::sumRow(const int iRow) const
{
	int sum = 0;
	for (auto j = 0; j < n; j++)
		sum += matrix[iRow][j];
	return sum;
}
int Matrix3x3::minColumn(const int iCol) const
{
	int min = INT_MAX;
	for (auto i = 0; i < n; i++)
		if (matrix[i][iCol] < min)
			min = matrix[i][iCol];

	return min;
}
int Matrix3x3::maxColumn(const int iCol) const
{
	int max = INT_MIN;
	for (auto i = 0; i < n; i++)
		if (matrix[i][iCol] > max)
			max = matrix[i][iCol];

	return max;
}

int Matrix3x3::getDimension() const
{
	return n;
}

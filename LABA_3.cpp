// LABA_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> 
#include <string> 

using namespace std;


int findMin(int* startObject, int* endObject)
{
	int min = INT32_MAX;
	for (int i = 0; i < (endObject - startObject + 1); i++)
		if (startObject[i] < min) min = startObject[i];
	return min;
}



void findElement(int* startObject, int* endObject) 
{
	for (int i = 1; i < (endObject - startObject + 1); i++) {
		if (startObject[i] - startObject[i - 1] != 1) {
			cout << startObject[i] - 1 << endl;
			break;
		}
	}
}

int PredMin(int* startObject, int* endObject) 
{
	int min = INT32_MAX;
	int predmin = INT32_MAX;
	for (int i = 0; i < (endObject - startObject + 1); i++)
	{
		if (startObject[i] < min)
		{
			if (min < predmin) predmin = min;
			min = startObject[i];
		}
	}

	return predmin;
}

int main()
{
	int arr[] = { 8, 4, 0, 123, 1234, 672, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimal: " << findMin(arr, arr + n - 1) << endl;
	cout << "PredMinimal: " << PredMin(arr, arr + n - 1) << endl;

	int newArr[] = { 1,2,3,5,6,7,8,9 };
	int m = sizeof(newArr) / sizeof(arr[0]);
	cout << " Missing element: ";
	findElement(newArr, newArr + m - 1);

	return 0;
}

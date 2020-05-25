// LABA_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> 
#include <string> 

using namespace std;

int Max(int* startObject, int* endObject)
{
	int max = INT32_MIN;
	for (int i = 0; i < (endObject - startObject + 1); i++)
		if (startObject[i] > max) max = startObject[i];
	return max;
}

void Sort(int* st, int* end)
{

	for (int i = 0; i < (end - st + 1); i++)
	{
		for (int j = i + 1; j < (end - st + 1); j++)
		{
			if (*(st + i) > * (st + j))
			{
				int t = *(st + i);
				*(st + i) = *(st + j);
				*(st + j) = t;
			}
		}
	}
}




int main()
{
	int arr[] = { 8, 4, 0, 123, 1234, 672, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Sort(arr, arr + n - 1);
	cout << "Sort: " << endl ; 
	for (int i = 0; i < n; i++)
		cout << *(arr + i) << " ";
	cout << endl << "Array Maximum: " << endl << Max(arr, arr + n - 1) << endl;
}



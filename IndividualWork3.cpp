#include <iostream>

using namespace std;

typedef bool(*predicate)(int);

int ValidNumber();
void RandomArray(int*, int);
int** AlLocateMemory(int, int*);
void DisplayMatrix(int**, int, int*);
void DisplayArray(int*, int);
bool Predicate(int i);
void NewMatrix(int* , int, predicate);
void MergeSort(int*, int );
void MergeSort(int*, int, int);
void Merge(int*, int, int, int);

int main()
{
	int n=ValidNumber();
	int** matrix = new int*[n];
	int* dimentions = new int(n);

	RandomArray(dimentions, n);
	DisplayMatrix(matrix, n, dimentions);

	NewMatrix(dimentions, n, Predicate);
	DisplayMatrix(matrix, n, dimentions);

	system("pause");
	return 0;
}

int ValidNumber()
{
	int n;
	cin >> n;
	if(n < 0)
	{
		cout << "Invalid number ";
	}
	return n;
}

void RandomArray(int* dimentions, int n)
{
	for (int i = 0; i < n; i++)
	{
		dimentions[i] = rand() % 10;
	}
}

int** AlLocateMemory(int n, int* dimentions)
{
	int** matrix = new int*[n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[dimentions[i]];
	}

	return matrix;
}

void DisplayMatrix(int** matrix, int n, int* dimentions)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < dimentions[i]; j++)
		{
			cout.width(5);
			cout<< matrix[i][j];
		}

		cout << endl;
	}

	cout<< endl;
}

void DisplayArray(int* dimentions, int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << dimentions[j] << "  ";
	}
	cout << endl;
}

bool Predicate(int i)
{
	return i % 2 == 0;
}

void NewMatrix(int* dimentions, int n, predicate Predicate)
{
	for (int i = 0; i < n; i++)
	{
		if (Predicate(i))
		{
			MergeSort(dimentions,n);
		}
	}
}

void MergeSort(int* array, int n)
{
	MergeSort(array, 0, n - 1);
}

void MergeSort(int* array, int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int middleIndex = (startIndex + endIndex) / 2;
		MergeSort(array, startIndex, middleIndex);
		MergeSort(array, middleIndex + 1, endIndex);
		Merge(array, startIndex, middleIndex, endIndex);
	}
}

void Merge(int* dimentions, int startIndex, int middleIndex, int endIndex)
{
	const int totalElements = endIndex - startIndex + 1;

	int * tempArray = new int[totalElements];
	int leftIndex = startIndex;
	int rightIndex = middleIndex + 1;
	int mergedIndex = 0;
	while (leftIndex <= middleIndex && rightIndex <= endIndex)
	{
		if (dimentions[leftIndex] <= dimentions[rightIndex])
		{
			tempArray[mergedIndex] = dimentions[leftIndex];
			++leftIndex;
		}
		else
		{
			tempArray[mergedIndex] = dimentions[rightIndex];
			++rightIndex;
		}
		++mergedIndex;
	}

	while (leftIndex <= middleIndex)
	{
		tempArray[mergedIndex] = dimentions[leftIndex];
		++leftIndex;
		++mergedIndex;
	}

	while (rightIndex <= endIndex)
	{
		tempArray[mergedIndex] = dimentions[rightIndex];
		++rightIndex;
		++mergedIndex;
	}

	for (int i = 0; i < totalElements; ++i)
	{
		dimentions[startIndex + i] = tempArray[i];
	}
	delete[] tempArray;
}

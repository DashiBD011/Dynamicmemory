#include<iostream>
using namespace std;

void FillRand(int** arr, const int m, const int n);
void Print(int** arr, const int m, const int n);

void Allocate(int** arr, const int m, const int n);
void Clear(int** arr, const int m);

//void push_row_back(int**& arr, int& m);

void main()
{
	setlocale(LC_ALL, "");
	int m;
	int n;
	cout << "Введите кол-во строк: "; cin >> m;
	cout << "Введите кол-во столбцов: "; cin >> n;

	int** arr = new int* [m];

	Allocate(arr, m, n);
	FillRand(arr, m, n);
	Print(arr, m, n);

	cout << endl;

	//push_row_back(arr, m);
	//Print(arr, m, n);

	Clear(arr, m);
}

void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}


void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}
}

void Allocate(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)arr[i] = new int[n];
}

void Clear(int** arr, const int m)
{
	for (int i = 0; i < m; i++)	delete arr[i];
	delete[] arr;
}

//void push_row_back(int**& arr, int& m)
//{
//	int** buffer = new int* [++m]{};
//	for (int i = 0; i < m; i++)
//	{	
//		buffer[i] = arr[i];
//	}
//	delete[]arr;
//	arr = buffer;
//	
//	
//}

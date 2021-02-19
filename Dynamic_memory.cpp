#include"DynamicMemory.h"


void FillRand(int arr[], const int c)
{
	for (int i = 0; i < c; i++)
	{
		arr[i] = rand() % 100;
	}
	cout << "Массив int" << endl;
}

void FillRand(double arr[], const int c)
{
	for (int i = 0; i < c; i++)
	{
		arr[i] = double(rand() % 100) / 10;
	}
	cout << "Массив double" << endl;
}

void FillRand(float arr[], const int c)
{
	for (int i = 0; i < c; i++)
	{
		arr[i] = float(rand() % 100) / 10;
	}
	cout << "Массив float" << endl;
}

void FillRand(char arr[], const int c, int minrand, int maxrand)
{
	for (int i = 0; i < c; i++)
	{
		arr[i] = rand() % (maxrand - minrand) + minrand;
	}
	cout << "Массив char" << endl;
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
	cout << "Массив типа int" << endl;
}

void FillRand(float** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = float(rand() % 100) / 10;
		}
	}
	cout << "Массив типа float" << endl;

}

void FillRand(double** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = double(rand() % 1000) / 10;
		}
	}
	cout << "Массив типа double" << endl;
}

void FillRand(char** arr, const int m, const int n, int minrand, int maxrand)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % (maxrand - minrand) + minrand;
		}
	}
	cout << "Массив типа char" << endl;
}

template<typename T>
void Print(T arr[], const int c)
{
	for (int i = 0; i < c; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template<typename T>
void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

template<typename T>
T** Allocate(const int m, const int n)
{
	T** arr = new T * [m] {};
	for (int i = 0; i < m; i++)arr[i] = new T[n];
	return arr;
}

template<typename T>
void Clear(T** arr, const int m)
{
	for (int i = 0; i < m; i++)	delete arr[i];
	delete[] arr;
}

template<typename T>
void push_back_mutable(T*& arr, int& c, int value)
{
	T* buffer = new T[c + 1]{};
	for (int i = 0; i < c; i++)	buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[c] = value;
	c++;

}

template<typename T>
void push_front_mutable(T*& arr, int& c, int value)
{
	T* buffer = new T[c + 1]{};
	for (int i = 0; i < c; i++)	buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	c++;
}

template<typename T>
void insert(T*& arr, int& c, int index, int value)
{
	if (index >= c)return;
	T* buffer = new T[++c];
	for (int i = 0; i < c; i++)
	{
		i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
}

template<typename T>
void pop_back(T*& arr, int& c)
{
	T* buffer = new T[--c];
	for (int i = 0; i < c; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;

}

template<typename T>
void pop_front(T*& arr, int& c)
{
	T* buffer = new T[--c];
	for (int i = 0; i < c; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}

template<typename T>
void erase(T*& arr, int& c, int index)
{
	if (index >= c)return;
	T* buffer = new T[--c];
	for (int i = 0; i < c; i++)
	{
		i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}


template<typename T>
void push_row_back(T**& arr, int& m, const int n)
{

	//1)создаем буферный массив указателей
	T** buffer = new T * [m + 1];
	//2)копируем адреса строк исходного массива в буферный массив указателей
	for (int i = 0; i < m; i++)	buffer[i] = arr[i];

	delete[]arr;
	arr = buffer;
	arr[m] = new T[n]{ 0 };
	m++;
}

template<typename T>
void push_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T * [m + 1]{};
	for (int i = 0; i < m; i++)	buffer[i + 1] = arr[i];

	delete[]arr;
	arr = buffer;
	arr[0] = new T[n]{};
	m++;
}

template<typename T>
void insert_row(T**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	T** buffer = new T * [m + 1]{};

	for (int i = 0; i < index; i++)	buffer[i] = arr[i];

	for (int i = index; i < m; i++)	buffer[i + 1] = arr[i];

	delete[]arr;
	arr = buffer;
	arr[index] = new T[n]{};
	m++;
}

template<typename T>
void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T * [--m]{};
	for (int i = 0; i < m; i++)	buffer[i] = arr[i];

	delete[] arr[m];
	delete[]arr;
	arr = buffer;
}

template<typename T>
void pop_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T * [--m]{};
	for (int i = 0; i < m; i++)	buffer[i] = arr[i + 1];

	delete[] arr[0];
	delete[]arr;
	arr = buffer;
}

template<typename T>
void erase_row(T**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	T** buffer = new T * [--m]{};

	for (int i = 0; i < index; i++)	buffer[i] = arr[i];

	for (int i = index; i < m; i++)	buffer[i] = arr[i + 1];

	delete[] arr[index];
	delete[]arr;
	arr = buffer;
}

template<typename T>
void push_col_back(T** arr, const int m, int& n)
{

	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)	buffer[j] = arr[i][j];

		delete arr[i];
		arr[i] = buffer;
	}
	n++;
}

template<typename T>
void push_col_front(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{

		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)	buffer[j + 1] = arr[i][j];

		delete arr[i];
		arr[i] = buffer;
	}
	n++;

}

template<typename T>
void insert_col(T** arr, const int m, int& n, int index)
{
	if (index > n)return;
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};

		for (int j = 0; j < index; j++)	buffer[j] = arr[i][j];

		for (int j = index; j < n; j++)	buffer[j + 1] = arr[i][j];

		delete arr[i];
		arr[i] = buffer;
	}

	n++;

}

template<typename T>
void pop_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};
		for (int j = 0; j < n - 1; j++) buffer[j] = arr[i][j];

		delete arr[i];
		arr[i] = buffer;
	}
	n--;
}

template<typename T>
void pop_col_front(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};
		for (int j = 0; j < n - 1; j++)	buffer[j] = arr[i][j + 1];

		delete arr[i];
		arr[i] = buffer;
	}
	n--;
}

template<typename T>
void erase_col(T** arr, const int m, int& n, int index)
{
	if (index > n)return;
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};

		for (int j = 0; j < index; j++)	buffer[j] = arr[i][j];

		for (int j = index; j < n - 1; j++) buffer[j] = arr[i][j + 1];

		delete arr[i];
		arr[i] = buffer;
	}
	n--;
}


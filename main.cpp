#include<iostream>
using std::cout;
using std::cin;
using std::endl;


template<typename T> void FillRand(T** arr, const int m, const int n);
template<typename T> void Print(T** arr, const int m, const int n);

template<typename T> T** Allocate(const T m, const T n);
template<typename T> void Clear(T** arr, const int m);

template<typename T> void push_row_back(T**& arr, int& m, const int n);
template<typename T> void push_row_front(T**& arr, int& m, const int n);
template<typename T> void insert_row(T**& arr, int& m, const int n, int index);

template<typename T> void pop_row_back(T**& arr, int& m, const int n);
template<typename T> void pop_row_front(T**& arr, int& m, const int n);
template<typename T> void erase_row(T**& arr, int& m, const int n, int index);

template<typename T> void push_col_back(T** arr, const int m, int& n);
template<typename T> void push_col_front(T** arr, const int m, int& n);
template<typename T> void insert_col(T** arr,const int m, int& n, int index);
 
template<typename T> void pop_col_back(T** arr, const int m, int& n);
template<typename T> void pop_col_front(T** arr, const int m, int& n);
template<typename T> void erase_col(T** arr, const int m, int& n, int index);



//#define PUSH_ROW_BACK
//#define PUSH_ROW_FRONT
//#define INSERT_ROW
//#define POP_ROW_BACK
//#define POP_ROW_FRONT
//#define ERASE_ROW
//#define PUSH_COL_BACK
//#define PUSH_COL_FRONT
//#define INSERT_COL
#define POP_COL_BACK
#define POP_COL_FRONT
#define ERASE_COL

void main()
{
	setlocale(LC_ALL, "");
	int m;
	int index;
	int n;
	cout << "Введите кол-во строк: "; cin >> m;
	cout << "Введите кол-во столбцов: "; cin >> n;


	int** arr = Allocate(m, n);

	FillRand(arr, m, n);
	Print(arr, m, n);

	

#ifdef PUSH_ROW_BACK
	cout << "Массив с добавленой строкой в коцне: " << endl;
	push_row_back(arr, m, n);
	Print(arr, m, n);
	
#endif // PUSH_ROW_BACK
	

#ifdef PUSH_ROW_FRONT
	cout << "Массив с добавленой строкой в начале: " << endl;
	push_row_front(arr, m, n);
	Print(arr, m, n);
#endif // PUSH_ROW_FRONT


#ifdef INSERT_ROW

	cout << "Введите индекс добавляемой строки: "; cin >> index;
	insert_row(arr, m, n, index);
	Print(arr, m, n);

#endif // INSERT_ROW


#ifdef POP_ROW_BACK
	cout << "Массив с удаленной строкой в конце: " << endl;
	pop_row_back(arr, m, n);
	Print(arr, m, n);
#endif // POP_ROW_BACK


#ifdef POP_ROW_FRONT
	cout << "Массив с удаленной строкой в начале: " << endl;
	pop_row_front(arr, m, n);
	Print(arr, m, n);
#endif // POP_ROW_FRONT


#ifdef ERASE_ROW
	cout << "Введите индекс удаляемой строки: "; cin >> index;
	erase_row(arr, m, n, index);
	Print(arr, m, n);
#endif // ERASE_ROW


#ifdef PUSH_COL_BACK
	cout << "Массив с добавленым столбиком  в конце: " << endl;
	push_col_back(arr, m, n);
	Print(arr, m, n);
#endif // PUSH_COL_BACK


#ifdef PUSH_COL_FRONT
	cout << "Массив с добавленым столбиком  в начале: " << endl;
	push_col_front(arr, m, n);
	Print(arr, m, n);
#endif // PUSH_COL_FRONT


#ifdef INSERT_COL
	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	insert_col(arr, m, n, index);
	Print(arr, m, n);
#endif // INSERT_COL


#ifdef POP_COL_BACK
	cout << "Массив с удаленным столбцом в конце: " << endl;
	pop_col_back(arr, m, n);
	Print(arr, m, n);
#endif // POP_COL_BACK


#ifdef POP_COL_FRONT
	cout << "Массив с удаленным столбцом в начале: " << endl;
	pop_col_front(arr, m, n);
	Print(arr, m, n);
#endif // POP_COL_FRONT


#ifdef ERASE_COL
	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	erase_col(arr, m, n, index);
	Print(arr, m, n);
#endif // ERASE_COL


	Clear(arr, m);
}

template<typename T>
void FillRand(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
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
T** Allocate(const T m, const T n)
{
	T** arr = new T* [m] {};
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
void push_row_back(T**& arr, int& m, const int n)
{
	
	//1)создаем буферный массив указателей
	T** buffer = new T*[m + 1];
	//2)копируем адреса строк исходного массива в буферный массив указателей
	for (int i = 0; i < m; i++)	buffer[i] = arr[i];
	
	delete[]arr;
	arr = buffer;
	arr[m] = new T[n] {};
	m++;
}

template<typename T>
void push_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T* [m+1]{};
	for (int i = 0; i < m; i++)	buffer[i+1] = arr[i];
	
	delete[]arr;
	arr = buffer;
	arr[0] = new T [n] {};
	m++;
}

template<typename T>
void insert_row(T**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	T** buffer = new T* [m+1]{};

	for (int i = 0; i < index; i++)	buffer[i] = arr[i];
	
	for (int i = index; i < m; i++)	buffer[i + 1] = arr[i];
	
	delete[]arr;
	arr = buffer;
	arr[index] = new T [n] {};
	m++;
}

template<typename T>
void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T* [--m]{};
	for (int i = 0; i < m; i++)	buffer[i] = arr[i];
	
	delete[] arr[m];
	delete[]arr;
	arr = buffer;
}

template<typename T>
void pop_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T* [--m]{};
	for (int i = 0; i < m; i++)	buffer[i] = arr[i+1];

	delete[] arr[0];
	delete[]arr;
	arr = buffer;
}

template<typename T>
void erase_row(T**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	T** buffer = new T* [--m]{};
	
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

		T* buffer = new T[n+1]{};
		for (int j = 0; j < n; j++)	buffer[j+1] = arr[i][j];
		
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
		T* buffer = new T[n-1]{};
		for (int j = 0; j < n-1; j++) buffer[j] = arr[i][j];
		
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
		for (int j = 0; j < n - 1; j++)	buffer[j] = arr[i][j+1];
		
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
		
		for (int j = index; j < n-1; j++) buffer[j] = arr[i][j + 1];
		
		delete arr[i];
		arr[i] = buffer;
	}
	n--;
}


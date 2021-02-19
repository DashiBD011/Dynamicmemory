#include"DynamicMemory.h"


void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY1

	int c;
	int value;
	int index;
	cout << "Введите размер массива:"; cin >> c;
	DataType* arr = new DataType[c];

	FillRand(arr, c);
	Print(arr, c);


	cout << "Введите добавляемое значение: "; cin >> value;
	push_back_mutable(arr, c, value);
	Print(arr, c);


	cout << "Введите добавляемое значение: "; cin >> value;
	push_front_mutable(arr, c, value);
	Print(arr, c);


	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс: "; cin >> index;
	insert(arr, c, index, value);
	Print(arr, c);


	cout << "Удаление значения по индексу" << endl;
	cout << "Введите индекс: "; cin >> index;
	erase(arr, c, index);
	Print(arr, c);


	cout << "Удаление последнего значения: " << endl;
	pop_back(arr, c);
	Print(arr, c);


	cout << "Удаление первого значения: " << endl;
	pop_front(arr, c);
	Print(arr, c);
  
	delete[] arr;
#endif // DYNAMIC_MEMORY1

#ifdef DYNAMIC_MEMORY2

	int m;
	int index;
	int n;
	cout << "Введите кол-во строк: "; cin >> m;
	cout << "Введите кол-во столбцов: "; cin >> n;
	cout << endl;


	DataType** arr = Allocate<DataType>(m, n);

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
#endif // DYNAMIC_MEMORY2



}
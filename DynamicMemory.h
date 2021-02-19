#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void FillRand(int arr[], const int c);
void FillRand(double arr[], const int c);
void FillRand(float arr[], const int c);
void FillRand(char arr[], const int c, int minrand = 48, int maxrand = 57);

void FillRand(int** arr, const int m, const int n);
void FillRand(float** arr, const int m, const int n);
void FillRand(double** arr, const int m, const int n);
void FillRand(char** arr, const int m, const int n, int minrand = 65, int maxrand = 90);

template<typename T> void Print(T arr[], const int c);
template<typename T> void Print(T** arr, const int m, const int n);

template<typename T> T** Allocate(const int m, const int n);
template<typename T> void Clear(T** arr, const int m);

template<typename T> void push_back_mutable(T*& arr, int& c, int value);
template<typename T> void push_front_mutable(T*& arr, int& c, int value);
template<typename T> void insert(T*& arr, int& c, int index, int value);

template<typename T> void pop_back(T*& arr, int& c);
template<typename T> void pop_front(T*& arr, int& c);
template<typename T> void erase(T*& arr, int& c, int index);

template<typename T> void push_row_back(T**& arr, int& m, const int n);
template<typename T> void push_row_front(T**& arr, int& m, const int n);
template<typename T> void insert_row(T**& arr, int& m, const int n, int index);

template<typename T> void pop_row_back(T**& arr, int& m, const int n);
template<typename T> void pop_row_front(T**& arr, int& m, const int n);
template<typename T> void erase_row(T**& arr, int& m, const int n, int index);

template<typename T> void push_col_back(T** arr, const int m, int& n);
template<typename T> void push_col_front(T** arr, const int m, int& n);
template<typename T> void insert_col(T** arr, const int m, int& n, int index);

template<typename T> void pop_col_back(T** arr, const int m, int& n);
template<typename T> void pop_col_front(T** arr, const int m, int& n);
template<typename T> void erase_col(T** arr, const int m, int& n, int index);


//#define DYNAMIC_MEMORY1
#define DYNAMIC_MEMORY2

//#define PUSH_ROW_BACK
//#define PUSH_ROW_FRONT
//#define INSERT_ROW
//#define POP_ROW_BACK
//#define POP_ROW_FRONT
//#define ERASE_ROW
//#define PUSH_COL_BACK
//#define PUSH_COL_FRONT
//#define INSERT_COL
//#define POP_COL_BACK
//#define POP_COL_FRONT
//#define ERASE_COL

typedef float DataType;

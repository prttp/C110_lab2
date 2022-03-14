
//Прототипы функций, используемых в данном задании :
//void VarArgs(int arg1, ...);
#include<string.h>
#include <iostream>
#include <cstdarg>
#include <cmath>
const int N = 4;
const int M = 5;

void PrintArray(int Array[N][M]);
void PrintDynArray(int** dynar, int N, int M);
int DayOfYear(int day, int month, int year, int nDayTab[2][12]);
int DayOfMonth(int DoY, int year, int& month, int nDayTab[2][12]);
void VarArgs(int arg1, ...);
void VarArgsM(int arg1, ...);
double Sum(double x1, double x2);
double Sub(double x1, double x2);
double Mul(double x1, double x2);
double Div(double x1, double x2);

void Sort(char* pcFirst, int nNumber, int size,
void(*Swap)(void*, void*), int(*Compare)(void*, void*));
void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);
void SwapDouble(void* p1, void* p2);
int CmpDouble(void* p1, void* p2);
void SwapStr(void* p1, void* p2);
int CmpStr(void* p1, void* p2);
const char* GetString1();
const char* GetString2();
const char* GetString3();
const char* GetString4();
const char* GetString5();

void AddNew(int** arr, int* n);
void PDArray(int* dynar, int N);

int F81(int N);
int F82(int N);
void F83(const char* str);
void F84(const char* str, int n);


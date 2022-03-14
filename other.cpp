#include "other.h"

void PrintArray(int Array[N][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << Array[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "____________________________________" << std::endl;
}
void PrintDynArray(int** dynar, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << dynar[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "____________________________________" << std::endl;
}

int DayOfYear(int day, int month, int year, int nDayTab[2][12]) {
	bool isLeapYear = (year % 4 == 0) && (year % 400 == 0 || year % 100 != 0); //определение високосности
	int dMonth = 0;
	for (int i = 0; i < (month - 1); i++) {
		dMonth += nDayTab[isLeapYear][i];
	}
	int answer = day + dMonth;
	return answer;
}
int DayOfMonth(int DoY, int year, int& month, int nDayTab[2][12]) {
	bool isLeapYear = (year % 4 == 0) && (year % 400 == 0 || year % 100 != 0); //определение високосности
	int answer = DoY;
	for (int i = 0; i < 11; i++) {
		if (answer < nDayTab[isLeapYear][i]) { 
			month = i+1;
			break; }
		answer -= nDayTab[isLeapYear][i];
		}
	return answer;
}
///////////////////////////////////////////////////

//Подсказка-заготовка для задания 5а
//Без использования макросов

void VarArgs(int arg1,...)
{
	int number = 0;	//счетчик элементов
	int* p = &arg1;//Объявите указатель на int и инициализируйте его адресом
	//первого аргумента
	
	while (*p) {//Пока не достигнут конец списка:
		std::cout << *p << ' ';// а) печать значения очередного аргумента
		p++;// б) модификация указателя (он должен указывать на
	//следующий аргумент списка)
		number++;// в) увеличить счетчик элементов
	};
	


	//Печать числа элементов
	std::cout << "//" << number << std::endl;
}

void VarArgsM(int arg1, ...)
{
	int number = 0;	//счетчик элементов
	int i = arg1;
	va_list p;
	va_start(p, arg1);
	while (i) {//Пока не достигнут конец списка:
		std::cout << i << ' ';// а) печать значения очередного аргумента
		i = va_arg(p, int);// б) модификация указателя (он должен указывать на
	//следующий аргумент списка)
		number++;// в) увеличить счетчик элементов
	};
	va_end(p);


	//Печать числа элементов
	std::cout << "//" << number << std::endl;
}

double Sum(double x1, double x2) {
	double res = x1 + x2;
	return res;
}
double Sub(double x1, double x2) {
	double res = x1 - x2;
	return res;
}
double Mul(double x1, double x2) {
	double res = x1 * x2;
	return res;
}
double Div(double x1, double x2) {
	double res = x1 / x2;
	return res;
}

//#include "other.h"

///////////////////////////////////////////////////



void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(void*, void*), int(*Compare)(void*, void*))
{
	int i;
	for (i = 1; i < nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1)*size;
			if ((*Compare)(pPrevious, pCurrent) > 0)//требуется
												//переставить
				(*Swap)(pPrevious, pCurrent);
		}
}
//-----------------------------------------------------------------------
void SwapInt(void* p1, void* p2)
{
	int* p1tmp =static_cast<int*>(p1);
	int* p2tmp = static_cast<int*>(p2);
	int p3 = *p1tmp;
	*p1tmp = *p2tmp;
	*p2tmp = p3;
}
//-----------------------------------------------------------------------
int CmpInt(void* p1, void* p2)
{
	int nResult;
	int* p1tmp = static_cast<int*>(p1);
	int* p2tmp = static_cast<int*>(p2);
	nResult = *p1tmp - *p2tmp;
	return nResult;
}
//-----------------------------------------------------------------------
void SwapDouble(void* p1, void* p2)
{
	double* p1tmp = static_cast<double*>(p1);
	double* p2tmp = static_cast<double*>(p2);
	double p3 = *p1tmp;
	*p1tmp = *p2tmp;
	*p2tmp = p3;
}
//-----------------------------------------------------------------------
int CmpDouble(void* p1, void* p2)
{
	double nResult;
	double* p1tmp = static_cast<double*>(p1);
	double* p2tmp = static_cast<double*>(p2);
	nResult = *p1tmp - *p2tmp;
	int res;
	if (nResult == 0) { res = 0; }
	else if (nResult < 0) { res = -1; }
	else { res = 1; };
	return res;
}
//-----------------------------------------------------------------------
void SwapStr(void* p1, void* p2)
{
	char** p1tmp = static_cast<char**>(p1);
	char** p2tmp = static_cast<char**>(p2);
	char* p3 = *p1tmp;
	*p1tmp = *p2tmp;
	*p2tmp = p3;
	
}
//-----------------------------------------------------------------------
int CmpStr(void* p1, void* p2)
{
	int nResult;
	const char** p1tmp = static_cast<const char**>(p1);
	const char** p2tmp = static_cast<const char**>(p2);
	nResult = strcmp(*p1tmp, *p2tmp);
	return nResult;
}
///-----------------------------------------------------------------------
const char* GetString1()
{
	return "Hello";
}
//-----------------------------------------------------------------------
const char* GetString2()
{
	const char* str = "Book"; // возвращ знач - конст чар
	return str;
}
///-----------------------------------------------------------------------
const char* GetString3()
{
	static char str[] = "Little"; //static, мб есть другой способ
	return str;
}
//-----------------------------------------------------------------------
const char* GetString4()
{
	static char str[] = "world";
	return str;
}
//-----------------------------------------------------------------------
const char* GetString5()
{
	const char* str = new char[strlen("time")+1];
	str = "time"; //нужно присвоить значение
	return str;
}
void AddNew(int** arr, int* n) {
	int Input=0;
	std::cout << "Enter the new element:" << std::endl;
	std::cin >> Input;
	bool flag = 0; //флаг для определения наличия элемента в массиве
	for (int i = 0; i < *n; i++) {
		if ((*arr)[i] == Input) { std::cout << "This element exists already!" << std::endl; 
								flag = 1;
								break; };
	}
	if (flag == 0) {
		int* tmp = new int[*n + 1];      //расширение динамического массива
		memcpy(tmp, *arr, ((*n) * sizeof(int)));
		delete[] *arr;
		*arr = tmp;
		(*arr)[*n] = Input;
		*n=(*n)+1;
		
	}
}

void PDArray(int* dynar, int N) {
	
		for (int j = 0; j < N; j++) {
			std::cout << dynar[j] << ' ';
		}
		std::cout << std::endl;
	
}
int F81(int N){
	if (N <= 1) { return 1; }
	else { return N + F81(N - 1); }
}
int F82(int N) {
	if (N < 1) { return 0; }
	else {	return 1 + F82(N/10); }
}
void F83(const char* str) {
	if (*str) { F83(str + 1); }
	else return;
	std::cout << *str;
	}
void F84(const char* str, int n) {
	
	if (*str) { F84((str + 1), (n-2)); }
	else return;
	std::cout << *(str+n);
	
}

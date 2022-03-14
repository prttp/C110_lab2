
/*************************************************************
	������������ ������� �2 ���� �110. �������.
	��������� �� �������

*************************************************************/

#include <tchar.h>
//#include <cstdio>
//#include <cstdarg>
#include "other.h"


#define	  stop __asm nop
				
int _tmain()
{

	//������� 1. 
	//��������� �� ������� � �������� ����������.
	//�������� ��� �������� ������� ������ ���������
	//1. �� ���������� ��������� �������
	//int ar[N][M] = {������ ���������������};//��������� - ��� � ��� ������ ���� ������ N � M
	//����� ������� PrintArray   ����� ��������� ���:
	{
		
		int ar[N][M] = { {1, 2, 3, 4, 5},
						 {5, 4, 3, 2, 1},
						 {1, 2, 3, 4, 5},
						 {5, 4, 3 ,2, 1} };
		int ar2[][M] = { {1, 2, 3, 4, 5},
						 {5, 4, 3, 2, 1},
						 {1, 2, 3, 4, 5},
						 {5, 4, 3 ,2, 1},
						 {1, 2, 3, 4, 5},
						 {5, 4, 3, 2, 1} };

		//	PrintArray(ar, ... ����� ����, ����������� �������� ��� �����-������ ������);  //�����! ������ ��������- ��� ���������� (!) �������
		PrintArray(ar);

		//2. � ������������ ��������� ������� (��� ����������� �����������)
		int dN = 4;
		int dM = 5;
		int** dynar = new int* [dN];
		for (int i=0; i < dN; i++) {  // ���������� �������
			dynar[i] = new int[dM];
			for (int j=0; j < dM; j++) {
				dynar[i][j] = j;
			}
			stop
		}
		PrintDynArray(dynar, dN, dM);
		for (int i = 0; i < dN; i++) { // ������� ������
			delete[] dynar[i];
		}
		delete[] dynar;
		dynar = 0;
	}
	
/////////////////////////////////////////////////////////////////////////////
	//������� 2.
	//�������� ��������� �� ���������� ������ � �������� ��������� �������.
			//�������� ��� ����������������� ���� ����� �������:
			//1.  ... DayOfYear(...)
			//- ����������� ���� ������ (�����,����� � ��� �������� � �������� ����������)
			//� ���������� ���� ����(������������ ��������)
			//2. ... DayOfMonth(...) - ������� ����������� ���������� ���� ���� � ���� ������
			// (��������� ��� � ���������� ���� ���� � �������� ���������� � ������ ������������
			// ���� ������ � ����� ������ � �����-�� ������� �������� ��� �������� ���������� ���������)

			//��������� ����������������� ����� ������� � ������� ���������� ���������:


			//� �������� ���������� ��� �������� ��������� "���������� - ������������" ���.
			//��� �������� "������������" ���� ����� ����� ������� ������� (isLeepYear)
			//��� ����� ������������ � ������ ������� � �������� ������ �� ���������� ����������
			//������ ������������ ���� ����������� ������� nDayTab
	{
		int nDayTab[2][12] = {
			{31,28,31,30,31,30,31,31,30,31,30,31}, //������������ ���
			{31,29,31,30,31,30,31,31,30,31,30,31} };	//���������� ���

		//����� ������� DayOfYear   ����� ��������� ���:


		int day = 25, month = 5, year = 1993;
		int numDay = DayOfYear(day, month, year, nDayTab);  //�����! ��������� ��������- ��� ���������� (!) �������

		//�������� ���������� �������� �������� DayOfMonth        //�����! ��������� ��������- ��� ���������� (!) �������
		day = DayOfMonth(numDay, year, month, nDayTab);

		stop
			/////////////////////////////////////////////////////////////////////////////
				//������� 3.
				//������� 3�. ������� � ���������� ������ ����������.
				//�������� ������� (���� ��������� VarArgs, �� ������������
				// �������), ������� ��������� ���������� ����� ����������
				// ���� int � ������� �� ������ ����� �������� ���������� �
				// �� ��������.
				// ��������� ����� ������ �������� ������� ��������.

			int nN1 = 5, nN2 = 11, nN3 = 4, nN4 = 7, nN5 = -1;
		VarArgs(nN1, 0);
		VarArgs(nN1, nN2, 0);
		VarArgs(nN1, nN2, nN3, nN4, nN5, 0);
		stop


			//������� 3�. ������������� ������� 3� � ������� ��������
			// va_start, va_arg, va_end
			VarArgsM(nN1, 0);
		VarArgsM(nN1, nN2, 0);
		VarArgsM(nN1, nN2, nN3, nN4, nN5, 0);

	}
///////////////////////////////////////////////////////////////////
	//���� ��������� �� �������

	//������� 4. ��������� �� �������. "�����������".
	//�������� �������:
	//1)Sum - ��������� ��� �������� double � ���������� �����
	//���� ��������
	//2)Sub- ��������� ��� �������� double � ���������� ��������
	//���� ��������
	//3)Mul - *
	//4)Div - /
	//5)� ��� ���������� � ������� ������ ������������ ������� ����������� ����������
	//		- pow(). ��������� 1: �������� ������� ��������� � <cmath>.
	//		��������� 2: ����������� ���������� ������������� ��������� �������������
	//		��������� ���� �������, � ��� ����������� ������������ ��������� �� 
	//		double pow(double, double);

	//������������ ������������	��������� �����������:
	//���� ������������ ����� ������������ �������� ������ ������������,
	//�� ����� ������� ��� �������� � ���� ��������
	//� �� �������� ���������. ��������� ��������� ����������� ������
	//��������������� ����� ������� �� ���������.
	//������������� ����������� ����� ������������������ ����� ��������
	{
		double x1 = 0;
		double x2 = 0;
		char x3 = 0;
		std::cout << "Enter the first arguement:" << std::endl;
		std::cin >> x1;
		std::cout << "Enter the second arguement:" << std::endl;
		std::cin >> x2;
		std::cout << "Enter the operation sign (+, -, *, / or ^):" << std::endl;
		std::cin >> x3;
		if (x3 == '+' || x3 == '-' || x3 == '*' || x3 == '/' || x3 == '^') {
			double (*pf)(double, double) = 0;
			if (x3 == '+') { pf = Sum; };
			if (x3 == '-') { pf = Sub; };
			if (x3 == '*') { pf = Mul; };
			if (x3 == '/') { pf = Div; };
			if (x3 == '^') { pf = pow; };
			std::cout << pf(x1, x2) << std::endl;
		}
		else { std::cout << "ERROR! The operation sign is incorrect!" << std::endl; }
	}

	stop
		///////////////////////////////////////////////////////////////////
			//������� 5. ��������� �� ������� � �������� ���������.
			//���� ��������� ������� ���������� ����� �������� - Sort.
			//������� ��������� ��������� ���������:
			//1) ��������� �� ������ ����������� �������
			//2) ���������� ����������� ���������
			//3) ������ �������� � ������
			//4) ��������� �� ������� ������������ ���������
			//5) ��������� �� ������� ��������� ���������

			//5a. �������� ������� ������������ ���� ����� �������� -
			// SwapInt, ������� ��������� ��� void ��������� � 
			//������ �������� �������

			//�������� ������� ��������� ���� ����� �������� -
			// CmpInt, ������� ��������� ��� void ��������� �
			//���������� int ��������� ���������: 
			//<0 - ������ ������� ������, ��� ������
			//=0 - �����
			//>0 - ������ ������� ������, ��� ������
	{
		int nAr[5] = {5, 3, 2, 4, 1};	//������ ��� ����������

		//������ ��������� �������
		for (int i = 0; i < 5; i++) {
		std::cout << nAr[i] << ' ';
		};
		std::cout << std::endl;
		//����� ����������
		int nTotal = sizeof(nAr) / sizeof(nAr[0]);			//���������� ��������� � �������
		Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);

		//������ ����������� ����������
		for (int i = 0; i < 5; i++) {
			std::cout << nAr[i] << ' ';
		}
		std::cout << std::endl;
		stop
	}
	
	//������� 5�. �� �������� � 5� �������� ���������������
	//������� - SwapDouble � CmpDouble � �������� ������� Sort
	//��� ���������� ������� ������������ ��������.
	{
		double nAr[5] = { 5.2, 3.34, 2.1, 4.15, 1.67 };	//������ ��� ����������

		//������ ��������� �������
		for (int i = 0; i < 5; i++) {
			std::cout << nAr[i] << ' ';
		};
		std::cout << std::endl;
		//����� ����������
		int nTotal = sizeof(nAr) / sizeof(nAr[0]);			//���������� ��������� � �������
		Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(double), SwapDouble, CmpDouble);

		//������ ����������� ����������
		for (int i = 0; i < 5; i++) {
			std::cout << nAr[i] << ' ';
		}
		std::cout << std::endl;
		stop
	}
	
	//������� 5�*. �� �������� � 5� �������� ���������������
	//������� - SwapStr � CmpStr � �������� ������� Sort
	//��� ���������� ������� ���������� �� ������.
		{
			const char* arStr[] = { "QQQ", "SDF", "ABC","Abba", "ENFR","En" };
			for (int i = 0; i < (sizeof(arStr)/sizeof(char*)); i++) {
				std::cout << arStr[i] << ' ';
			};
			std::cout << std::endl;
			int nTotal = sizeof(arStr) / sizeof(char*);
			//���������:
			//� ������� ������� ����� ������ �����, ���� �������� ����� �������, 
			
			stop
			
			Sort(reinterpret_cast<char*>(arStr), nTotal, sizeof(char*), SwapStr, CmpStr);
			for (int i = 0; i < (sizeof(arStr) / sizeof(char*)); i++) {
				std::cout << arStr[i] << ' ';
			};
			std::cout << std::endl;
			stop
		}
///////////////////////////////////////////////////////////////////
		{
			//������� 6. ������� ���������� �� �������.
			//�������� ��������� ������� ����
			//const char* GetString1();   
			//const char* GetString2();
			//const char* GetString3();
			//const char* GetString4();
			//const char* GetString5();

			//		...., ������ �� ������� ���������� ��������� �� ���� ������
			//(��������� - ����� ����� �� ������ ����� ���������� �� �������) �� ����������� �������� �������������, ��������� �� ��������� �������, ������� ������ 

			// ��� ������������ ��� ���� �������. 
			//���������:
			//1) ��� �� ��� ���������, ���� ���, �� ��� ��������� ��������������
			//2) ����� ���� ��������� �����-�� �������������� ��������

			//�������� � ������������������ ������ ���������� �� �������
			//GetString1,GetString2...
			const char* (*fArr[5])() = { GetString1, GetString2, GetString3, GetString4, GetString5 };
			//������� ����� �������, ������� �� ������ �������:
			int n = 2;




			//�������� �������
			const char* res = fArr[n]();


			//������������ ���������
			std::cout << res << std::endl;
			//��� �������� ��� �� ����������?
			stop
		}
////////////////////////////////////////////////////////////////////////////
	//������� 7*.
	//�������� ���������� ������ (����������� ����������� � ��������
	//���������� ���������), ��������� ��� ����������.
	//�������� �������, ������� ��������� � ������ ����� �������� ������ (!) ��� �������,
	//��� ������ �������� � ������� ��� ���. 
	//���������: ��� ���� ������  ������� ������ �����������!
	//��� �������� �������� �������, ������� ������� �������� ���� ��������� �� �����
		{
			int n = 5;
			int* Arr = new int[n];
			for (int i = 0; i < n; i++) {
				Arr[i] = i + n;
			}
			stop
			int M = 0;
			std::cout<< "How many elements are you planning to add?" << std::endl;
			std::cin >> M;
			for (int i = 0; i < M; i++) {
				
				AddNew(&Arr, &n);
			}
			PDArray(Arr, n);
		}

///////////////////////////////////////////////////////////////////////////
		{
			//������� 8.  
			//����������� �������.
			//8.1.�������� ����������� ������� ���������� ����� ������ N ����������� �����. 
			int sum = F81(10);
			//8.2.�������� ����������� ������� ���������� ���������� ���� 10-����� ������������ �����
			int num = F82(3567);
			//8.3.�������� ����������� ������� ��� ������ �� ����� ������ � �������� �������. 
			F83("time");
			std::cout << std::endl;
			//8.4.�������� ����������� ������� ��� ������ �� ����� ������ � ������ (!) �������.
			F84("unbelievable", (strlen("unbelievable")-1));
			


			stop
		}
	return 0;
}//main


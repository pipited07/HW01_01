// HW01_01.cpp : 定義主控台應用程式的進入點。
//作者:國立成功大學機械所 陳紀融 N16054598

#include "stdafx.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template <class T> T FindMaximum(T* TArray,const int& size);
template <> char* FindMaximum<char*>(char* CharArray[], const int& size);

int main()
{
	srand((unsigned)time(NULL));       //宣告各陣列
	short * ShortArray = new short[6];
	double *DoubleArray = new double[9];
	char* CharArray[8] = { 
	"abc",
	"defg",
	"hijklm",
	"nop",
	"qrstuvw",
	"x",
	"yz",
	"abcde" };



	//印出所有陣列內容及測試
	cout << "short陣列內容:";
	for (int i=0;i<6;i++){
		*(ShortArray + i) = rand()%100000;
		cout  << *(ShortArray + i)<< setw(6);
	}
	cout << "\n最大值為:" << FindMaximum(ShortArray,6);

	cout << "\n\ndouble陣列內容:";
	for (int i = 0; i<9; i++) {
		*(DoubleArray + i) = rand()/100.0;
		cout  << *(DoubleArray + i)<< setw(8) ;
	}
	cout << "\n最大值為:" << FindMaximum(DoubleArray, 9);
	

	cout << "\n\nchar陣列內容:";
	for (int i = 0; i<8; i++) {
		cout  << *(CharArray + i)<< setw(10);
	}
	cout << "\n陣列最大值為:" << FindMaximum(CharArray, 8)<<endl;


	delete[] ShortArray;
	delete[] DoubleArray;
	system("pause");
    return 0;
}
//找最大值樣板
template <class T> T FindMaximum(T* Tarray, const int& size)
{
	T max = 0;
	for (int i = 0;i<size;i++) 
		if (max < Tarray[i])
			max = Tarray[i];

	return max;
}
//char* 樣板特殊化
template <> char* FindMaximum<char*>(char* CharArray[], const int& size){

	char* max = "";
	unsigned int length=0;
	string temp;

	for (int i = 0; i < size; i++) {
		temp.assign(CharArray[i]);
		if (length < temp.length()) {
			length = temp.length();
			max = CharArray[i];
		}
	}
	
	return max;
}
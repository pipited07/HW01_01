// HW01_02.cpp : 定義主控台應用程式的進入點。
//作者:國立成功大學機械所 陳紀融 N16054598

#include "stdafx.h"
#include "HW01_02.h"
#include <iostream>
#include <fstream>


using namespace std;
using namespace MyGeometry;
int main()
{	
	unsigned int nPoint=0;
	const char* filename = "Point.txt";
	Report(filename, nPoint);         //程式碼實作於此函數
	system("pause");
    return 0;
}


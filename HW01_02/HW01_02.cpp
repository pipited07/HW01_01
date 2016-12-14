#include "stdafx.h"
#include "HW01_02.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
using namespace MyGeometry;

double Point::Length() {

	return sqrt(pow(x,2)+pow(y,2));
}

string Point::CoutPoint() {

	return "("+to_string(x)+","+ to_string(y) +")";
}
Point*  MyGeometry::LoadPoint(const char* filename, unsigned int& nPoint) {

	fstream fin;
	string temp;
	fin.open(filename, ios::in);
	int count = 0;
	while (getline(fin, temp, '\n')) //計算行數
		count++;
	fin.close();
	nPoint = count;


	Point* PointArray = new Point[count];  //new出點空間


	fin.open(filename, ios::in);
	for (int i = 0; getline(fin, temp, '\n'); i++){//字串處理將點取出存進point
		PointArray[i].x = stof(temp.substr(0, temp.find(' ')));
		PointArray[i].y = stof(temp.substr(temp.find(' '), temp.find('\n')));
	}
	fin.close();

	return PointArray;
}

Point* MyGeometry::MinVerticalDistance(Point* PointArray, unsigned int& nPoint) {//找出離x軸最近的點的索引值，並傳回指標
	int MinIndex = 0;
	double number = 100;
	for (unsigned int i = 0;i<nPoint;i++) {
		if (abs((PointArray + i)->y) < number) {
			number = abs((PointArray + i)->y);
			MinIndex = i;
		}
	}
	return &PointArray[MinIndex];
}
Point * MyGeometry::SortbyLength(Point * PointArray, unsigned int & nPoint) //由小到大排序
{
	Point temp;
	for (unsigned int i = 0; i < nPoint; i++) {
		for (unsigned int j = 1; j < nPoint - i; j++) {
			if ((PointArray + j)->Length() < (PointArray + j - 1)->Length()) {
				temp.x = (PointArray + j - 1)->x;
				temp.y = (PointArray + j - 1)->y;
				(PointArray + j - 1)->x = (PointArray + j)->x;
				(PointArray + j - 1)->y = (PointArray + j)->y;
				(PointArray + j)->x = temp.x;
				(PointArray + j)->y = temp.y;
			}
		}
	}

	return PointArray;
}

void MyGeometry::Report(const char* filename,unsigned int &nPoint) { //輸出題目要求格式

	fstream outfile;
	string outputPath = "Answer.txt";
	stringstream answer ;
	Point* PointArray;
	answer << "物件導向程式設計第一次作業\nN16054598  陳紀融";	
	PointArray = LoadPoint(filename, nPoint);
	answer << "\n點數目:"<<nPoint;
	answer << "\n最接近 x 軸的點:" << MinVerticalDistance(PointArray, nPoint)->CoutPoint();
	answer << "\n與原點距離最遠的點:" << (SortbyLength(PointArray, nPoint)+ nPoint-1)->Length();

	outfile.open(outputPath, ios::out);
	outfile << answer.str();
	outfile.close();
	delete[] PointArray;
}


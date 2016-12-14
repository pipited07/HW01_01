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
	while (getline(fin, temp, '\n')) //�p����
		count++;
	fin.close();
	nPoint = count;


	Point* PointArray = new Point[count];  //new�X�I�Ŷ�


	fin.open(filename, ios::in);
	for (int i = 0; getline(fin, temp, '\n'); i++){//�r��B�z�N�I���X�s�ipoint
		PointArray[i].x = stof(temp.substr(0, temp.find(' ')));
		PointArray[i].y = stof(temp.substr(temp.find(' '), temp.find('\n')));
	}
	fin.close();

	return PointArray;
}

Point* MyGeometry::MinVerticalDistance(Point* PointArray, unsigned int& nPoint) {//��X��x�b�̪��I�����ޭȡA�öǦ^����
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
Point * MyGeometry::SortbyLength(Point * PointArray, unsigned int & nPoint) //�Ѥp��j�Ƨ�
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

void MyGeometry::Report(const char* filename,unsigned int &nPoint) { //��X�D�حn�D�榡

	fstream outfile;
	string outputPath = "Answer.txt";
	stringstream answer ;
	Point* PointArray;
	answer << "����ɦV�{���]�p�Ĥ@���@�~\nN16054598  ������";	
	PointArray = LoadPoint(filename, nPoint);
	answer << "\n�I�ƥ�:"<<nPoint;
	answer << "\n�̱��� x �b���I:" << MinVerticalDistance(PointArray, nPoint)->CoutPoint();
	answer << "\n�P���I�Z���̻����I:" << (SortbyLength(PointArray, nPoint)+ nPoint-1)->Length();

	outfile.open(outputPath, ios::out);
	outfile << answer.str();
	outfile.close();
	delete[] PointArray;
}


#ifndef HW01_02_H
#define HW01_02_H
#include<string>

namespace MyGeometry
{

	struct Point //#1
	{		
		float x;
		float y;
		double Length(); //#2
		std::string CoutPoint(); //#3
	};
	Point* LoadPoint(const char* filename, unsigned int& nPoint); //#4
	Point* MinVerticalDistance(Point* PointArray, unsigned int &nPoint); //#5
	Point* SortbyLength(Point* PointArray, unsigned int &nPoint); //#6
	void Report(const char* filename, unsigned int &nPoint); //#7
}



#endif 
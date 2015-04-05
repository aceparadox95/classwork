/***************************************************************
 * Author: Ryan Cosby
 * Date Created: 11/25/2014
 * Last Modification Date: 11/25/2014
 * File name: geom.cpp
 *
 * Overview:
 * This program creates a line object based on input coordinates
 * from the user. The line object has two functions that hold the
 * lines slope and the lines length
 *
 * Input:
 * Coordinates for both ends of the line
 *
 * Output:
 * Prints the length and slope member function outputs
 * **************************************************************/ 
 
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Point // Point Class
{
	private:
		double x; //x coordinate variable
		double y; //y coordinate variable
	public:
	    Point(); //default constructor prototype
		Point (double, double); //constructor prototype
		double get_x();// function to access private x value prototype
		double get_y();// function to access private y value prototype
		double distanceTo(Point);// function to find distance between points prototype
};

class LineSegment
{
	private:
		Point bgn;//line beginning coordinate pair
		Point end;//line ending coordinate pair
	public:
		LineSegment (Point, Point);//line segment constructor prototype
		double length();//line length member function prototype
		double slope();//line slope member function prototype
};

Point::Point() //default constructor prototype
{
	x = 0;
	y = 0;
}


Point::Point(double xval, double yval) //constructor prototype
{
	x = xval;
	y = yval;
}

double Point::get_x() // function to access private x value
{
    return x;   
}

double Point::get_y()// function to access private y value
{
    return y;   
}

double Point::distanceTo(Point inpPt)// function to find distance between points
{
	return sqrt((pow((inpPt.x - x),2.0)) + (pow((inpPt.y - y),2.0)));// square root of (a^2 + b^2)
}


LineSegment::LineSegment(Point bgnPt, Point endPt)//line segment constructor
{
	bgn = bgnPt;//initialize beginning point
	end = endPt;//initialize ending point
}

double LineSegment::length() //line length member function
{
	return bgn.distanceTo(end);
}

double LineSegment::slope() //line slope member function
{
	return (end.get_y() - bgn.get_y())/(end.get_x()- bgn.get_x()); // rise over run
}

int main()
{
	char userState = 'y';//storing user state
	while (userState == 'y') // keep user in loop till they want to exit
	{
	string coord1, coord2, c1x, c1y, c2x, c2y;
	int commIndex = 0;
	cout << "Enter the coordinates for the first point (x, y): " << endl;
	getline(cin, coord1);
	cout << "Enter the coordinates for the second point (x, y): " << endl;
	getline(cin, coord2);
	for (int i = 0; i < coord1.length(); i++) //splitting first coordinates
	{
		if (coord1[i] == ',')
			commIndex = i;
	}
	for (int i = 0; i < commIndex; i++)
	{
		c1x+= coord1[i];
	}
	for (int i = commIndex + 2; i < coord1.length(); i++)
	{
		c1y+= coord1[i];
	}
	for (int i = 0; i < coord2.length(); i++)  //splitting second coordinates
	{
		if (coord2[i] == ',')
			commIndex = i;
	}
		for (int i = 0; i < commIndex; i++)
	{
		c2x+= coord2[i];
	}
	for (int i = commIndex + 2; i < coord2.length(); i++)
	{
		c2y+= coord2[i];
	}
	Point p1(atof(c1x.c_str()), atof(c1y.c_str())); //create beginning point object
	Point p2(atof(c2x.c_str()), atof(c2y.c_str())); //create ending point object
	LineSegment lineseg (p1,p2);//create line object with both points
	cout << "Line Length = " << lineseg.length() << endl; //print length
	if (isinf((float)lineseg.slope())) // print infinity if infinity
		cout << "The line slope is vertical" << endl;
	else
		cout << "Line Slope = " << lineseg.slope() << endl;// print slope if not infinity	
	cout << "Do you want to created another line? (y or n)" << endl;// prompt user to create new line
	cin >> userState; //store response
	cin.ignore(); //clear keyboard buffer
	}
	return 0;
}
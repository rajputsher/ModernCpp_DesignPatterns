#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
#include <cmath>
using namespace std;


enum class PointType
{
    cartesian,
    polar
};

class Point
{
    
    private:
        // Here the constructor point is made private
        //Hence a Point cannot be created like this Point p {5,10};
        //However, with the methods, it can be created as in the main function
        Point(float x, float y): x(x), y(y){}
        friend class PointFactory; //violates open-closed principle
        //We can avoid using the friend class if we make the constructor public then we do not violate OCP
        //However the Point constructor is sensitive becaue the user might create a polar cordinate just using auto p1{1,2} which is not correct as this will create a cartesian cordinate.
    public:
        float x,y;
        // class methods
        // static Point NewCartesian(float x, float y)
        // {
        //     return {x,y};
        // }

        // static Point NewPolar(float  r, float theta)
        // {
        //     return {r*cos(theta), r*sin(theta)};
        // }

        friend ostream& operator<<(ostream &os, const Point &point)
        {
            os<<"x: "<< point.x<<" y: "<< point.y;
            return os;
        }
};

//seperating the concert
// moving the method from class point to the PointFactory
class PointFactory
{
    // This class cannot access the  private constructor of Point class
    //We need to make an ugly change for that. i.e friend class PointFactory in point class
    //This in turn violated Open closed principle 
        PointFactory(){}
    public:
        static Point NewCartesian(float x, float y)
        {
            return {x,y};
        }

        static Point NewPolar(float  r, float theta)
        {
            return {r*cos(theta), r*sin(theta)};
        }
};

int main()
{
    // auto pc = Point::NewCartesian(5,10);
    // auto pp = Point::NewPolar(5,M_PI_4);
    // cout <<"Cartesian point: " <<pc<<endl;
    // cout <<"Polar point: " <<pp<<endl;

    auto P = PointFactory::NewPolar(5,M_PI_4);

    return 0;
}
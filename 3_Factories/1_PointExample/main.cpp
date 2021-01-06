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

struct Point
{
    float x,y;

    //We can add a constructor as below to accomodate both Cartesian and Polar co-ordinates
    //There is a draw back i.e, we do not know what a and b corresponds to. We can overcome this by adding description as below
    // param a : either x or rho
    // param b : either y or theta
    // we can over come this by moving initialization from  constructor to a Factory method.
    Point(float a, float b, PointType type = PointType::cartesian)
    {
        if(type == PointType::cartesian)
        {
            x =a;
            y=b;
        }
        else
        {
            x = a * cos(b);
            y = a * sin(b);
        }
        
    }
};

// struct Point
// {
//     float x,y;

//     //constructor: Strictly cartesian
//     Point(float x,float y):x(x), y(y)
//     {

//     }
//     //What if we need a constructor for polar cordinates
//     //constructor
//     Point(const float rho, const float thetha)
//     {

//     }
//     //But unfortunately, we have already got a constructor with two floats,
//     //so you cannot have another one.

// }


int main()
{
    return 0;
}
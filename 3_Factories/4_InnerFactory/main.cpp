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

class Point
{
  /*Point(float a, float b, PointType type = PointType::cartesian)
  {
  if (type == PointType::cartesian)
  {
  x = a; b = y;
  }
  else
  {
  x = a*cos(b);
  y = a*sin(b);
  }
  }*/

  // use a factory method
  Point(float x, float y) : x(x), y(y) {}

  class PointFactory
  {
    PointFactory() {}
  public:
    static Point NewCartesian(float x, float y)
    {
      return { x,y };
    }
    static Point NewPolar(float r, float theta)
    {
      return{ r*cos(theta), r*sin(theta) };
    }
  };
public:
    float x, y;
    static PointFactory Factory;
    friend ostream& operator<<(ostream &os, const Point &point)
    {
        os<<"x: "<< point.x<<" y: "<< point.y;
        return os;
    } 
};

int main()
{
  // will not work
  // Point p{ 1,2 };

  // nope!
  // Point::PointFactory pf;

  // if factory is public, then
  //auto p = Point::PointFactory::NewCartesian(3, 4);

  // at any rate, use this
  auto pp = Point::Factory.NewCartesian(2, 3);
  cout << pp<< endl;

  return 0;
}
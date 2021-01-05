#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

class Rectangle
{
    protected:
        int width, height;

    public:
        Rectangle(int width, int height): width(width), height(height)
        {

        }

        int getWidth() const{
            return width;
        }

        int getHeight() const{
            return height;
        }

        virtual void setWidth(int width) {
            Rectangle::width = width;
        }

        virtual void setHeight(int height){
            Rectangle::height = height;
        }

        int area() const
        {
            return width*height;
        }
};

class Square: public Rectangle
{
    public:
        Square(int size): Rectangle(size,size)
        {

        }
    void setWidth(int width) override
    {
        this->width = this->height = width;
    }   

    void setHeight(int height) override
    {
        this->width = this->height = height;
    }
};

void process(Rectangle& r)
{
    int w=r.getWidth();
    r.setHeight(10);
    cout<< "expected area = "<< (w*10)
        <<", got "<<r.area()<<endl;
}

// The call of sqaure with process function, we can see that it fails 
// The better way of creating a sqaure would be to create a factory such as below and then we can adhere it to the liskov substitution principle
struct RectangleFactory
{
  static Rectangle create_rectangle(int w, int h);
  static Rectangle create_square(int size);
};

int main()
{
    Rectangle r{3,4};
    process(r);

    Square sq{5};
    process(sq);

    return 0;
}
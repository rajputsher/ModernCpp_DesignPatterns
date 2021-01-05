#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

enum class Color {red, green, blue};
enum class Size {small, medium, large};

struct Product
{
    string name;
    Color color;
    Size size;
};

//Here we can see that for each new criteria we are repeating the code and this is not a scalable approach
//As the criteria to filter by increases the number of funcitons increases.
struct ProductFilter
{
    //The following method filters the input items by color and ouputs the products(pointer to products)
    vector<Product*> by_color(vector<Product*> items, Color color){
        vector<Product*> result;
        for(auto& i: items)
            if(i->color == color)
                result.push_back(i);
        return result;
    }

    //Filter by Size
    vector<Product*> by_size(vector<Product*> items, Size size){
        vector<Product*> result;
        for(auto& i: items)
            if(i->size == size)
                result.push_back(i);
        return result;
    }

    //Filter by Size and Color
    vector<Product*> by_size_and_color(vector<Product*> items, Size size,Color color){
        vector<Product*> result;
        for(auto& i: items)
            if(i->size == size && i->color == color)
                result.push_back(i);
        return result;
    }
};


int main()
{
    Product apple{"Apple",Color::green,Size::small};
    Product tree{"Tree",Color::green,Size::large};
    Product house{"House", Color::blue, Size::large};

    vector<Product*> items {&apple, &tree, &house};

    ProductFilter pf;

    auto green_things = pf.by_color(items, Color::green);
    for(auto& item: green_things)
        cout<< item->name << "is green\n";
    

    return 0;
}
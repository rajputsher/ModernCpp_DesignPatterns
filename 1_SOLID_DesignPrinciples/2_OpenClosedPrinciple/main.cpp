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

template <typename T> 
struct Specification
{
     virtual ~Specification() = default;
     virtual bool is_satisfied(T* item) const = 0;
};

template <typename T> 
struct Filter
{
    virtual vector<T*> filter(vector<T*> items, 
                             Specification<T>& spec) = 0;
};

struct BetterFilter:Filter<Product>
{
    vector<Product *> filter(vector<Product *> items,
                            Specification<Product> &spec) override
    {
        vector<Product*> result;
        for (auto& item:items)
            if(spec.is_satisfied(item))
                result.push_back(item);
        return result;
    }

};

struct ColorSpecification: Specification<Product>
{
    Color color;

    ColorSpecification(Color color): color(color){}

    bool is_satisfied(Product *item) const override {
        return item->color == color;
    }
};

struct SizeSpecification: Specification<Product>
{
    Size size;

    explicit SizeSpecification(const Size size):size{size}
    {

    }
    bool is_satisfied(Product* item) const override{
        return item->size == size;
    }
};

template <typename T> struct AndSpecification;

// new: 
template <typename T> 
AndSpecification<T> operator&&
  (const Specification<T>& first, const Specification<T>& second)
{
  return { first, second };
}

//Combinator Specification
template <typename T>
struct AndSpecification: Specification<T> //Andspecification inherits from Specification
{
    //Take the arguments of left and right then combine it
    const Specification<T>& first;
    const Specification<T>& second;

    AndSpecification(const Specification<T> &first,const Specification<T> &second):first(first),second(second)
    {

    }
    bool is_satisfied(T *item) const override
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

int main()
{
    Product apple{"Apple",Color::green,Size::small};
    Product tree{"Tree",Color::green,Size::large};
    Product house{"House", Color::blue, Size::large};

    const vector<Product*> items {&apple, &tree, &house};

    /* Need not repeat this for each filter
    ProductFilter pf;

    auto green_things = pf.by_color(items, Color::green);
    for(auto& item: green_things)
        cout<< item->name << "is green\n";
    */

   BetterFilter bf;
   ColorSpecification green(Color::green);
   
   for(auto& item: bf.filter(items, green) )
      {
        cout<< item->name << " is green\n";
      }  

   SizeSpecification large(Size::large);
   AndSpecification<Product> green_and_large(green,large); 

   for(auto& item: bf.filter(items, green_and_large))
   {
       cout<< item->name << " is green and large\n";
   }
   
   return 0;
}
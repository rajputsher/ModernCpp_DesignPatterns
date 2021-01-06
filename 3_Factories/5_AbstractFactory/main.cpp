#include <iostream>
#include <memory>
#include <map>
#include "HotDrink.hpp"
#include "DrinkFactory.hpp"
using namespace std;

unique_ptr<HotDrink> make_drink(string type)
{
  unique_ptr<HotDrink> drink;
  if (type == "tea")
  {
    drink = make_unique<Tea>();
    drink->prepare(200);
  }
  else 
  {
    drink = make_unique<Coffee>();
    drink->prepare(50);
  }
  return drink;
}

int main()
{
  auto d = make_drink("tea");
  cout<<"================================"<<endl;
  DrinkFactory df_C;
  df_C.make_drink("coffee");
  cout<<"================================"<<endl;
  DrinkFactory df_T;
  df_T.make_drink("tea");

  getchar();
  return 0;
}
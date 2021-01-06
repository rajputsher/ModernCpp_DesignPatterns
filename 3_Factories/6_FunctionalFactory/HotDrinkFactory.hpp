#pragma once
#include "HotDrink.hpp"

// Factory
struct HotDrinkFactory
{
  //unique_ptr : shared pointers
  virtual unique_ptr<HotDrink> make() const = 0;
};
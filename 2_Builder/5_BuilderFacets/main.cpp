#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

#include "Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonJobBuilder.hpp"

int main ()
{
  Person p = Person::create()
    .lives().at("The long Road").with_postcode("007 007").in("Utopia")
    .works().at("Building With Computers").as_a("Engineer").earning(100000);

  cout << p << endl;
  getchar();
  return 0;
}
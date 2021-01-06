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

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
using namespace boost;



struct Address
{
  string street,city;
  int suite;
  //Empty constructor
  Address() {}
  //Constructor
  Address(const string& street, const string &city, int suite): 
          street(street), city(city), suite(suite)
          {

          }
  //Robust way of doing is not only creating copy construct in the Contact class  but also here 
  Address(const Address& other):
    street{other.street},city{other.city}, suite{other.suite}{}

  friend ostream &operator<<(ostream &os, const Address &address)
  {
    os << "street: "<< address.street << " city: " << address.city
      <<" suite: " << address.suite;
    return os;
  }

  private:
  friend class serialization::access;

  template <class archive>
    void serialize(archive& ar,const unsigned Version)
    {
      ar &street;
      ar &suite;
      ar &city;
    }

};

struct Contact 
{
  string name;

  // Initially
  // Address address;
  Address* address; 
  // Default contructor // required for serialization
  Contact()// : name(nullptr), address(nullptr)
  {

  } 

  Contact(const string &name,  Address *address):
    name(name), address(address)
    {

    }  
  //Copy Constructor
  // Contact(const Contact& other)
  //   : name{other.name} //Copy the name as it is 
  //   , address{new Address {other.address->street, other.address->city, other.address->suite}} //This will create a new Address and then copy
  // {

  // }

  //Copy Construct after adding copy construct in Address class
  Contact(const Contact& other)
    : name{other.name} //Copy the name as it is 
    , address {new Address{*other.address}} //This will create a new Address and then copy
  {

  }

  friend ostream &operator<<(ostream &os, const Contact &contact)
  {
    os << " Name: " << contact.name << " Address: " << *contact.address;
    return os;
  }

  private:
  friend class serialization::access;

  template <class archive>
    void serialize(archive& ar,const unsigned Version)
    {
      ar &name;
      ar &address;
    }
};

//Contact main{"",new Address{"","",0}}


struct EmployeeFactory
{
  static Contact main;
  static Contact aux;

  static unique_ptr<Contact> NewMainOfficeEmployee(string name, int suite)
  {
    static Contact p{ "", new Address{"221b baker street","London",006} };
    return NewEmployee(name, suite, p);
  }

  static unique_ptr<Contact> NewAuxOfficeEmployee(string name, int suite)
  {
    return NewEmployee(name, suite, aux);
  }

private:
  // smart pointer
  //We can use this as a utitlity function to create NewMainOfficeEmployee and NewAuxOfficeEmployee
  static unique_ptr<Contact> NewEmployee(string name, int suite, Contact& prototype)
  {
    auto result = make_unique<Contact>(prototype);
    result->name = name;
    result->address->suite = suite;
    return result;
  }
};

// int main()
// {
//   // Contact sherlock{"Sherlock holmes",  Address{"221b baker street","London",006}};
//   Contact sherlock{"Sherlock holmes", new Address{"221b baker street","London",006}};

//   //Contact james{"James Bond", Address{"221a baker street","London",007}};
//   //Alternate way of doing the same

//   // Contact james=sherlock; 
//   // james.name = "James Bond";
//   // james.address.suite= 007;
//   // james.address.street="221a baker street";
//   // james.address.city="London";

//   //Shallow Copy
//   //Contact james = sherlock; // Here is where the problem begins, this does not do a deep copy
//   //  james.name= "James Bond";
//   // james.address->suite = 007; // This will not only change for james but also it will change to 007 for sherlock
//   // // This is because whe we did Contact james = sherlock; the adrress pointer was also copied to james and we are modifying the both addresses.
//   // cout << sherlock <<james<<endl; // This will print same address for both James and sherlock.
//   //***************************//

//   //Deep Copy
//   Contact james{sherlock}; //uses copy construct
//   // The above method works but it can be give as an API for the users
//   james.name= "James Bond";
//   james.address->suite = 007; 
//   cout << sherlock <<james<<endl; // This will print different suite values for James and Sherlocks as desired

//   return 0;
// }

// int main()
// {
//   auto sherlock = EmployeeFactory::NewMainOfficeEmployee("Sherlock",006);
//   cout<<*sherlock<<endl;

//   return 0;
// }

int main()
{
  auto clone= [](const Contact& c)  
                { //serializing
                    ostringstream oss;
                    archive::text_oarchive oa(oss);
                    oa<<c;
                    string s= oss.str();
                    cout << s <<endl;

                  //Deserializing
                    istringstream iss(s);
                    archive::text_iarchive ia(iss);
                    Contact result;
                    ia >> result;
                    return result;
                };
  auto sherlock = EmployeeFactory::NewMainOfficeEmployee("Sherlock", 006);
  auto james = clone(*sherlock);
  james.name = "James Bond";
  james.address->suite = 007;
  cout << *sherlock <<endl<<james <<endl; //only sherlock needs pointer because james is just a reference

  return 0;
}
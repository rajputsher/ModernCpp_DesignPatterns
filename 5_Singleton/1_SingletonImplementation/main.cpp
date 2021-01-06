#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
#include <cmath>
#include <map>
using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;


class SingletonDatabase
{
  //constructor is made private so it can be instantiated by anyone
  SingletonDatabase()
  {
    cout<< "Initializing database\n";

    ifstream ifs("capitals.txt");

    string s,s2;

    while (getline(ifs,s))
    {
      getline(ifs,s2);
      int pop = lexical_cast<int>(s2);
      capitals[s] = pop;
    }
    
  }
  map<string,int> capitals;

  public:
    // just because we have made the constructor private that does not mean some one else cannot make another database
    // to ensure that we need to delete the following constructors
    //copy constructor
    SingletonDatabase(SingletonDatabase const &) = delete;
    //Assignment operator Construct
    void operator=(SingletonDatabase const&) = delete;

    //How do we make people use SingletonDatabase?
    //We  create static get method

    static SingletonDatabase& get()
    {
      static SingletonDatabase db;
      return db;
    }

    //Now api to get population of a particular city
    int get_population(const string& name)
    {
      return capitals[name];
    }
};

int main()
{
  //auto db = SingletonDatabase::get(); // cannot be used because the copy = constructor is deleted
  string city="Delhi";
  cout<< city<< " has population "<< 
        SingletonDatabase::get().get_population(city)<<endl; // only way
  return 0;
}
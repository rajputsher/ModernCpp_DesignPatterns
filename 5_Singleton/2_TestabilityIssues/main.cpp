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

#include "gtest/gtest.h"


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

struct SingletonRecordFinder
{
  int total_population(vector<string> names)
  {
    int result{0};
    for(auto& name: names)
      result += SingletonDatabase::get().get_population(name);
    return result;
  }
};

//Here we are not able to do a unit test this is more of a integration test
//Because we are getting the test data from the database 
TEST(RecordFinderTest, SingletonTotalPopTest)
{
  SingletonRecordFinder rf;
  vector<string> names{"Seoul","Stockholm"};
  int tp= rf.total_population(names);
  EXPECT_EQ(1234000+48700,tp);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
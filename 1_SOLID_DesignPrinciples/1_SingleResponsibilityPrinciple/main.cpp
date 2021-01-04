#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

struct Journal
{
    string title;
    vector<string> entries;

    Journal(const string &title): title(title) {} //constructor

    void add_entry(const string& entry)
    {
        static int count =1;
        entries.push_back(lexical_cast<string>(count++) + ": "+ entry);
    }

    /*Not a good idea to add the save operation in the same class
    as someday we might want to save this in a database Better add it in a seperate class
    */
    /*
    void save(const string& filename)
    {
        ofstream ofs(filename);
        for (auto& e: entries)
        {
            ofs << e << endl;
        }
    }
    */
};

//By have a sepearte part for Managing persistence we can have each class its own reposibilities
// by doing this we seperate the concerns that might arise due to that
struct PersistenceManager{

    static void save(const Journal& j , const string& filename)
    {
        ofstream ofs(filename);
        for (auto& e: j.entries)
        {
            ofs << e << endl;
        }
    }
};

int main()
{
    Journal journal{"My Diary 2021"};
    journal.add_entry("I completed a course");
    journal.add_entry("I read a book");

    //journal.save("my_diary_2021.txt");

    PersistenceManager pm;
    pm.save(journal, "my_diary_2021.txt");

    getchar();
    return 0;
}
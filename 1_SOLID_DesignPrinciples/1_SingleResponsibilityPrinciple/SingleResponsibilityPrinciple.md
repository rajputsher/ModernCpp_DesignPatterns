# Single Responsibility Principle

The single-responsibility principle (SRP) is a computer-programming principle that states that every class in a computer program should have responsibility over a single part of that program's functionality, which it should encapsulate. All of that module, class or function's services should be narrowly aligned with that responsibility

The requirements of a component(sw application) change over time. Each of them also changes the responsibility of at least one class. The more responsibilities one class has, the more often you need to change it. If one class implements multiple responsibilities, they are no longer independent of each other.

That might not seem like a big deal, but it also affects all classes or components that depend on the changed class. Depending on your change, you might need to update the dependencies or recompile the dependent classes even though they are not directly affected by your change. They only use one of the other responsibilities implemented by your class, but you need to update them anyway.

In the end, you need to change your class more often, and each change is more complicated, has more side-effects, and requires a lot more work than it should have. So, it’s better to avoid these problems by making sure that each class has only one responsibility. 

## Benifits of SRP

- Frequency and Effects of Changes
- Easier to Understand
- Easier to validated

## Example

In the below example the having functions such as save to file in  `struct Journal` is not desirable. It is better to handle persistency related functionalities in a seperate struct.


```c++
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
```

## References
1. [Stackify](https://stackify.com/solid-design-principles/)
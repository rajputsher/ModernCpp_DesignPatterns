#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
// #include <boost/lexical_cast.hpp>

using namespace std;
// using namespace boost;

// A. High-level modules should not depend on low-level modules.
//    Both should depend on abstractions.
// B. Abstractions should not depend on details. 
//    Details should depend on abstractions.

enum Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    string name;
};

//Introducing abstraction
struct RelationshipBrowser
{
    virtual vector<Person> find_all_children_of(const string& name) =0;
};


struct Relationships: RelationshipBrowser //low-level module/construct
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_child(const Person& parent, const Person& child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child,Relationship::child,parent}); //Inverse relationship
    }

    vector<Person> find_all_children_of(const string& name) override
    {
        vector<Person> result;
        for (auto&& [first, rel, second]: relations)
        {
            if (first.name == name && rel == Relationship::parent)
            {
                result.push_back(second);
            }
        }
        return result;
    }
};


//Below the high-level module is dependent on the low-level
//If we change the relations variable in struct Relationships from public to private, the below class will no longer be usable
struct Research //high-level
{

    Research(RelationshipBrowser& browser)
    {
        for (auto& child : browser.find_all_children_of("John"))
        {
            cout << "John has a child called " << child.name << endl;
        }
    }
    // Research(Relationships& relationships) // Here we are depending on the low-level module. This should not be done
    // {
    //     auto& relations = relationships.relations;
    //     for (auto&& [first,rel,second]: relations)
    //     {
    //         if(first.name == "John" && rel == Relationship::parent)
    //         {
    //             cout<<"John has a child called " << second.name<< endl;
    //         }
    //     }
    // }
};

int main()
{
    Person parent{"John"};
    Person child1{"Max"}, child2{"Paul"};

    Relationships relationships;
    relationships.add_parent_child(parent,child1);
    relationships.add_parent_child(parent,child2);

    Research _(relationships);
    return 0;
}
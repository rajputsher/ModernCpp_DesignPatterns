#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
using namespace std;

// Is the last 2 sections we output html from C++
//Here :We can construct a html like construct using unique initializer syntax

struct Tag
{
    string name,text;
    vector<Tag>  children;
    vector<pair<string,string>> attributes;
    // String output operator on the Tag to print all the tags and children 
    friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
    {
      os << "<" << tag.name;

      for (const auto& att : tag.attributes)
        os << " " << att.first << "=\"" << att.second << "\"";

      if (tag.children.size() == 0 && tag.text.length() == 0)
      {
        os << "/>" << std::endl;
      } 
      else
      {
        os << ">" << std::endl;

        if (tag.text.length())
          os << tag.text << std::endl;

        for (const auto& child : tag.children)
          os << child;

        os << "</" << tag.name << ">" << std::endl;
      }

      return os;
    }

    protected:
        //constructor
        Tag(const string &name, const string &text): name(name), text(text)
        {

        }

        //constructor with children
        Tag(const string &name, const vector<Tag> &children):
            name(name), children(children) 
        {

        }
};

//creating a tag
// Tag paragraph <p>

struct P: Tag
{
    //constructor
    P(const string &text) : Tag("p",text){}

    //Paragraph can have a children of its own
    //constructor
    P(initializer_list<Tag> children)
        :Tag{"p",children}{}
};

//creating a tag
// Tag Image <img>

struct IMG: Tag
{
    explicit IMG(const string& url): Tag{"img",""}
    {
        attributes.emplace_back(make_pair("src",url));
    }
};

int main()
{
    // we can write html like syntax in C++ using uniform initializer
    cout<<
            P
            {
                IMG{"http://dragonballz.com/vegeta.png"}
            }
        <<endl;
    return 0;
}
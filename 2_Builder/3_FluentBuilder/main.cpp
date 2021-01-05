#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
using namespace std;

struct HtmlBuilder;

struct HtmlElement // HtmlElement represents different elements for ex: <p> paragraph
{
    string name, text;
    vector<HtmlElement> elements; //Element can contain other element ex: paragraph can contain <ul> unordered lists
    const size_t indent_size = 2;

    HtmlElement(){} //empty constructor
    HtmlElement(const string &name, const string &text) : name(name), text(text) //constructor with arguments
    {

    }

    string str(int indent=0) const 
    {
        ostringstream oss;
        string i(indent_size*indent, ' '); 
        oss << i << "<" << name << ">" << endl;
        if (text.size() > 0)
        oss << string(indent_size*(indent + 1), ' ') << text << endl;

        for (const auto& e : elements)
        oss << e.str(indent + 1);

        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }
    
    //Fluent builder
    // static HtmlBuilder build(string root_name)
    // {
    //     return {root_name};
    // }
    static unique_ptr<HtmlBuilder> build(string root_name)
        {
            return make_unique<HtmlBuilder>(root_name);
        }
};

// Builder
struct HtmlBuilder
{
    HtmlElement root;

    HtmlBuilder(string root_name)//Constructor
    {
        root.name= root_name;
    }

    //add children to root element

    // void add_child(string child_name, string child_text)
    // {
    //     HtmlElement e{child_name, child_text};
    //     root.elements.emplace_back(e); //similar to push back but for constructor with more than one arhuments
    // }

    //Fluent Builder
    // void to start with
    HtmlBuilder& add_child(string child_name, string child_text)
    {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e); //similar to push back but for constructor with more than one arhuments
        return *this;
    }

    HtmlBuilder* add_child2(string child_name, string child_text)
    {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e); //similar to push back but for constructor with more than one arhuments
        return this;
    }

    string str() const 
    {
        return root.str();
    }

    operator HtmlElement() const{return root;}


};



int main()
{
    auto text = "hello";
    string output;
    output += "<p>"; //paragraph html tag
    output += text; //paragraph text
    output += "</p>"; //paragraph end tag
    cout<< output << endl;

    // The above approach works but is not scalable

    /************************************************/
    //Lets consider an example of printing bunch of lists
    string words[] = {"hello","world"};
    ostringstream oss;
    oss << "<ul>\n";
    for (auto w: words)
    {
        oss<< "  <li>"<< w << "</li>\n";
    }
    oss << "\n</ul>";
    cout<< oss.str()<<endl;
    //Html is a structured format but none of this is expressed here 
    
    cout<<"/************************************************/\n"<<endl;
    // Here instead of directly working with the HtmlElement we use a HtmlBuilder to build the html content in a structred way.
    // HtmlBuilder builder{"ul"};
    // builder.add_child("li","hello");
    // builder.add_child("li","world");
    // cout<<builder.str()<<endl;
    
    HtmlBuilder builder{"ul"};
    builder.add_child("li","hello").add_child("li","world");// we can append more of the similar operation
    cout<<builder.str()<<endl;
    
    cout<<"/************************************************/\n"<<endl;

    auto builder2 = HtmlElement::build("ul")->add_child2("li","Hello")->add_child2("li","world");
    cout<<builder2<<endl;
    return 0;

}
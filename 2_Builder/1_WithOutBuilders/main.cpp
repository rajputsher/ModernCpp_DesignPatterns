#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
using namespace std;

// Life without Builders
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
    return 0;
}
#include <string>
#include <iostream>
#include "PersonFactory.cpp"

int main()
{
    PersonFactory pf;
    auto P1 = pf.create_person("Max");
    cout<<"Person1: "<< P1 <<endl;


    auto P2 = pf.create_person("Paul");
    cout<<"Person2: "<<P2 <<endl;
}
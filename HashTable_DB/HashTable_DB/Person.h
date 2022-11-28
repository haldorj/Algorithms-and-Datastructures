#pragma once

class Person
{
public:
    std::string Name;
    int age;
 
    // Next ptr for linked list
    Person* Next = nullptr;
};
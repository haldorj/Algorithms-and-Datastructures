#pragma once

struct Person
{
    std::string Name;
    int age;
 
    // Next ptr for linked list
    Person* Next;
};
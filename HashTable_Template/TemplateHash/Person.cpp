#include "Person.h"

std::ostream& operator<<(std::ostream& lhs, Person& rhs) {
    lhs << "AGE: " << rhs.Age << " NAME: " << rhs.Name;
    return lhs;
}
Person::Person(int age, std::string name, char bingus) {
    Age = age;
    Name = name;
    Bingus = bingus;
}
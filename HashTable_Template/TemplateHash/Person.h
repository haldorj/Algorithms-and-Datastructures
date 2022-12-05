#include <ostream>
#include <string>
#include <xthreads.h>

class Person {
public:
    Person() = default;

    Person(int age, std::string name, char bingus);

    int Age{};
    std::string Name;
    char Bingus{};

    // lhs LeftHandSide
    Person operator+(const Person& rhs) {
        Person newPerson{};
        newPerson.Age = Age + rhs.Age;
        newPerson.Name = Name + rhs.Name;
        newPerson.Bingus = 'B';
        return newPerson;
    }

    friend std::ostream& operator<<(std::ostream& lhs, Person& rhs);

    // friend std::ostream& operator<<(std::ostream& lhs, Person& rhs);
};

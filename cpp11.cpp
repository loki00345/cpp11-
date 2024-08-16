#include <iostream>
#include <cstring>

using namespace std;

class Human {
public:
    char* name;
    int age;

    Human() : name{ new char[8] {"noname"} }, age{ 0 } {}

    Human(const char* name, int age) : name{ new char[strlen(name) + 1] }, age{ age } {
        strcpy_s(this->name, strlen(name) + 1, name);
    }

    Human(const Human& other) : name{ new char[strlen(other.name) + 1] }, age{ other.age } {
        strcpy_s(this->name, strlen(other.name) + 1, other.name);
    }

    Human& operator=(const Human& other) {
        if (this == &other) return *this;

        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name) + 1, other.name);
        age = other.age;

        return *this;
    }

    ~Human() {
        delete[] name;
    }

    void print() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Apartment {
private:
    Human* people;
    int peopleCount;

public:
    Apartment() : people{ nullptr }, peopleCount{ 0 } {}

    Apartment(Human* people, int count) : people{ new Human[count] }, peopleCount{ count } {
        for (int i = 0; i < count; i++) {
            people[i] = people[i];
        }
    }

    Apartment(const Apartment& other) : people{ new Human[other.peopleCount] }, peopleCount{ other.peopleCount } {
        for (int i = 0; i < peopleCount; i++) {
            people[i] = other.people[i];
        }
    }

    Apartment& operator=(const Apartment& other) {
        if (this == &other) return *this;

        delete[] people;
        peopleCount = other.peopleCount;
        people = new Human[peopleCount];
        for (int i = 0; i < peopleCount; i++) {
            people[i] = other.people[i];
        }

        return *this;
    }

    ~Apartment() {
        delete[] people;
    }

    void print() const {
        cout << "Apartment with " << peopleCount << " people:" << endl;
        for (int i = 0; i < peopleCount; i++) {
            people[i].print();
        }
    }
};

class House {
private:
    Apartment* apartments;
    int apartmentCount;

public:
    House() : apartments{ nullptr }, apartmentCount{ 0 } {}

    House(Apartment* apartments, int count) : apartments{ new Apartment[count] }, apartmentCount{ count } {
        for (int i = 0; i < count; i++) {
            apartments[i] = apartments[i];
        }
    }

    House(const House& other) : apartments{ new Apartment[other.apartmentCount] }, apartmentCount{ other.apartmentCount } {
        for (int i = 0; i < apartmentCount; i++) {
            apartments[i] = other.apartments[i];
        }
    }

    House& operator=(const House& other) {
        if (this == &other) return *this;

        delete[] apartments;
        apartmentCount = other.apartmentCount;
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; i++) {
            apartments[i] = other.apartments[i];
        }

        return *this;
    }

    ~House() {
        delete[] apartments;
    }

    void print() const {
        cout << "House with " << apartmentCount << " apartments:" << endl;
        for (int i = 0; i < apartmentCount; i++) {
            apartments[i].print();
        }
    }
};

int main() {
    Human people1[] = { Human("Alice", 25), Human("Bob", 30) };
    Apartment apt1(people1, 2);
    Human people2[] = { Human("Charlie", 35), Human("David", 40) };
    Apartment apt2(people2, 2);

    Apartment apartments[] = { apt1, apt2 };
    House house(apartments, 2);

    house.print();
}
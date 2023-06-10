#include <iostream>
using namespace std;

class Flat
{
public:
    Flat() { cout << "Flat construct\n"; }
    ~Flat() { cout << "Flat destruct\n"; }
};

class Build
{
    Flat flat;
public:
    Build() { cout << "Build construct\n"; }
    ~Build() { cout << "Build destruct\n"; }
};


class Boss
{
public:
    Boss() { cout << "Boss construct\n"; }
    ~Boss() { cout << "Boss destruct\n"; }
};

class Department
{
    Boss* boss;
public:
    Department(Boss* boss = nullptr) : boss{ boss }
        { cout << "Department construct\n"; }

    ~Department() { cout << "Department destruct\n"; }
};



class Animal
{
    string name;
public:
    Animal(string name = "") : name{ name } {}
    virtual void Say() { cout << "???\n"; }
    void Name() { cout << name << "\n"; }
};

class Cat : public Animal
{
public:
    Cat() : Animal("Cat") {}
    void Say() override { cout << "myau\n"; }
};

class PersCat : public Cat
{

};

class Dog : public Animal
{
public:
    Dog() : Animal("Dog") {}
    void Say() override { cout << "gaff\n"; }
};

class Base
{
public:
    Base() { cout << "base construct\n"; }
    virtual ~Base() { cout << "base destruct\n"; }
};

class Derived : public Base
{
    int* pointer;
public:
    Derived() : pointer{ new int[10] } 
    { 
        cout << "Derived construct\n"; 
    }

    ~Derived() 
    { 
        delete[] pointer;
        cout << "Derived destruct\n"; 
    }
};


int main()
{
    /*
    Cat* cat = new Cat();
    Animal* animal = new Animal();
    cat->Say();
    animal->Say();

    animal = cat;
    animal->Name();
    animal->Say();

    animal = new Dog();
    animal->Name();
    animal->Say();
    */

    /*
    Base* base = new Derived();
    delete base;
    */

    Build* build = new Build();

    delete build;

    Boss* boss = new Boss();

    Department* department = new Department(boss);
    delete department;
    
    delete boss;
}

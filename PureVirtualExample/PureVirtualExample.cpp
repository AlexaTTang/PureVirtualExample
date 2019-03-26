// PureVirtualExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//pure virtual example
#include "pch.h"
#include <cstdio>
#include <string>

// Base class
class Animal {
	std::string _name;
	std::string _type;
	std::string _sound;
	// private constructor prevents construction of base class
	Animal() {};
protected:
	// protected constructor for use by derived classes
	Animal(const std::string & n, const std::string & t, const std::string & s)
		: _name(n), _type(t), _sound(s) 
	{
		printf("Animal Constructed\n");
	}
public:
	void speak() const;
	const std::string & name() const { return _name; }
	const std::string & type() const { return _type; }
	const std::string & sound() const { return _sound; }
	std::string snap() { return "Animal_Snap"; }     //redefine same signature
	virtual std::string move() = 0;  //pure virtual function
};

void Animal::speak() const 
{
	printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal
class Dog : public Animal 
{
	int walked;
public:
	Dog(std::string n) : Animal(n, "dog", "woof"), walked(0) 
	{
		printf("Dog Constructed\n");
	};
	int walk() { return ++walked; }
	std::string snap() { return "Dog_Snap"; }    //redefine same signature but, I can still call as it was statically linked
	virtual std::string move() { return "Dog_Move"; }
};

// Cat class - derived from Animal
class Cat : public Animal 
{
	int petted;
public:
	Cat(std::string n) : Animal(n, "cat", "meow"), petted(0)
	{
		printf("Cat Constructed\n");
	};
	int pet() { return ++petted; }
	virtual std::string move() { return "Cat_Move"; }
};

class Donkey :public Animal 
{
	int carried;
public:
	Donkey(std::string n) : Animal(n, "donkey", "hee-haw"), carried(0) 
	{
		printf("Donkey constructed\n");
	};
	int carry() { return ++carried; }
	virtual std::string move() { return "Donkey_Move"; }
};

// Pig class - derived from Animal
class Pig : public Animal {
	int fed;
public:
	Pig(std::string n) : Animal(n, "pig", "oink"), fed(0) 
	{
		printf("Pig Constructed\n");
	};
	int feed() { return ++fed; }
	virtual std::string move() { return "Pig_Move"; }
};

//Poly
std::string displayName(const Animal &A)
{
	return A.name();
}


int main(int argc, char ** argv) 
{
	Dog d("Rover");
	Cat c("Fluffy");
	Pig p("Arnold");
	Donkey donk("Eeyore");

	//Poly  
	//calling a specific ANIMAL -> a derived class of base
	printf("%s\n", displayName(d).c_str());
	printf("%s\n", displayName(c).c_str());
	printf("%s\n", displayName(p).c_str());

	//d.snap()  //who get called?
	printf("%s\n", d.snap().c_str());
	printf("%s\n", d.Animal::snap().c_str());

	//virtual function calls
	printf("%s\n", d.move().c_str());
	printf("%s\n", c.move().c_str());
	printf("%s\n", p.move().c_str());


	d.speak();
	c.speak();
	p.speak();
	donk.speak();

	printf("the dog has been walked %d times\n", d.walk());
	printf("the cat has been petted %d times\n", c.pet());
	printf("the pig has been fed %d times\n", p.feed());
	printf("the Donkey has been carried %d times\n", donk.carry());
}
//
//A virtual function a member function which is declared within base class and is re - defined(Overriden) by derived class.When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the function.
//• Virtual functions ensure that the correct function is called for an object, regardless of the type of reference(or pointer) used for function call.
//• They are mainly used to achieve Runtime polymorphism
//• Functions are declared with a virtual keyword in base class.
//• The resolving of function call is done at Run - time.
//Rules for Virtual Functions
//1. They Must be declared in public section of class.
//2. Virtual functions cannot be static and also cannot be a friend function of another class.
//3. Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism.
//4. The prototype of virtual functions should be same in base as well as derived class.
//5. They are always defined in base class and overridden in derived class.It is not mandatory for derived class to override(or re - define the virtual function), in that case base class version of function is used.
//6. A class may have virtual destructor but it cannot have a virtual constructor.
//
//A pure virtual function(or abstract function) in C++ is a virtual function for which we don’t have implementation, we only declare it.A pure virtual function is declared by assigning 0 in declaration.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

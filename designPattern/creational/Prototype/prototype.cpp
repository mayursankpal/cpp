#include <iostream>
#include <string.h>

using namespace std;

// Abstract Animal class
class Animal
{
protected:
	char _hairColor[10];
	int _hairLength, _tail, _weight, _height, _age;
	int _intelligence, _stubbornness, _agressiveness;

public:
	virtual Animal *clone() = 0;

	void setHairLength(int length)
	{
		_hairLength = length;
	}

	void setHairColor(const char *color)
	{
		strncpy(_hairColor, color, (size_t) strlen(color));
	}

	void setTail(int length)
	{
		_tail = length;
	}

	void setWeight(int kg)
	{
		_weight = kg;
	}

	void setHeight(int m)
	{
		_height = m;
	}

	void setAge(int age)
	{
		_age = age;
	}

};

// Derived Sheep class
class Sheep : public Animal
{
public:
	Sheep()
	{
		_hairLength = 5;
		_stubbornness = 3;
		_agressiveness = 2;
		_intelligence = 7;
	}
	Sheep* clone()                  //IQ : Though this is vritual method return type signature does not match exactly with base class
	{
        cout << "cloning sheep using Animal" << endl;
		return new Sheep(*this);
	}
	void shearing()
	{
		_hairLength -= 2;
	}
    void features()
    {
        cout << "sheep features" << endl;
        cout << "hair length: " << _hairLength << endl;
        cout << "stubbornness: " << _stubbornness << endl;
        cout << "agressiveness: " << _agressiveness << endl;
        cout << "intelligence: " << _intelligence << endl;
        cout << endl;
    }
};

// Derived Cow class
class Cow : public Animal
{
public:
	Cow()
	{
		_stubbornness = 6;
		_agressiveness = 5;
		_intelligence = 8;
	}
	Cow* clone()                    //IQ : Though this is vritual method return type signature does not match exactly with base class
	{
        cout << "cloning cow using Animal" << endl;
		return new Cow(*this);
	}
    void features()
    {
        cout << "cow features" << endl;
        cout << "stubbornness: " << _stubbornness << endl;
        cout << "agressiveness: " << _agressiveness << endl;
        cout << "intelligence: " << _intelligence << endl;
        cout << endl;
    }
};

int main()
{
	//create initial instance of a Sheep
	Sheep* sheep0 = new Sheep;
	sheep0->setHairColor("white");
	sheep0->setTail(5);
	sheep0->setWeight(90);
	sheep0->setHeight(1);
	sheep0->setAge(5);
    sheep0->features();

	//create initial instance of a Cow
	Cow* cow0 = new Cow;
	cow0->setHairColor("brown");
	cow0->setTail(20);
	cow0->setWeight(790);
	cow0->setHeight(2);
	cow0->setAge(8);
    cow0->features();

	Animal *farm[3];

	//use cloning to populate the farm
	farm[0] = sheep0->clone();
	farm[1] = cow0->clone();

	//change a cow property
	farm[1]->setWeight(1000);

	//shear a Sheep and clone it
	sheep0->shearing();
	farm[2] = sheep0->clone();

    cout << "=================================" << endl; 
    cout << "farm animals features" << endl;
    sheep0->features();
    cow0->features();

}


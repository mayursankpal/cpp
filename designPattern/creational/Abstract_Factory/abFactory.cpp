// 04_02_AbFacImp_Start.cpp
//

//#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

//==================Door Objects==================
class Door
{
public:
	Door()
	{
	}
	virtual void Open() = 0;
};

class GasCarDoor : public Door
{
public:
	GasCarDoor()
	{
		cout << "Making a door for a gas car." << endl;
	}
	void Open()
	{
		cout << "click" << endl;
	}
};

class ElectricCarDoor : public Door
{
public:
	ElectricCarDoor()
	{
		cout << "Making a door for an electric car" << endl;
	}
	void Open()
	{
		cout << "shhhhh" << endl;
	}
};

//==================Engine objects==================
class Engine
{
protected:
	char _sound[15];
public:
	Engine()
	{
		strncpy(_sound,"",1);
		//strcpy_s(_sound, "");
	}
	virtual void Run() = 0;
};

class GasEngine : public Engine
{
public:
	GasEngine()
	{
		strncpy(_sound,"vroom",5);
		// strcpy_s(_sound, "vroom");
		cout << "Making a gas engine." << endl;
	}
	void Run()
	{
		cout << _sound << endl;
	}
};

class ElectricEngine : public Engine
{
public:
	ElectricEngine()
	{
		strncpy(_sound, "SHHHH",5);
		cout << "Making an electric engine." << endl;
	}
	void Run()
	{
		cout << _sound << endl;
	}
};

//==================Factories==================
class CarFactory
{
public:
	virtual Door* BuildDoor() = 0;
	virtual Engine* BuildEngine() = 0;
};

class GasCarFactory :public CarFactory
{
public:
	Door * BuildDoor()
	{
		return new GasCarDoor();
	}
	Engine* BuildEngine()
	{
		return new GasEngine();
	}
};

class ElectricCarFactory :public CarFactory
{
public:
	Door * BuildDoor()
	{
		return new ElectricCarDoor();
	}
	Engine* BuildEngine()
	{
		return new ElectricEngine();
	}
};

int main()
{
	CarFactory * factory = NULL;

	int choice;
	cout << "Select a car type: " << endl;
	cout << "1: Gasoline" << endl;
	cout << "2: Electric" << endl;
	cout << "Selection: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		/* code */
		factory = new GasCarFactory();
		break;

	case 2:
		/* code */
		factory = new ElectricCarFactory();
		break;

	default:
		cout<<"Invalid selection"<<endl;
		factory = NULL;
		break;
	}

	factory->BuildDoor()->Open();
	factory->BuildEngine()->Run();
	//delete factory; //this causes a crash

	cout << "Done" << endl;
	cout << endl;

}


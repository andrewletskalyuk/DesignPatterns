#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Unit abstract
{
public:
	virtual void Play() = 0;
	virtual ~Unit() {
	}
};

class Archer : public Unit
{
public:
	void Play()
	{
		cout << "Archer playing\n";
	}
};

class Mag : public Unit
{
public:
	void Play()
	{
		cout << "Mag playing\n";
	}
};

class Swardman : public Unit
{
public:
	void Play()
	{
		cout << "Swardman playing\n";
	}
};


enum Players
{
	archer = 1, mag, swardman
};


class FactoryMethod abstract
{
public:
virtual	Unit* CreateUnit()=0;
};

class FactoryMethodArcher : public FactoryMethod
{
public:
	Unit* CreateUnit()
	{
		cout << "Archer\n";
		return new Archer();
	}
};

class FactoryMethodMag : public FactoryMethod
{
public:
	Unit* CreateUnit()
	{
		cout << "Mag\n";
		return new Mag();
	}
};

class FactoryMethodSwardman : public FactoryMethod
{
public:
	Unit* CreateUnit()
	{
		cout << "Swardman\n";
		return new Swardman();
	}
};

int main()
{
	setlocale(LC_ALL, "");
	//vector <Unit*> team;

	/*while (true)
	{
		cout << "Make choice: \n";
		cout << "1 - add Archer\n";
		cout << "2 - add Mag\n";
		cout << "3 - add Swardman\n";
		cout << "0 - end\n";
		int choice = 777;
		cin >> choice;
		if (choice == archer)
		{
			team.push_back(new Archer());
		}
		else if (choice == mag)
		{
			team.push_back(new Mag());
		}
		else if (choice == swardman)
		{
			team.push_back(new Swardman());
		}
		else if (choice == 0)
		{
			break;
		}
	}

	for (auto el : team)
	{
		el->Play();
	}*/

	FactoryMethodArcher factoryMethodArcher;
	FactoryMethodMag factoryMethodMag;
	FactoryMethodSwardman factoryMethodSwardman;

	FactoryMethod* factory[] = { &factoryMethodArcher, &factoryMethodMag, &factoryMethodSwardman };

	Unit* player;

	while (true)
	{
		cout << "Make choice: \n";
		cout << "1 - add Archer\n";
		cout << "2 - add Mag\n";
		cout << "3 - add Swardman\n";
		cout << "0 - end\n";
		int choice = 777;
		cin >> choice;
		if (choice == 0 || choice > 3)
		{
			break;
		}
		else
		{
			player = factory[choice - 1]->CreateUnit();
		}
	}
	system("pause");
	return 0;
}

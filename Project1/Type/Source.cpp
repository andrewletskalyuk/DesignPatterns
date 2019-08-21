#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Unit abstract
{
public:
	virtual void Play() = 0;
	virtual Unit* Clone()=0;
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
	Unit* Clone()
	{
		return new Archer(*this);
	}
};

class Mag : public Unit
{
public:
	void Play()
	{
		cout << "Mag playing\n";
	}
	Unit* Clone()
	{
		return new Mag(*this);
	}
};

class Swardman : public Unit
{
public:
	void Play()
	{
		cout << "Swardman playing\n";
	}
	Unit* Clone()
	{
		return new Swardman(*this);
	}
};

enum Players
{
	archer = 1, mag, swardman
};

class CreatePrototype
{
	static Unit* prototypes[3];
public:
	static Unit* createPlayer(Players type)
	{
		switch (type)
		{
		case archer:
			return prototypes[type - 1]->Clone();
			break;
		case mag:
			return prototypes[type - 1]->Clone();
			break;
		case swardman:
			return prototypes[type - 1]->Clone();
			break;
		default:
			return prototypes[archer]->Clone();
			break;
		}
	}
};

Unit* CreatePrototype::prototypes[] = { new Archer(), new Mag(), new Swardman() };

int main()
{
	setlocale(LC_ALL, "");
	vector <Unit*> team2;

	while (true)
	{
		cout << "Make choice: \n";
		cout << "1 - Archer\n";
		cout << "2 - Mag\n";
		cout << "3 - Swardman\n";
		cout << "0 - end\n";
		int choice = 777;
		cin >> choice;
		if (choice!=0)
		{
			team2.push_back(CreatePrototype::createPlayer((Players)choice));
		}
		else if (choice == 0)
		{
			break;
		}
	}

	//clone 
	vector <Unit*> team1;
	for (auto i:team2)
	{
		team1.push_back(i->Clone());
	}


	system("pause");
	return 0;
}

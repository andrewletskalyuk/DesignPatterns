#include <iostream>
#include <string>
#include <map>

using namespace std;

//патерн білдер - призначений для об"єкту що складається з менших частин

class NoteBook
{
private:
	string name;
	map<string, string> mapnote;
public:
	NoteBook(string n = "Notebook") : name(n)
	{
	}
	string getPart(const string& key)
	{
		return mapnote[key];
	}
	void setPart(string key, string value)
	{
		this->mapnote[key] = value;
	}
	void Show()
	{
		cout << name << endl;
		for (auto el : mapnote)
		{
			cout << el.first << " " << el.second << endl;
		}
	}
	bool DoesThisButtonExist(string key)
	{
		return	mapnote.find(key) != mapnote.end() ? true : false;
	}
};

class NoteBookBuilder
{
protected:
	NoteBook* device;
public:
	virtual void setMemory() = 0;
	virtual void setHDD() = 0;
	virtual void setMatrix() = 0;
	virtual void setCPU() = 0;
	NoteBook* getDevice()
	{
		return this->device;
	}
};

class GameNoteBook : public NoteBookBuilder
{
public:
	GameNoteBook()
	{
		device = new NoteBook("GameNoteBook");
	}
	void setMemory()
	{
		device->setPart("memory", "16Gb");
	}
	void setHDD()
	{
		device->setPart("HDD", "1028Gb");
	}
	void setMatrix()
	{
		device->setPart("Matrix", "HP");
	}
	void setCPU()
	{
		device->setPart("CPU", "Intel");
	}
};

class HomeNoteBook : public NoteBookBuilder
{
public:
	HomeNoteBook()
	{
		device = new NoteBook("HomeNoteBook");
	}
	void setMemory()
	{
		device->setPart("memory", "8Gb");
	}
	void setHDD()
	{
		device->setPart("HDD", "256Gb");
	}
	void setMatrix()
	{
		device->setPart("Matrix", "Lenovo");
	}
	void setCPU()
	{
		device->setPart("CPU", "AMD");
	}
};

class CustomNoteBook : public NoteBookBuilder
{
public:
	CustomNoteBook()
	{
		device = new NoteBook("CustumerNoteBook");
	}
	void setMemory()
	{
		device->setPart("memory", "2Gb");
	}
	void setHDD()
	{
		device->setPart("HDD", "64Gb");
	}
	void setMatrix()
	{
		device->setPart("Matrix", "HP");
	}
	void setCPU()
	{
		device->setPart("CPU", "Celeron");
	}
	void SetYourVariant()
	{
		string temp;
		cout << "EnterCPU\n";
		cin >> temp;
		device->setPart("CPU", temp);
		//temp = nullptr;

		cout << "EnterHDD\n";
		cin >> temp;
		device->setPart("HDD", temp);
		//temp = nullptr;
		
		cout << "EnterMatrix\n";
		cin >> temp;
		device->setPart("Matrix", temp);
		//temp = nullptr;

		cout << "EnterMemory\n";
		cin >> temp;
		device->setPart("Memory", temp);
		//temp = nullptr;
	}
	void Show()
	{
		device->Show();
	}
};

class NoteBookShop
{
public:
	void CreateNoteBook(NoteBookBuilder * b)
	{
		
		b->setCPU();
		
		b->setHDD();
		
		b->setMatrix();
		
		b->setMemory();
	}
};

int main()
{
	setlocale(LC_ALL, "");

	NoteBookShop* shop = new NoteBookShop();

	NoteBookBuilder* builder = new GameNoteBook();

	shop->CreateNoteBook(builder);
	builder->getDevice()->Show();

	CustomNoteBook* custom = new CustomNoteBook();
	custom->SetYourVariant();
	custom->Show();


	system("pause");
	return 0;
}
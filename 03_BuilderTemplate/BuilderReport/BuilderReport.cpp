#include <iostream>
#include <string>
#include <map>

using namespace std;

//Програма для створення звітів.Звіт створюється у текстовому форматі або HTML.
//Зібрати звіт, який складається з 3 - х частин : назва, основна частина, дата, підпис

class Report
{
private:
	string name;
	map<string, string> we;
public:
	Report(string n = "Report") : name(n)
	{
	}
	string getPart(const string& key)
	{
		return we[key];
	}
	void setPart(string key, string value)
	{
		this->we[key] = value;
	}
	void ShowReport()
	{
		cout << name << endl;
		for (auto el : we)
		{
			cout << el.first << " " << el.second << endl;
		}
	}
};

class BuiderReport
{
protected:
	Report* report;
public:
	virtual void setName() = 0;
	virtual void setMain() = 0;
	virtual void setFooter() = 0;
	Report* getReport()
	{
		return this->report;
	}
};

class TXTReport : public BuiderReport
{
public:
	TXTReport()
	{
		report = new Report("TXT Report");
	}
	void setName()
	{
		report->setPart("Name", "first name");
	}
	void setMain()
	{
		report->setPart("main", "our main");
	}
	void setFooter()
	{
		report->setPart("Footer", " our footer");
	}
};

class HTMLReport : public BuiderReport
{
public:
	HTMLReport()
	{
		report = new Report("HTML Report ");
	}
	void setName()
	{
		report->setPart("Name", "HTMLfirst name");
	}
	void setMain()
	{
		report->setPart("Main", "HTMLour main");
	}
	void setFooter()
	{
		report->setPart("Footer", "HTMLour footer");
	}
};

class Author
{
public:
	void CreateReport(BuiderReport * b)
	{

		b->setName();

		b->setMain();

		b->setFooter();

	}
};

int main()
{
	setlocale(LC_ALL, "");

	Author* author = new Author();

	BuiderReport* buiderReport = new TXTReport();

	author->CreateReport(buiderReport);

	buiderReport->getReport()->ShowReport();

	system("pause");
	return 0;
}
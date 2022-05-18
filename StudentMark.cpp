#include <iostream>
#include <fstream>
#include <string>


using namespace std;

float mark;
string name;
string nationalcode;
fstream m;
void inputdata();
void printdata();
void Ncheck();
void checkmark();
void inputName();
int main()
{
	inputdata();
	printdata();

	return 0;
}
void inputdata()
{

	m.open("sample.txt", ios::out);
	for (int i = 1; i <= 3; i++)
	{
		inputName();
		Ncheck();
		checkmark();
	}
}

void printdata()
{
	bool find = false;
	ifstream bank("sample.txt");
	while (bank >> name)
	{
		bank >> nationalcode;
		bank >> mark;
		if (mark >= 15)
		{
			find = 1;
			cout << endl;
			cout << "Name is : " << name << "\t" << "Codemeli is : " << nationalcode << "\t" << "Moadel is :" << mark << endl;

		}

	}
	if (find = 0)
	{
		cout << "Any one can not ger mark great than 15" << endl;
	}

}

void inputName()
{
	cout << "Please enter name" << endl;
	cin >> name;
	m << name << endl;
}

void Ncheck()
{
	bool Nationalflag = 0;
	do {
		do
		{
			cout << "Please enter nationalcode" << endl;
			cin >> nationalcode;

		} while (nationalcode.length() != 10);
		int control = nationalcode[9] - 48;
		int sum = 0;
		int k = 0;

		for (int i = 0; i < 9; i++)
		{
			sum = sum + ((nationalcode[i] - 48) * (10 - i));
		}
		k = sum % 11;

		if (k < 2)
		{
			if (control == k)
			{
				//cout << "true";
				m << nationalcode << endl;
				Nationalflag = 1;
			}
			else
			{
				cout << "Your national Code is not correct" << endl;
				Nationalflag = 0;
			}
		}
		else if (control == (11 - k))
		{
			//cout << "true";
			m << nationalcode << endl;
			Nationalflag = 1;
		}
		else
		{
			cout << "Your national Code is not correct" << endl;
			Nationalflag = 0;
		}
	} while (Nationalflag != 1);
}

void checkmark()
{
	bool markFlag = 0;
	do {

		cout << "Please enter Mark" << endl;
		cin >> mark;

		if (mark < 0 || mark >20)
		{
			cout << "Your Mark should be between 0-20" << endl;
			markFlag = 0;
		}
		else
		{
			markFlag = 1;
			m << mark << endl;
		}

	 
	}while (markFlag == 0);
}
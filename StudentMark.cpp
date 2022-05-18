#include <iostream>
#include <fstream>
#include <string>


using namespace std;

float mark;
string name;
string nationalcode;
float avg;
float physicmark;
float mathmark;
float cheimsrymark;
float avgmax = 0;
fstream m;
int cs = 0;

void inputdata();
void printdata();
void Ncheck();
void checkmark();
void inputName();
int main()
{
	cout << "Please enter number of student :" <<endl;
	cin >> cs;
	inputdata();
	printdata();

	return 0;
}

void printdata()
{
	bool find = false;
	ifstream bank("sample.txt");
	while (bank >> name)
	{
		bank >> nationalcode;
		bank >> mathmark;
		bank >> physicmark;
		bank >> cheimsrymark;
		bank >> avg;
		
		if (avg > avgmax)
		{
			avgmax = avg;
			fstream h;
			h.open("sample2.txt", ios::out);
			h << name << endl;
			h << nationalcode << endl;
			h << mathmark << endl;
			h << physicmark << endl;
			h << cheimsrymark << endl;
			h << avg << endl;
		}
		if (avg >= 0)
		{
			find = 1;
			cout << endl;
			cout << "Name is : " << name << "\t" << "Codemeli is : " << nationalcode << "\t" << "Math Mark is :" << mathmark << "\t" << "Physic Mark is :" << physicmark << "\t" << "Cheimsry Mark is :" << cheimsrymark << "\t" << "AVG is :" << avg << endl;
		}
		
	}
	ifstream bank2("sample2.txt");
	{
		bank2 >> name;
		bank2 >> nationalcode;
		bank2 >> mathmark;
		bank2 >> physicmark;
		bank2 >> cheimsrymark;
		bank2 >> avg;
		cout << endl;
		cout << endl;
		cout <<"Best Student" <<endl;
		cout << "Name is : " << name << "\t" << "Math Mark is :" << mathmark << "\t" << "Physic Mark is :" << physicmark << "\t" << "Cheimsry Mark is :" << cheimsrymark << "\t" << "AVG is :" << avg << endl;
	}

	if (find = 0)
	{
		cout << "Any one can not ger mark great than 15" << endl;
	}

}
void inputdata()
{

	m.open("sample.txt", ios::out);
	for (int i = 1; i <= cs; i++)
	{
		inputName();
		Ncheck();
		checkmark();
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
	float sum = 0;
	bool markFlag = 0;
	for (int i = 1; i <= 3; i++)
	{

		do {

			cout << "Please enter Mark " << i << endl;
			cin >> mark;

			if (mark < 0 || mark >20)
			{
				cout << "Your Mark should be between 0-20" << endl;
				markFlag = 0;
			}
			else
			{
				markFlag = 1;
				if (i == 1)
				{
					mathmark = mark;
					m << mark << endl;
				}
				else if (i == 2)
				{
					physicmark = mark;
					m << mark << endl;
				}
				else if (i == 3)
				{
					cheimsrymark = mark;
					m << mark << endl;
				}

				sum = sum + mark;


			}


		} while (markFlag == 0);
		
	}
	avg = sum / 3;
	m << avg << endl;
}
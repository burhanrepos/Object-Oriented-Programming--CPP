#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#define MAX 10
enum Employ_Type { TM, TS, TL };
Employ_Type type;
class Employee {
	int eno;
	string ename;
	string cnic;
public:
	Employee(int eno = 0, string ename = "", string cnic = "") :eno(eno), ename(ename), cnic(cnic) {}
	virtual void setter()
	{
		cout << "Enter Employee No: ";
		cin >> eno;
		cin.ignore(10, '\n');
		cout << "Enter Employee Name : ";
		getline(cin, ename);
		cout << "Enter Employee CNIC : ";
		getline(cin, cnic);
	}
	virtual void getter()
	{
		cout << "Employee No : " << eno << endl;
		cout << "Employee Name : " << ename << endl;
		cout << "Employee CNIC : " << eno << endl;
	}
    Employ_Type get_type();// MEMBER OF EMPLOYEE CLASS
};
class Manager :public Employee {
	string title;
	double clubDues;
public:
	Manager(int eno = 0, string ename = "", string cnic = "", string t = "", double c = 0.0) :Employee(eno, ename, cnic), title(t), clubDues(c) {}
	void setter()
	{
		Employee::setter();
		cout << "Enter Manager Title: ";
		getline(cin, title);
		cout << "Enter Manager Club Dues : ";
		cin >> clubDues;
	}
	void getter()
	{
		cout << "----------------Manager Data -------------\n" << endl;
		Employee::getter();
		cout << "Manager Title: " << title << endl;
		cout << "Manager Club Dues : " << clubDues << endl;
	}
};
class Scientist :public Employee {
	string res_field;
	int no_of_pub;
public:
	Scientist(int eno = 0, string ename = "", string cnic = "", string r = "", double p = 0.0) :Employee(eno, ename, cnic), res_field(r), no_of_pub(p) {}
	void setter()
	{
		Employee::setter();
		cout << "Enter Scientist Research Field : ";
		getline(cin, res_field);
		cout << "Enter Scientist No of Publication : ";
		cin >> no_of_pub;
	}
	void getter()
	{
		cout << "----------------Scientist Data -------------\n" << endl;
		Employee::getter();
		cout << "Scintist Research Field: " << res_field << endl;
		cout << "Scientist No of Publication : " << no_of_pub << endl;
	}
};
class Labour :public Employee {
	string shift;
	double hrs_work;
	double hrs_rate;
public:
	Labour(int eno = 0, string ename = "", string cnic = "", string s = "", double w = 0.0, double r = 0.0) :Employee(eno, ename, cnic), shift(s), hrs_work(w), hrs_rate(r) {}
	void setter()
	{
		Employee::setter();
		int ch;
		do {
			cout << "------ Select Shift-----\n";
			cout << "1 ) Morning\n";
			cout << "2 ) Evening\n";
			cout << "Enter your choice  : ";
			cin >> ch;
			if (ch == 1)
			{
				shift = "Morning";
				break;
			}
			else if (ch == 2)
			{
				shift = "Evening";
				break;
			}
			else
				cout << "Wrong choice , Select One Please\n";
		} while (true);
		cout << "Enter Labour Hours Worked : ";
		cin >> hrs_work;
		cout << "Enter Labours Per Hour Rate : ";
		cin >> hrs_rate;
	}
	void getter()
	{
		cout << "----------------Labour Data -------------\n" << endl;
		Employee::getter();
		cout << "Labour Shift : " << shift << endl;
		cout << "Labour Hours Worked : " << hrs_work << endl;
		cout << "Labours Per Hour Rate : " << hrs_rate << endl;
	}
};
Employ_Type Employee::get_type()
{
	if (typeid(*this) == typeid(Manager))
		return TM;
	if (typeid(*this) == typeid(Scientist))
		return TS;
	if (typeid(*this) == typeid(Labour))
		return TL;
}
void Write(Employee* arr[], int nn)
{
	int size;
	cout << "Your are Writing " << nn << " Employee in File\n";
	ofstream outfile;
	outfile.open("Employee.dat", ios::trunc | ios::binary);
	if (!outfile)
	{
		cout << "Error Occured... While Writing in FIle..." << endl;
		exit(-1);
	}
	for (int i = 0; i < nn; i++)
	{
		type = arr[i]->get_type();
		outfile.write((char*)&type, sizeof(type));
		switch (type)
		{
		case TM:
			size = sizeof(Manager);
			break;
		case TS:
			size = sizeof(Scientist);
			break;
		case TL:
			size = sizeof(Labour);
			break;
		}
		outfile.write((char*)&arr[i], size);
		if (!outfile)
			cout << "Can't Write to files\n";
	}
	outfile.close();

}
void Read(Employee *arr[], int& nn)
{
	int size;
	ifstream infile; 
	infile.open("Employee.dat", ios::in | ios::binary);
	nn = 0;
	while(!infile.eof())
	{
		infile.read((char*)&type, sizeof(type));
		if (infile.eof())
			break;
		cout << "Type : " << type << endl;
		switch (type)
		{
		case TM:
			cout << "You Read Manager " << endl;
			arr[nn] = new Manager;
			size = sizeof(Manager);
			break;
		case TS:
			cout << "You Read Scientist " << endl;
			arr[nn] = new Scientist;
			size = sizeof(Scientist);
			break;
		case TL:
			cout << "You Read Labour" << endl;
			arr[nn] = new Labour;
			size = sizeof(Labour);
			break;
		}
		infile.read((char*)arr[nn], size);
		cout << endl;
		nn++;
	}
	cout << "You Read " << nn << " Employees From File\n";
	infile.close();
}
int main()
{
	int ch, ch1;
	Employee *employee[MAX];
	int e = 0;
	do
	{
		cout << "----------- Employee Management System --------------\n\n";
		cout << "1 ) Manager Detail\n\n";
		cout << "2 ) Scientist Detail\n\n";
		cout << "3 ) Labour Detail\n\n";
		cout << "4 ) Display Employees\n\n";
		cout << "5 ) Write to File\n\n";
		cout << "6 ) Read From File\n\n";
		cout << "7 ) EXIT\n\n";
		cout << "Enter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			employee[e] = new Manager();
			employee[e]->setter();
			e++;
			break;
		case 2:
			employee[e] = new Scientist();
			employee[e]->setter();
			e++;
			break;
		case 3:
			employee[e] = new Labour();
			employee[e]->setter();
			e++;
			break;
		case 4:
			cout << e << endl;
			for (int i = 0; i < e; i++)
			{
				cout << employee[i]->get_type() << endl;
				employee[i]->getter();
				
				cout << endl << endl;
			}
			break;
		case 5:
			if (e > 0)
				Write(employee, e);
			else
				cout << "Fill the array\n";
			break;
		case 6:
			Read(employee, e);
			break;
		case 7:
			exit(-1);
			break;
		}
	} while (true);
}
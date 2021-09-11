#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#define MAX 10
ofstream outFile;
ifstream inFile;
class Employee {
	int eno;
	string ename;
	string cnic;
	static int eCount;
public:
	Employee(int eno = 0, string ename = "", string cnic = "") :eno(eno), ename(ename), cnic(cnic)
	{
		eCount++;
	}
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
	static int empCount()
	{
		return eCount;
	}
	virtual ~Employee() {
		eCount--;
	};
	virtual void getter()
	{
		cout << "Employee No : " << eno << endl;
		cout << "Employee Name : " << ename << endl;
		cout << "Employee CNIC : " << cnic << endl;
	}
	virtual void write()
	{
		outFile << eno;
		outFile<< ename << endl;
		outFile<< cnic << endl;
	}
	virtual void read()
	{
		inFile >> eno;
		getline(inFile, ename);
		getline(inFile, cnic);
	}
};
class Manager :public Employee {
	string title;
	double clubDues;
	static int mCount;
public:
	Manager(int eno = 0, string ename = "", string cnic = "", string t = "", double c = 0.0) :Employee(eno, ename, cnic), title(t), clubDues(c)
	{
		mCount++;
	}
	void setter()
	{
		Employee::setter();
		cout << "Enter Manager Title: ";
		getline(cin, title);
		cout << "Enter Manager Club Dues : ";
		cin >> clubDues;
	}
	virtual ~Manager() {
		mCount --;
	};
	void getter()
	{
		cout << "----------------Manager Data -------------\n" << endl;
		Employee::getter();
		cout << "Manager Title: " << title << endl;
		cout << "Manager Club Dues : " << clubDues << endl;
	}
	static int manCount()
	{
		return mCount;
	}
	void write()
	{
		outFile << 'M';
		Employee::write();
		outFile << title << endl;
		outFile<< clubDues << endl;
	}
	void read()
	{
		Employee::read();
		getline(inFile, title);
		inFile >> clubDues;
	}
};
class Scientist :public Employee {
	string res_field;
	int no_of_pub;
	static int sCount;
public:
	Scientist(int eno = 0, string ename = "", string cnic = "", string r = "", int p = 0.0) :Employee(eno, ename, cnic), res_field(r), no_of_pub(p) 
	{
		sCount++;
	}
	void setter()
	{
		Employee::setter();
		cout << "Enter Scientist Research Field : ";
		getline(cin, res_field);
		cout << "Enter Scientist No of Publication : ";
		cin >> no_of_pub;
	}
	virtual ~Scientist() {
		sCount--;
	};
	void getter()
	{
		cout << "----------------Scientist Data -------------\n" << endl;
		Employee::getter();
		cout << "Scintist Research Field: " << res_field << endl;
		cout << "Scientist No of Publication : " << no_of_pub << endl;
	}
	static int sciCount()
	{
		return sCount;
	}
	void write()
	{
		outFile << 'S';
		Employee::write();
		outFile << res_field << endl;
		outFile << no_of_pub<< endl;
	}
	void read()
	{
		Employee::read();
		getline(inFile, res_field);
		inFile >> no_of_pub;
	}
};
class Labour :public Employee {
	string shift;
	int hrs_work;
	double hrs_rate;
	static int lCount;
public:
	Labour(int eno = 0, string ename = "", string cnic = "", string s = "", double w = 0.0, double r = 0.0) :Employee(eno, ename, cnic), shift(s), hrs_work(w), hrs_rate(r) 
	{
		lCount++;
	}
	void setter()
	{
		Employee::setter();
		int ch;
		do {
			cout << "------ Select Shift-----\n";
			cout << "1 ) Morning\n";
			cout << "2 ) Night\n";
			cout << "Enter your choice  : ";
			cin >> ch;
			if (ch == 1)
			{
				shift = "Morning";
				break;
			}
			else if (ch == 2)
			{
				shift = "Nigt";
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
	virtual ~Labour() {
		lCount--;
	};
	void getter()
	{
		cout << "----------------Labour Data -------------\n" << endl;
		Employee::getter();
		cout << "Labour Shift : " << shift << endl;
		cout << "Labour Hours Worked : " << hrs_work << endl;
		cout << "Labours Per Hour Rate : " << hrs_rate << endl;
	}
	static int labCount()
	{
		return lCount;
	}
	void write()
	{
		outFile << 'L';
		Employee::write();
		outFile << shift << endl;
		outFile << hrs_work;
		outFile<< hrs_rate;
	}
	void read()
	{
		Employee::read();
		getline(inFile, shift);
		inFile >> hrs_work;
		inFile >> hrs_rate;
	}

};
int Employee::eCount = 0;
int Manager::mCount = 0;
int Scientist::sCount = 0;
int Labour::lCount = 0;
int main()
{
	int ch;
	char ch1;
	Employee *employee[MAX];
	int e = 0;
	do
	{
		cout << "----------- Employee Management System --------------\n\n";
		cout << "1 ) Manager Detail\n\n";
		cout << "2 ) Scientist Detail\n\n";
		cout << "3 ) Labour Detail\n\n";
		cout << "4 ) Display Employees\n\n";
		cout << "5 ) Write Employee From File\n\n";
		cout << "6 ) Read Employees into File\n\n";
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
			for (int i = 0; i < e; i++)
			{
				employee[i]->getter();
				cout << endl << endl;
			}
			cout << "No of Total Employee : " << Employee::empCount() << endl;
			cout << "No of Managers : " << Manager::manCount() << endl;
			cout << "No of Scientist : " << Scientist::sciCount() << endl;
			cout << "No of Labour : " << Labour::labCount() << endl;
			break;
		case 5:
			outFile.open("employee.txt", ios::out);
			outFile << e << endl;
			for (int i = 0; i < e; i++)
			{
				employee[i]->write();
				delete employee[i];
			}
			e = 0;
			outFile.close();
			cout << "\nAll Data Save to File Successfully!!!\n";
			break;
		case 6:
			inFile.open("employee.txt", ios::in);
			inFile >> e;
			for (int i = 0; i < e; i++)
			{
				inFile >> ch1;
				switch (ch1)
				{
				case'M':
					employee[i] = new Manager();
					employee[i]->read();
					break;
				case'S':
					employee[i] = new Scientist();
					employee[i]->read();
					break;
				case'L':
					employee[i] = new Labour();
					employee[i]->read();
					break;
				default:
					cout << "\nInvalid Input...!!!\n";
				}
			}
			break;
		case 7:
			exit(-1);
			break;
		}
	} while (true);
}
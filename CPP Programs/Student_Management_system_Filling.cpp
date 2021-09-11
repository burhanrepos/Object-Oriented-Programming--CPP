#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#define MAX 70
#define SUB 3
class Student {
	int reg;
	string name;
	double average;
	double marks[SUB];
	char grade;
public:
	Student()
	{
		reg = 0;
		name = "";
		grade = ' ';
		average = 0;
		for (int i = 0; i < SUB; i++)
		{
			marks[i] = 0;
		}
	}
	void setter();
	void getter();
	void update();
	void append();
	int search(Student arr[],int n, int data);
	int getReg();
	void Swap(Student& S1, Student& S2);
};
void Student::setter()
{
	int sum = 0;
	bool flag;
	do
	{
		cout << "Enter Reg No for student For Insertion ( Reg no Must be in range of ( 1000-9999) : ";
		cin >> reg;
		if (reg >= 1000 && reg <= 9999)
			break;
		else
			cout << "!)Wrong Input ,please enter agian\n\n";
			
	} while (true);
	cin.ignore(10, '\n');
	cout << "Enter Name of Student : ";
	getline(cin, name);
	cout << "\tEnter Marks of Student\n";
	for (int j = 0; j < SUB; j++)
	{
		do
		{
			cout << "\tSubject " << j + 1 << " Marks : ";
			cin >> marks[j];
			if (marks[j] >= 0 && marks[j] <= 100)
			{
				break;
			}
			else
				cout << "Marks Range must be 0 to 100\n";
		} while (true);
		sum += marks[j];
	}
	average = sum / SUB * 1.0;
	if (average >= 80)
		grade = 'A';
	else if (average < 80 && average >= 70)
		grade = 'B';
	else if (average < 70 && average >= 60)
		grade = 'C';
	else
		grade = 'D';
}
void Student::append()
{
	int sum = 0;
	bool flag;
	do
	{
		cout << "Enter Reg No for student For Insertion ( Reg no Must be in range of ( 1000-9999) : ";
		cin >> reg;
		if (reg >= 1000 && reg <= 9999)
			break;
		else
			cout << "!)Wrong Input ,please enter agian\n\n";

	} while (true);
	cin.ignore(10, '\n');
	cout << "Enter Name of Student : ";
	getline(cin, name);
	cout << "\tEnter Marks of Student\n";
	for (int j = 0; j < SUB; j++)
	{
		do
		{
			cout << "\tSubject " << j + 1 << " Marks : ";
			cin >> marks[j];
			if (marks[j] >= 0 && marks[j] <= 100)
			{
				break;
			}
			else
				cout << "Marks Range must be 0 to 100\n";
		} while (true);
		sum += marks[j];
	}
	average = sum / SUB * 1.0;
	if (average >= 80)
		grade = 'A';
	else if (average < 80 && average >= 70)
		grade = 'B';
	else if (average < 70 && average >= 60)
		grade = 'C';
	else
		grade = 'D';
}
int Student::search(Student arr[],int n,int data)
{
	for (int i = 0; i < n; i++)
	{
		if (data == arr[i].reg)
			return i;
	}
	return -9999;
}
int Student::getReg()
{
	return reg;
}
void Student::update()
{
	bool flag;
	int sum = 0;
		cin.ignore(10, '\n');
		cout << "Enter Name of Student : ";
		getline(cin, name);
		cout << "\tEnter Marks of Student\n";
		for (int j = 0; j < SUB; j++)
		{
			do
			{
				cout << "\tSubject " << j + 1 << " Marks : ";
				cin >> marks[j];
				if (marks[j] >= 0 && marks[j] <= 100)
				{
					break;
				}
				else
					cout << "Marks Range must be 0 to 100\n";
			} while (true);
			sum += marks[j];
		}
		average = sum / SUB * 1.0;
		if (average >= 80)
			grade = 'A';
		else if (average < 80 && average >= 70)
			grade = 'B';
		else if (average < 70 && average >= 60)
			grade = 'C';
		else
			grade = 'D';
	
}
void Student::getter()
{
	cout << reg << "  " << name << " ";
	for (int i = 0; i < SUB; i++)
	{
		cout << "\t" << marks[i];
	}
	cout <<  "\t"  << average << "%" << "\t" << grade << endl << endl;
}
void Student::Swap(Student& S1,Student& S2)
{
	int r;
	string n;
	double av, g, m;
	r = S1.reg;
	S1.reg = S2.reg;
	S2.reg = r;
	n = S1.name;
	S1.name = S2.name;
	S2.name = n;
	av = S1.average;
	S1.average = S2.average;
	S2.average = av;
	g = S1.grade;
	S1.grade = S2.grade;
	S2.grade = g;
	for (int i = 0; i < SUB; i++)
	{
		m = S1.marks[i];
		S1.marks[i] = S2.marks[i];
		S2.marks[i] = m;
	}
}
void Write(Student stu[], int nn)
{
	ofstream outfile;
	outfile.open("student.dat", ios::out | ios::binary);
	if (!outfile.good())
		cout << "Error Occured .....!!\n";
	else
	{
		outfile.write(reinterpret_cast<char*>(&nn), sizeof(int));
		outfile.write(reinterpret_cast<char*>(stu), nn * sizeof(Student));
		outfile.close();
		cout << "\n\tAll Data is Saved on Disk... Successfully...!!\n";
	}
}
void Read(Student stu[], int &nn)
{
	ifstream infile;
	infile.open("student.dat", ios::in | ios::binary);
	cout << "No of Student Before Reading : " << nn << endl;
	infile.read(reinterpret_cast<char*>(&nn), sizeof(int));
	cout << "No of Student After Reading : " << nn << endl;
	infile.read(reinterpret_cast<char*>(stu),nn* sizeof(Student));
	infile.close();
	cout << "\n\tAll Data is Read on Disk... Successfully...!!\n";
}
int main()
{
	Student *student;
	student= new Student[MAX];
	int ch,n=0,reg,temp;
	do
	{
		system("cls");
		cout << "###########*******     MAIN MENU   *********############\n\n";
		cout << "1 ) Create Data Base of Student \n\n";
		cout << "2 ) Display Student Data of DataBase\n\n";
		cout << "3 ) Append Student Data in DataBase\n\n";
		cout << "4 ) Delete Student Data from DataBase\n\n";
		cout << "5 ) Sort Student Data from DataBase\n\n";
		cout << "6 ) Update Student Data from DataBase\n\n";
		cout << "7 ) Write Data to File\n\n";
		cout << "8 ) Read Data From File\n\n";
		cout << "9 ) Reset the Array\n\n";
		cout << "10 ) Exit\n\n";
		cout << "Enter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			if (n == 0)
			{
				cout << "Enter No of Student : ";
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					student[i].setter();
				}
			}
			else
				cout << "Please Reset the Array First\n";
			
			system("pause");
			break;
		case 2://display
			if (n > 0)
			{
				cout << "RegNO\tName \t\tS1\tS2\tS3\t%\tGrade\n";
				for (int i = 0; i < n; i++)
				{
					student[i].getter();
				}
			}
			else
				cout << "Please Fill the Array First\n";
			system("pause");
			break;
		case 3://insertion
			student[n++].append();
			system("pause");
			break;
		case 4://deletion
			if (n > 0)
			{
				cout << "Enter regNo to Delete : ";
				cin >> reg;
				temp = student->search(student, n, reg);
				if (temp != -9999)
				{
					for (int i = temp; i < n - 1; i++)
					{
						student[i] = student[i + 1];
					}
					n--;
				}
				else
					cout << "RegNo not exist\n";
			}
			else
				cout << "Please Fill the Array First\n";


			system("pause");
			break;
		case 5://sort
			if (n > 0)
			{
				for (int i = 0; i < n - 1; i++)
				{
					cout << "inner for :" << i << " : " << "\n";
					for (int j = i + 1; j < n; j++)
					{
						cout << "inner for :"<<i<<" : "<< j<<"\n";
						if (student[i].getReg() > student[j].getReg())
						{
							cout << "in if\n";
						//	swap(student[i], student[j]);
							student->Swap(student[i], student[j]);
						}
					}

				}
			}
			else
				cout << "Please Fill the Array First\n";
			
			system("pause");

			break;
		case 6://update
			if (n > 0)
			{
				cout << "Enter regNo to update : ";
				cin >> reg;
				temp = student->search(student, n, reg);
				if (temp != -9999)
				{
					student[temp].update();
				}
				else
					cout << "RegNo not exist\n";
			}
			else
				cout << "Please Fill the Array First\n";
			
			
			system("pause");
			break;
		case 7:
			if (n > 0)
			{
				Write(student, n);
			}
			else
				cout << "Please Fill the Array First\n";
			system("pause");

			break;
		case 8:
			student = new Student[MAX];
			n = 0;
			Read(student, n);
			system("pause");
			break;
		case 9:
			student = new Student[MAX];
			n = 0;
			break;
		case 10:
			exit(-1);
		default:
			cout << "!!!ERROR : You have Selected Wrong Choice , Kindly Select right one \n\n";
			cout << endl;
			system("pause");
		}
	} while (true);
}
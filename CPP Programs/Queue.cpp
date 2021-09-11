#include<iostream>
using namespace std;
#define MAX 5
class Queue {
	int first, cur;
	int arr[MAX];
public:
	Queue():first(-1),cur(-1){}
	void enqueue();
	int Dequeue();
	bool isEmpty();
};
void Queue::enqueue()
{
	int data;
	if (cur <MAX-1)
	{
		cout << "Enter Data to into QUEUE : ";
		cin >> data;
		if (first == -1)
		{
			arr[++first] = data;
			cur++;
		}
		else
		{
			arr[++cur] = data;
		}
	}
	else
		cout << "Overflow\n";
}
int Queue::Dequeue()
{
	int temp;
	if (first <= cur )
	{
		return arr[first++];
	}
	else
	{
		first = -1;
		cur = -1;
		return -9999;
	}
}
bool Queue::isEmpty()
{
	if (first<0)
		return true;
	else
		return false;
}
int main()
{
	Queue Q;
	int ch;
	int data;
	int temp;
	do
	{
		cout << "************  Main Menu  ***************\n";
		cout << "1 ) Enqueue\n";
		cout << "2 ) Dequeue\n";
		cout << "3 ) isEmpty\n";
		cout << "4 ) Exit\n";
		cout << "Enter your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			Q.enqueue();
			break;
		case 2:
			temp = Q.Dequeue();
			if (temp != -9999)
				cout << "Dequeued data : " << temp << endl;
			else
				cout << "UnderFlow\n";
			break;
		case 3:
			if (Q.isEmpty())
				cout << "Stack is Empty\n";
			else
				cout << "Stack is Not Empty\n";
			break;
		case 4:
			exit(-1);
			break;
		}
	} while (true);
}

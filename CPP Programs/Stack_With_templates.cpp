#include<iostream>
#include<string>
using namespace std;
#define MAX 20
template<typename T>
class Stack {
	int top;
	T arr[MAX];
public:
	Stack() {
		top = -1;
	}
	void push(T data);
	T pop();
	T peek();
	bool isEmpty();
	bool isFull();
};
template<typename T>
void Stack<T>::push(T data)
{
	if (top != MAX - 1)
	{
		top++;
		arr[top] = data;
	}
	else
		cout << "OverFlow\n";
}
template<typename T>
T Stack<T>::pop()
{
	if (top != -1)
	{
		return arr[top--];
	}
	else
		cout << "UnderFlow\n";
}
template<typename T>
T Stack<T>::peek()
{
	if (top != -1)
	{
		return arr[top];
	}
	else
	{
		cout << "Stack is Empty\n";
	}
}
template<typename T>
bool Stack<T>::isEmpty()
{
	if (top < 0)
		return true;
	else
		return false;
}
int main()
{
	Stack<string> stack;
	int ch;
	string data;
	do
	{
		cout << "************  Main Menu  ***************\n";
		cout << "1 ) Push\n";
		cout << "2 ) Pop\n";
		cout << "3 ) Peek\n";
		cout << "4 ) isEmpty\n";
		cout << "5 ) Exit\n";
		cout << "Enter your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter Data to Push in Stack : ";
			cin >> data;
			stack.push(data);
			break;
		case 2:
			if (!stack.isEmpty())
				cout << "Popped data : " << stack.pop() << endl;
			else
				cout << "Stack is Empty\n";
			break;
		case 3:
			if (!stack.isEmpty())
				cout << "Peek Data : " << stack.peek() << endl;
			else
				cout << "Stack is Empty\n";
			
			break;
		case 4:
			if (stack.isEmpty())
				cout << "Stack is Empty\n";
			else
				cout << "Stack is Not Empty\n";
			break;
		case 5:
			exit(-1);
			break;
		}
	} while (true);
}

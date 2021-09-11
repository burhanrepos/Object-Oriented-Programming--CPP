#include<iostream>
using namespace std;
struct node {
	int m;
	node *lptr, *rptr;
};
void setter(node *&head, node *&tail, node *&cur, node *&pre, int &count)
{
	char ch;
	do
	{
		cur = new node;
		cur->lptr = NULL;
		cur->rptr = NULL;
		cout << "Enter Data in List : ";
		cin >> cur->m;
		if (head == NULL)
		{
			tail = pre = head = cur;
		}
		else
		{
			tail = cur;
			pre->rptr = cur;
			cur->lptr = pre;
			pre = cur;
		}
		count = count + 1;
		cout << "Do you have another Data ( Y or N ) : ";
		cin >> ch;
		if (toupper(ch) == 'N')
			break;

	} while (true);
}
void updation(node *&head, node *&cur)
{
	char ch;
	int data;
	bool flag = false;
	cout << "Enter Data to Update : ";
	cin >> data;
	cur = head;
	while (cur)
	{
		if (cur->m == data)
		{
			cout << "Current data found, Please Enter New Data : ";
			cin >> cur->m;
			flag = true;
			break;
		}
		cur = cur->rptr;
	}
	if (!flag)
	{
		cout << "Current Data Not Found\n";
	}

}
void deletion(node *&head, node *&tail, node *&cur, node *&pre, int data, int &count)
{

	if (head->m == data)
	{
		head = head->rptr;
		
		if (head != NULL)
			head->lptr = NULL;
		cout << "in head of deletion\n";
		count--;
	}
	else
	{
		cur = pre = head;
		while (cur != NULL)
		{
			cout << "in while of delete\n";
			
			if (data == cur->m)
			{
				cout << "in if of delete\n";
				cout << "Deleted Data : " << cur->m << endl;
				pre->rptr = cur->rptr;
				if (cur->rptr == NULL)
				{
					pre->rptr = NULL;
					tail = pre;
					break;
				}
				cur->rptr->lptr = pre;
				count--;
				pre = cur;
				cur = cur->rptr;
				break;
			
			}
				pre = cur;
				cur = cur->rptr;


		}


	}
}
void sorting(node *&head, node *&tail, node *&cur, node *&pre, int count)
{
	int temp;
	pre = head;
	while (pre)
	{
		cur = pre->rptr;
		while (cur)
		{
			if (pre->m > cur->m)
			{
				temp = cur->m;
				cur->m = pre->m;
				pre->m = temp;
			}
			cur = cur->rptr;
		}
		pre = pre->rptr;
	}
}
node* min(node *head, node* tail, node *cur, node* pre)
{
	int min;
	min = head->m;
	pre = head;
	cur = head->rptr;
	while (cur)
	{
		if (min > cur->m)
		{
			min = cur->m;

			pre = cur;
		}
		cur = cur->rptr;
	}
	cout << "minimum : " << pre->m << endl;
	return pre;
}


void insertion(node *&head, node *&tail, node *&cur, node *&pre, node *newNode, int& count)
{

	if (head->m >= newNode->m)
	{
		head->lptr = newNode;
		newNode->rptr = head;
		head = newNode;
		head->lptr=NULL;
		cout << "NewNode Data is Inserted in start: " << newNode->m << endl;
		count++;
		cout << "tail " << tail->rptr << endl;
		cout << "tail " << head->rptr << endl;
	}
	else
	{
		cur = pre = head;
		while (cur != NULL)
		{
			if (newNode->m > cur->m)
			{
				pre = cur;
				cur = cur->rptr;
			}
			else
				break;

		}
		if (cur != NULL)
		{
			newNode->lptr = pre;
			pre->rptr = newNode;
			newNode->rptr = cur;
			cur->lptr = newNode;
			cout << "NewNode Data is Inserted: " << newNode->m << endl;
		}
		else
		{
			newNode->lptr = pre;
			pre->rptr = newNode;
			tail = newNode;
			cout << "NewNode Data is Inserted: " << newNode->m << endl;
		}
		count++;
	}

}

void getter(node *head, node *tail, node *cur)
{
	int ch;
	do
	{
		cout << "------------- SUB MENU -------------\n";
		cout << "1) Display in Forward Direction\n";
		cout << "2) Display in Backward Direction\n";
		cout << "2) Back to Main Menu\n";
		cout << "Enter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cur = head;
			cout << "Data : ";
			while (cur)
			{
				cout << cur->m << "   ";
				cur = cur->rptr;
			}
			cout << endl;

			break;
		case 2:
			cur = tail;
			cout << "Data : ";
			while (cur)
			{
				cout << cur->m << "   ";
				cur = cur->lptr;
			}
			cout << endl;
			break;
		case 3:
			break;
		default:
			cout << "Wrong Input \n";
		}
		if (ch == 3)
			break;
	} while (true);
}
void sort(node *&head, node *&tail, node *cur, node *pre, int count)
{
	node *newNode = NULL;
	node *newHead = NULL;
	newHead = head;
	for (int i = 1; i <= count; i++)
	{
		cout << i << " : " << count << "\n";
		newNode = new node;
		newNode->lptr = NULL;
		newNode->rptr = NULL;
		if (newHead != NULL)
		{
			newNode = min(newHead, tail, cur, pre);
		//	getter(head, tail, cur);
			deletion(head, tail, cur, pre, newNode->m, count);
		//	getter(head, tail, cur);
			insertion(head, tail, cur, pre, newNode, count);
		//	getter(head, tail, cur);
			newHead = newHead->rptr;
		}
		
	}
}
int main()
{
	node *head, *tail, *cur, *pre;
	head = tail = cur = pre = NULL;
	node *newNode = NULL;
	static int count = 0;
	int ch, data;
	do
	{
		cout << "********************    MAIN  MENU  **********************\n\n";
		cout << "1 ) Create Database of Student \n\n";
		cout << "2 ) Display Database Student \n\n";
		cout << "3 ) Insertion in Database Student \n\n";
		cout << "4 ) Deletion in Database Student \n\n";
		cout << "5 ) Updation in Database Student \n\n";
		cout << "6 ) Sorting of Database Student \n\n";
		cout << "7 ) Delete Old List\n\n";
		cout << "8 ) Exit \n\n";
		cout << "Enter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			if (head == NULL)
				setter(head, tail, cur, pre, count);
			else
				cout << "LIST already Create,Do other Operations on it!!!\n";
			break;
		case 2:
			if (head != NULL)
			{
				getter(head, tail, cur);
			}
			else
				cout << "LIST is empty!!!\n";
			break;
		case 3:
			newNode = new node;
			newNode->lptr = NULL;
			newNode->rptr = NULL;
			cout << "Enter Data in List : ";
			cin >> newNode->m;
			insertion(head, tail, cur, pre, newNode, count);
			break;
		case 4:
			if (head != NULL)
			{
				cout << "Enter Data to be Deleted : ";
				cin >> data;
				deletion(head, tail, cur, pre, data, count);
			}
			else
				cout << "LIST is empty!!!\n";
			break;
		case 5:
			if (head != NULL)
			{
				updation(head, cur);
			}
			else
				cout << "LIST is empty!!!\n";
			break;
		case 6:
			if (head != NULL)
			{
				//sorting(head, cur,pre);
				cout << count << endl;
				sort(head, tail, cur, pre,count);
			}
			else
				cout << "LIST is empty!!!\n";
			break;
		case 7:
			head = tail = cur = pre = NULL;
			count = 0;
			break;
		case 8:
			exit(-1);
			break;
		}
	} while (true);
}
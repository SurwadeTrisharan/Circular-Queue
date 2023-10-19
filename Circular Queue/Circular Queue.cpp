#include<iostream>
using namespace std;
#define MAX 8
int cqueue[MAX];
int front = -1;
int rear = -1;

void enqueue(int item)
{
	if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
	{
		cout << "The circular queue is full" << endl;
		return;
	}
	if (front == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		if (rear == MAX - 1)
			rear = 0;
		else
			rear++;
	}
	cqueue[rear] = item;
}

int dequeue()
{
	int item;
	if (front == -1)
	{
		cout << "The circular queue is empty" << endl;
		return -1;
	}
	item = cqueue[front];
	if (front == rear)
	{
		front = rear = -1;
	}
	else
		if (front == MAX - 1)
			front = 0;
		else
			front++;
		return(item);
}

void display()
{
	int i;
	if (front == -1)
	{
		cout << "The Circular Queue is empty" << endl;
		return;
	}
	cout << "The elements of cqueue is" << endl;
	if (front <= rear)
		for (i = front; i <= rear; i++)
			cout << cqueue[i] << endl;
	else
	{
		for(i = front; i <= MAX - 1; i++)
			cout << cqueue[i] << endl;
			for (i = 0; i <= rear; i++)
				cout << cqueue[i] << endl;
	}
	return;
}

int main()
{
	int value, choice;
	do
	{
		cout << "Enter 1.Enqueue 2.Dequeue 3.Display 4.Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "Enter the element to Enqueue" << endl;
			cin >> value;
			enqueue(value);
			break;
		case 2:value = dequeue();
			cout << "The value deleted is: " <<value<< endl;
			break;
		case 3:display();
			break;
		default:cout << "Exiting";
			choice = 4;
		}
	} while (choice != 4);
}
#include <iostream>
using namespace std;
class Node
{
public:
	Node(int n)
	{
		data = n;
		next = nullptr;
	};
	Node(){};
	int data;
	Node *next;
};
class Queue
{
public:
	Queue();
	~Queue();
	bool isEmpty();
	int getLength();
	void Enqueue(int val);
	void DeQueue(int &val);
	void Print();

private:
	Node *front; //首指针和尾指针
	Node *rear;
};

Queue::Queue()
{
	front = rear = nullptr;
}

Queue::~Queue()
{
	Node *temp = new Node;
	while (front)
	{
		temp = front->next;
		delete front;
		front = temp;
	}
}

bool Queue::isEmpty()
{
	return front == rear;
}

int Queue::getLength()
{
	int num = 0;
	Node *temp = front;
	while (temp)
	{
		temp = temp->next;
		num++;
	}
	return num;
}

void Queue::Enqueue(int val)
{
	Node *temp = new Node(val);
	if (front == nullptr)
	{
		//考虑为空
		front = rear = temp;
	}

	rear->next = temp;
	rear = temp;
}

void Queue::DeQueue(int &val)
{
	if (!front) // 队列为空
	{
		rear = nullptr;
		val = -1;
		return;
	}

	val = front->data; // front指向的是首节点
	Node *temp = front;
	front = front->next;
	delete temp;
}

void Queue::Print()
{
	if (!front)
	{
		cout << "NULL" << endl;
		return;
	}
	Node *temp = front;

	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Queue a;
	int b;
	a.Enqueue(1);
	a.Enqueue(3);

	a.Print();

	cout << "Length:" << a.getLength() << endl;

	a.DeQueue(b);
	cout << "出队:" << b << endl;
	a.DeQueue(b);
	cout << "出队:" << b << endl;
	a.Print();
	cout << "Length:" << a.getLength() << endl;
}

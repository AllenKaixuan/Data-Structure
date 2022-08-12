/*
用数组实现一个栈
*/
#include <iostream>
using namespace std;

class Stack
{
public:
    Stack(int size);
    ~Stack();
    int push(int x);
    int pop(int *x);
    int getTop();
    int isEmpty() const;
    int isFull() const;
    int size() const;

private:
    int MAX; //栈的最大存储容量
    int top;
    int *stk; // 指向起始地址的指针
};

Stack::Stack(int size)
{
    MAX = size;
    stk = new int[MAX];
    top = -1;
}

Stack::~Stack()
{
    delete stk;
}

int Stack::push(int x)
{
    if (top >= MAX - 1)
        return 0; // 栈满了

    top++;
    stk[top] = x;
    return 1;
}

int Stack::pop(int *x)
{
    if (top == -1)
        return 0; // 栈空了
    *x = stk[top];
    top--;
    return 1;
}

int Stack::getTop()
{
    if (top == -1)
        return NULL;
    return stk[top];
}

int Stack::isEmpty() const
{
    return top == -1;
}
int Stack::isFull() const
{
    return top == MAX-1;
}

int Stack::size() const
{
    return top;  // 返回当前容量
}

int main()
{

	Stack s(20) ;
	cout << "是否为空栈" << s.isEmpty() << endl;
	s.push(100);
	cout << "100入栈" << endl;
	s.push(50);
	cout << "50入栈" << endl;
	s.push(10);
	cout << "10入栈" << endl;
	cout <<"栈的大小"<< s.size() << endl;
	int x = 0;
	s.pop(&x);
	cout <<"弹出的元素"<< x << endl;
	cout <<"弹出一个元素后栈的大小"<< s.size()<<endl;
	cout << "栈顶元素" << s.getTop() << endl;
	return 0;
}
/*
一个基础单向链表结构的实现，只有首指针，没有头节点和尾指针，因此空链表没有节点，
只有首指针为空；
*/
#include <iostream>
using namespace std;
template <class T>
class Chain; // 前置声明链表类，此处不能指定类型，在后面指定

template <class T>
class ChainNode
{
public:
    friend Chain<T>;

private:
    T data;
    ChainNode<T> *link;
};

template <class T>
class Chain
{
public:
    Chain() { first = nullptr; };
    ~Chain();
    bool IsEmpty() { return first == nullptr; }
    int Length() const;
    bool Find(int k, T &x) const; // 寻找第k个元素，将值返回到x中
    int Search(const T &x) const; // 给定元素，返回索引
    Chain<T> &Delete(int k, T &x);
    Chain<T> &Insert(int k, const T &x);
    void Output(ostream &out) const;

private:
    ChainNode<T> *first; // 首指针
};

template <class T>
Chain<T>::~Chain()
{
    ChainNode<T> *temp; //临时变量
    while (first)
    {
        temp = first->link;
        delete first;
        first = temp;
    }
}

template <class T>
int Chain<T>::Length() const
{
    ChainNode<T> *current = first;
    int len = 0;
    while (current)
    {
        len++;
        current = current->link;
    }
    return len;
}

template <class T>
bool Chain<T>::Find(int k, T &x) const
{
    if (k < 1) // 目标非法，k过小
        return false;
    // 目标合法，且存在
    ChainNode<T> *current = first;
    int index = 1;
    while (index < k && current) // current所指的为第k个节点，first指向的为第一个节点
    {
        current = current->link;
        index++;
    }
    if (current)
    {
        x = current->data;
        return true;
    }
    return false; //目标非法，k过大
}

template <class T>
int Chain<T>::Search(const T &x) const
{
    ChainNode<T> *current = first;
    int index = 1;
    while (current && current->data != x)
    {
        current = current->link;
        index++;
    }
    if (current)
        return index;
    return -1; // 不存在这个变量，返回-1
}

template <class T>
void Chain<T>::Output(ostream &out) const
{
    ChainNode<T> *current;
    for (current = first; current; current = current->link)
        out << current->data << " ";
}

template <class T>
ostream &operator<<(ostream &out, const Chain<T> &x) // 调用成员函数实现操作符重载，也可以使用友元函数
{
    x.Output(out);
    return out;
}

template <class T>
Chain<T> &Chain<T>::Delete(int k, T &x)
{
    if (k < 1 || !first)
        return *this;            // 目标非法，过小或链表为空，返回原来的链表
    ChainNode<T> *temp2 = first; // 首先找到删除节点的前驱节点
    if (k == 1)
        first = first->link; // 如果删除的是头节点，直接另首指针指向下一个节点
    else
    {
        ChainNode<T> *temp1 = first;
        for (int index = 1; index < k - 1 && temp1; index++)
            temp1 = temp1->link; // temp1 为前驱节点
        if (!temp1 || !temp1->link)
            return *this;    // 目标非法，删除的节点超出范围
        temp2 = temp1->link; // temp2为要删除的节点
        temp1->link = temp2->link;
    }
    x = temp2->data;
    delete temp2;
    return *this;
}

template <class T>
Chain<T> &Chain<T>::Insert(int k, const T &x)
{
    if (k < 0)
        return *this; // 目标非法，过小
    ChainNode<T> *temp = first;
    for (int index = 1; index < k && temp; index++)
        temp = temp->link; // temp为第k个节点
    if (k > 0 && !temp)
        return *this; //目标非法，过大
    ChainNode<T> *insertNode = new ChainNode<T>;
    insertNode->data = x;
    if (k) //插入到表中或表后
    {
        insertNode->link = temp->link; // 新节点指向k+1个节点
        temp->link = insertNode;       // k个节点指向新节点，顺序不能反
    }
    else // 插入到表头
    {
        insertNode->link = first; // 新节点指向首指针，当插入的是空链表时首指针为0，相当于插入了第一个节点
        first = insertNode;       //调整首指针，首指针指向首节点
    }
    return *this;
}

int main()
{
    Chain<int> list;
    for (int i = 0; i < 5; i++)
    {
        list.Insert(i, i);
    }
    cout << list << endl;
    int x;
    list.Delete(3, x);
    cout << list << " delete:" << x;
}

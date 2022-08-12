#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int id;
    string name;
    Node *next = nullptr; //可以每次创建新节点默认为nullptr，
                          //或者创建节点的时候令其等于head（nullptr）,或者每次声明尾节点为nullptr
};

class List
{
public:
    List();
    ~List(){};
    List &insert(int a, string s);
    List &append(int a, string s);
    void Print();

private:
    Node *head;
    Node *tail;
};

List::List()
{
    head = tail = nullptr;
}

List &List::insert(int a, string s)
{

    Node *temp = new Node;
    temp->id = a;
    temp->name = s;

    if (head == nullptr)
    { // 链表为空
        head = tail = temp;
        // tail->next = nullptr;   //可能需要加尾节点指向空
        return *this;
    }
    if (tail->id < a) //插在尾部
    {
        tail->next = temp;
        tail = temp;
        // tail->next = nullptr;
        return *this;
    }
    else if (head->id > a) //插在头部
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        Node *temp_1 = head;
        while (temp_1 != tail)
        {
            if (temp_1->id < a && temp_1->next->id > a) // 插在表中
            {
                temp->next = temp_1->next;
                temp_1->next = temp;
            }
            temp_1 = temp_1->next;
        }
    }

    return *this;
}

List &List::append(int a, string s)
{
    Node *temp = new Node;
    temp->id = a;
    temp->name = s;
    if (head)
    {
        tail->next = temp;
        temp = tail;
    }
    else
    {
        head = tail = temp;
    }
    return *this;
}

void List::Print()
{
    if (!head)
    {
        cout << "empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp)
    {

        cout << temp->name << endl;
        temp = temp->next;
    }
}

int main()
{

    List a;
    int temp_1;
    string temp_2;
    for (size_t i = 0; i < 3; i++)
    {
        cin >> temp_1 >> temp_2;
        a.insert(temp_1, temp_2);
    }
    // a.append(9,"fu");

    a.Print();
}
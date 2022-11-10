#include <iostream>
#include <time.h>
#include<vector>
#include <windows.h>
#include<algorithm>
using namespace std;

class BST
{
    int data;
    BST* left, * right;

public:
    BST();
    BST(int);
    BST* Insert(BST*, int);
    BST* Delete(BST*, int);
    void Inorder(BST*);

};

BST::BST() : data(0), left(NULL), right(NULL)
{
}

BST::BST(int value)
{
    data = value;
    left = right = NULL;
}

BST* BST::Insert(BST* root, int value)
{
    if (!root)
    {
        root = new BST(value);
        return root;
    }


    if (value > root->data) // 递归插入右子树
    {
        root->right = Insert(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = Insert(root->left, value);
    }
    else if (value == root->data)
    {
        return root; // 插入失败
    }
    return root;
}

BST* BST::Delete(BST* root, int value)
{
    BST* temp = new BST(); // temp是要删除的节点
    BST* tempp = new BST(); // 记录temp的父节点
    temp = root;
    while (temp && temp->data != value)
    {
        tempp = temp;
        if (temp->data < value)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    if (!temp)
        return root; //   1.未找到
    if (temp->left && temp->right)  // 2.删除的节点有左右子树
    {
        BST* s = temp->left, * ps = temp; // ps为temp父节点
        while (s->right)  //寻找左子树的最右节点（左子树中最大值）  
        {
            ps = s;
            s = s->right;
        }
        temp->data = s->data; // 交换节点
        temp = s;
        tempp = ps;
    }
    BST* c;
    if (temp->left)  // 3.删除节点只有一个叶节点，c保存着删除节点的子节点
        c = temp->left;
    else
        c = temp->right;

    if (temp == root) // 3.1删除的节点为根节点
        root = c;
    else           //3.2删除的节点为中间节点，则判断其为左子节点/右子节点
    {
        if (temp == tempp->left)
            tempp->left = c;
        else
            tempp->right = c;

    }
    delete temp;  // 将temp节点删除，包含4.删除节点为叶节点
    return root;

}

// 中序遍历
void BST::Inorder(BST* root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}


int main()
{
    int number = 100000;
    BST b, * root = NULL;
    vector<int> sequence;
    for (int i = 0; i < number; i++)
        sequence.push_back(i);
    random_shuffle(sequence.begin(), sequence.end());
    //插入测试
    time_t now1, test_time1;
    now1 = clock();
    for (int i = 0; i < number; i++)
    {
        root = b.Insert(root, sequence[i]);
    }
    test_time1 = clock();
    double endtime1 = (double)(test_time1 - now1)*1000;
    cout << "Insert 10000 numbers costs:" << endtime1 << "us" << endl;
    //删除测试
    time_t now2, test_time2;
    random_shuffle(sequence.begin(), sequence.end());  // 需要再次打乱
    now2 = clock();
    for (int i = 0; i < number; i++)
    {
        root = b.Delete(root, sequence[i]);
    }
    test_time2 = clock();
    double endtime2 = (double)(test_time2 - now2) * 1000;
    cout << "Delete 10000 numbers costs:" << endtime2 << "us" << endl;

    return 0;

}


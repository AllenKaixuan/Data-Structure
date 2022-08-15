/*
并查集结构，维护不相交的集合，每个集合有他的代表元素；
类似于离散数学中等价关系的划分；
1.初始化所有元素均属于不同的集合，挑一个元素作为代表,
即初始化根节点
2.查看是否有两个集合的代表相同，有则合并
使用的结构：
1.array: parent[],parent[i] = item, item是i的父亲
这样就创建了很多树
2.tree：每棵树都有一个代表元素满足parent[i] = i,也就
是根节点；每颗树代表着一个集合
操作：
1.Find:递归遍历parent数组，直到根节点;可以压缩树高来
改进，用一个缓存机制将递归中间结果直接放在根节点下
2.union：将找到的一棵树放到另一颗树下，合并集合；若
将A作为B的子集，parent[A] = B
使用rank数组改进：rank[i] = height，union时根据rank
大小操作，类似于AVL，缩小树高
*/
#include <iostream>
using namespace std;
class DisjSet
{
    int *rank, *parent, n;

public:
    DisjSet(int n);
    void makeSet();
    int find(int x);
    void Union(int x, int y);
};

DisjSet::DisjSet(int n)
{
    rank = new int[n];
    parent = new int[n];
    this->n = n;
    makeSet();
}

void DisjSet::makeSet()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}

int DisjSet::find(int x)
{
    if (parent[x] == x)
        return parent[x];
    else
    {
        int result = find(parent[x]);
        parent[x] = result; // 调整树高
        return result;
    }
}

void DisjSet::Union(int x, int y)
{
    int xset = find(x);
    int yset = find(y);
    if (xset == yset)
        return;

    if (rank[xset] < rank[yset])
    {
        parent[xset] = yset;
    }
    else if (rank[xset] > rank[yset])
    {
        parent[yset] = xset;
    }

    else
    {
        parent[yset] = xset;
        rank[xset] = rank[xset] + 1;
    }
}
int main()
{
    DisjSet obj(5);
    obj.Union(0, 2);
    obj.Union(4, 2);
    obj.Union(3, 1);
    if (obj.find(4) == obj.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (obj.find(1) == obj.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
 
    return 0;
}
/*
图常用的存储结构为：
1.邻接链表:一个数组表示顶点，每个元素都是一组链表（使用vector代替）的开端
  只需要知道图的顶点，向顶点添加边即可
2.邻接矩阵:二维矩阵，有边则两个定点双向索引变为1
*/
#include <iostream>
#include <vector>
using namespace std;
void adjacencyMatrix(int n, int m, int **&adjMat) // n是顶点个数，m是边数,注意需要传值引用
{
    adjMat = new int *[n + 1]; // 简化索引
    for (int i = 0; i < n + 1; i++)
    {
        adjMat[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            adjMat[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
}

// 领接链表
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v) {
        cout << "\n Adjacency list of vertex " << v
             << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}

int main()
{
    int **mat, n = 4, m = 2;

    adjacencyMatrix(n, m, mat);
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout.width(3);
            cout << mat[i][j];
        }
        cout << endl;
    }
}

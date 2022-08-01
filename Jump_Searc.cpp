/*
以固定步长搜索排序的数组，然后定位局部区域，使用线性探查；
性能比较：linear search  <  jump search  <  binary search;
需要做的比较次数为：((n/m) + m-1) ，当 m = √n时代价最小（n为数组长度，m为步长）;
时间复杂度为O(√ n)，但是在搜索值是最大或最小值时，比二分搜索效率高
*/
#include <iostream>
#include <math.h>
using namespace std;
int jumpSearch(int arr[], int n, int x)
{
    int step = sqrt(n);
    int start = 0;
    // for (int i = 0; i < n; i += step-1) // 当数组容量不能刚好分开时会导致遗漏
    // {
    //     if (arr[i] > x)
    //     {
    //         start = i - step;
    //         break;
    //     }
    //     else if (arr[i] == x)
    //         return i;
    // }
    while (arr[min(step, n) - 1] < x) // 当第一个step大于时，start=0，从头找(注意索引)
    {
        start = step;
        step += sqrt(n);
        if (start >= n)
            return -1;
    }

    for (int i = start; i < min(start + step, n); i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << jumpSearch(arr, n, target);
    return 0;
}
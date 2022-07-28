/*
将数组分为三部分，时间复杂度降低一些，O(log n base 3)，当然
操作数组也依然是已排序的。
*/
#include <iostream>
using namespace std;
// 递归版本
int TenarySearchRecursive(int *a, int l, int r, int target)
{
    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;
    if (r < l)
        return -1;
    else if (a[mid1] == target)
        return mid1;
    else if (a[mid2] == target)
        return mid2;
    else if (a[mid1] > target)
        return TenarySearchRecursive(a, l, mid1 - 1, target);
    else if (a[mid2] < target)
        return TenarySearchRecursive(a, mid2 + 1, r, target);
    else
        return TenarySearchRecursive(a, mid1 + 1, mid2 - 1, target);
}

// 迭代版本
int TenarySearch(int *a, int l, int r, int target)
{
    while (l <= r)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (target == a[mid1])
            return mid1;
        else if (target == a[mid2])
            return mid2;
        else if (target < mid1)
            r = mid1 - 1;
        else if (target > mid2)
            l = mid2 + 1;
        else
        {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    int n = sizeof(a) / sizeof(a[0]);
    cout << TenarySearchRecursive(a, 0, n - 1, target) << endl;
    cout << TenarySearch(a, 0, n - 1, target) << endl;
}
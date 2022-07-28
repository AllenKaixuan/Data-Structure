/*
二分查找是应用于已排序的数组，每次将查找的范围减半，将
时间复杂度由O(n)降为O(Log n)
*/
#include <iostream>
using namespace std;
// 迭代版本写法
int BinarySearch(int *a, int n, int target)
{
    int r = n - 1, l = 0, mid = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (target == a[mid])
            return mid;
        else if (target < a[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}
// 递归版本写法
int BinarySearchRecursive(int *a, int l, int r, int target)
{
    if (l > r)
        return -1;
    else
    {
        int mid = l + (r - l) / 2;  // 这样写可以避免l+r太大，超出int表示范围
        if (a[mid] == target)
            return mid;
        else if (a[mid] > target)
            return BinarySearchRecursive(a, l, mid - 1, target);
        else
            return BinarySearchRecursive(a, mid + 1, r, target);
    }
}
int main()
{
    int a[5] = {0, 2, 3, 5, 67};
    int target = 5;
    int n = sizeof(a) / sizeof(a[0]);
    cout << BinarySearch(a, n, target) << endl;
    cout << BinarySearchRecursive(a, 0, n - 1, target);
    return 0;
}
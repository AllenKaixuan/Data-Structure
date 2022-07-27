/*
时间复杂度为O(n)，辅助空间为O(1)
*/
#include <iostream>
using namespace std;
int search(int array[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == x)

            return i;
    }
    return -1;
}

// 优化：从两边向中间查找，只是改善最差的结果，时间复杂度不变

int search_optimized(int array[], int n, int x)
{
    int left = 0;
    int length = n;
    int right = length - 1;
    for (left = 0; left <= right;)
    {
        if (array[left] == x)

            return left;

        if (array[right] == x)

            return right;

        left++; // left记录了进行了几次寻找，position则是返回
        right--;
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    int x = 5;
    int n = sizeof(array) / sizeof(array[0]);
    // int result = search(array, n, x);
    int result = search_optimized(array, n, x);
    (result == -1) ? cout << "not in array" : cout << "index is:" << result;
    return 0;
}
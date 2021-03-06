#include<iostream>
#include<algorithm>
using namespace std;

int BiSearch(int* a, int len, int w)            //修改的二分查找，返回数组元素需要插入的位置
{
    int left = 0, right = len - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (a[mid] < w)
            left = mid + 1;
        else if(a[mid]>w)
            right = mid - 1;
        else
            return mid;
    }
    return left;            //数组中不存在该元素，则返回该元素应该插入的位置
}
int LIS(int *a, int n)
{
    int len = 1;
    int* MaxV=new int[n];
    MaxV[0] = a[0];
    int pos = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > MaxV[len - 1])
        {
            MaxV[len] = a[i];
            len++;
        }
        else{
            pos = BiSearch(MaxV, len, a[i]);
            MaxV[pos] = a[i];
        }
    }
    return len;
}
int main()
{
    int n;
    while (cin >> n)
    {
        int* a = new int[n];
        for (int i = 0; i != n; i++)
            cin >> a[i];
        if (n == 1)
            cout << 1 << endl;
        else
            cout << LIS(a, n) << endl;
    }
    
    return 0;
}

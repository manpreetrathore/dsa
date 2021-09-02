#include <bits/stdc++.h>
using namespace std;

int searchInRA(int a[], int k, int l, int r)
{
    if (l > r)
    {
        return -1;
    }
    int mid = (l + r) / 2;
    if (mid == k)
    {
        return mid;
    }
    if (a[l] <= a[mid])
    {
        if (k >= a[l] && k <= a[mid])
        {
            return searchInRA(a, l, l, mid + 1);
        }
        return searchInRA(a, k, mid + 1, r);
    }
    if (k >= a[mid] && k <= a[r])
    {
        return searchInRA(a, k, mid + 1, r);
    }
    return searchInRA(a, k, l, mid - 1);
}

int main()
{
    int a[] = {6, 7, 8, 9, 10, 1, 2, 5};
    int n = 8;
    int k = 10;
    cout << searchInRA(a, k, 0, n - 1) << endl;

    return 0;
}

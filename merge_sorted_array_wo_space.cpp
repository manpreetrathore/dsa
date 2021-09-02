#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0,k=n-1;
    while (i <= k and j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            
            arr1[k] = arr1[k] ^ arr2[j];
            arr2[j] = arr1[k] ^ arr2[j];
            arr1[k] = arr1[k] ^ arr2[j];
            j++;k--;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < m; i++)
        {

            cin >> arr2[i];
        }
        merge(arr1, arr2, n, m);
    }
}
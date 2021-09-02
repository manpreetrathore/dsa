#include <bits/stdc++.h>
using namespace std;

int smallestSubarrayWithSum(int a[], int n, int x)
{
    int sum = 0, miniLength = n + 1, start = 0, end = 0;
    while (end < n)
           {
               while (sum <= x && end < n)
               {
                   sum += a[end++];
               }
               while (sum > x && start < n)
               {
                   if (end - start < miniLength)
                   {
                       miniLength = end-start;
                   }
                   sum -= a[start++];
               }
           }
    return miniLength;
}

int main(){
    int a[] = {1,4,45,6,10,19};
    int x=51;
    int n=6;
    int miniLength = smallestSubarrayWithSum(a,n,x);
    if(miniLength==n+1){
        cout<<"No subarray "<<endl;
    }
    else{
        cout<<miniLength<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int knapsack(int value[], int w[], int n, int W){
    if(n==0 || W==0){
        return 0;
    }
    if(w[n-1]>W){
        return knapsack(value,w,n-1,W);
    }
    return max(knapsack(value,w,n-1,W-w[n-1])+value[n-1],knapsack(value,w,n-1,W));
}

int main(){
    int w[] = {10,20,30};
    int value[] = {100,50,150};
    int W=50;
    cout<<knapsack(value,w,3,W)<<endl;
    return 0;
}
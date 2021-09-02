#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int dp[N];

int lis(vector<int> &a, int n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = 1; // single element is also a lis
    for (int i = 0; i < n; i++)
    {
        if (a[n] > a[i])
        {
            dp[n] = max(dp[n], 1 + lis(a, i)); // lis(a,i) is where we apply memoization and recursion.
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++)
    {
        dp[i] = -1;
    }
    vector<int> dp(n, 1);
    int ans = 0;
    // tabulation method code
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

    // cout << lis(a, n - 1) << endl; // memoization method code
    return 0;
}
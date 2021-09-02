#include <bits/stdc++.h>
using namespace std;
int dp[205][205][205];
int lcs(string &s1, string &s2, string &s3, int n, int m, int k)
{
    if (n == 0 || m == 0 || k == 0)
    {
        return 0;
    }
    if (dp[n][m][k] != -1)
    {
        return dp[n][m][k]; // memoization step
    }
    if (s1[n - 1] == s2[m - 1] and s2[m - 1] == s3[k - 1])
    {
        return dp[n][m][k]=1 + lcs(s1, s2, s3, n - 1, m - 1, k - 1);
    }

    int l = lcs(s1, s2, s3, n - 1, m, k);
    int p = lcs(s1, s2, s3, n, m - 1, k);
    int r = lcs(s1, s2, s3, n, m, k - 1);

    return dp[n][m][k]=max(max(l, p), r);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << lcs(s1, s2, s3, s1.size(), s2.size(), s3.size()) << endl;
}
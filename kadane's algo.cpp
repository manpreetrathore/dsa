#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    int curr = 0;
    int maxTillNow = 0;
    for (int i = 0; i < a.size(); i++)
    {

        curr += a[i];
        maxTillNow = max(maxTillNow, curr);
        if (curr < 0)
        {
            curr = 0;
        }
    }
    cout << maxTillNow;
}
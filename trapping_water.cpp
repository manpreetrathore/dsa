#include <bits/stdc++.h>
using namespace std;

int trap_water(vector<int> a)
{
    stack<int> st;
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and a[st.top()] < a[i])
        {
            int cur = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }
            int diff = i - st.top() - 1;
            ans += (min(a[st.top()], a[i]) - a[cur]) * diff;
        }
        st.push(i);
    }
    return ans;
}
// [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]

int main()
{
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap_water(a) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void subsequence(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string res = s.substr(1);
    cout << "----" << res << " " << ch << " " << ans << "---";
    subsequence(res, ans);
    subsequence(res, ans + ch);
    // subsequence(res, ans+to_string(code));
}
int main()
{
    subsequence("abc", "");
    return 0;
}
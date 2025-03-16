#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t)
{
    int x = 0, y = 0;
    int count = 0;
    while (y < t.size())
    {
        if (s[x] == t[y])
        {
            count++;
            x++;
        }
        y++;
    }
    if (count == s.size())
        return true;
    return false;
}
int main()
{
    string s = "abc";
    string t = "ahbgdz";
    cout << isSubsequence(s, t) << endl;
}
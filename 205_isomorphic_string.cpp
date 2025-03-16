#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isIsomorphic(string s, string t)
{
    int n = s.size();
    if (n != t.size())
        return false;

    int s_map[129] = {0};
    int t_map[129] = {0};

    for (int i = 0; i < n; i++)
    {
        if (s_map[s[i]] != t_map[t[i]])
            return false;
        s_map[s[i]] = i + 1;
        t_map[t[i]] = i + 1;
    }
    return true;
}
int main()
{
    string s = "egg";
    string t = "adc";
    cout << isIsomorphic(s, t) << endl;
}
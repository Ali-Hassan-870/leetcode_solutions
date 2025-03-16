#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    int map[26] = {0};
    for (auto s_char : s)
        map[s_char - 'a']++;

    for (auto t_char : t)
    {
        if (map[t_char - 'a'] <= 0)
            return false;
        map[t_char - 'a']--;
    }
    return true;
}
int main()
{
    string s = "rat";
    string t = "car";
    cout << isAnagram(s, t) << endl;
}
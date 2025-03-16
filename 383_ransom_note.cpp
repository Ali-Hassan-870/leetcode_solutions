#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    vector<int> map(26, 0);
    for (auto c : magazine)
        map[c - 'a']++;

    for (auto c : ransomNote)
    {
        if (map[c - 'a'] <= 0)
            return false;
        map[c - 'a']--;
    }
    return true;
}

int main()
{
    string ransomNote = "aa";
    string magazine = "aa";
    cout << canConstruct(ransomNote, magazine) << endl;
}
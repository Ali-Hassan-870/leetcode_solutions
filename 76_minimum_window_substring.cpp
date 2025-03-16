#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string minWindow(string s, string t)
{
    vector<int> hash_map(58, 0);

    for (auto c : t)
        hash_map[c - 'A']++;

    int left = 0, right = 0, head = 0, min_len = INT32_MAX;
    int count = t.size();

    while (right < s.size())
    {
        if (hash_map[s[right] - 'A'] > 0)
            count--;
        hash_map[s[right] - 'A']--;
        right++;

        while (count == 0)
        {
            if (right - left < min_len)
            {
                head = left;
                min_len = right - left;
            }
            hash_map[s[left] - 'A']++;
            if (hash_map[s[left] - 'A'] > 0)
                count++;
            left++;
        }
    }
    return min_len == INT32_MAX ? "" : s.substr(head, min_len);
}

int main()
{
    string s = "ADOBECODEBANCZ";
    string t = "ABC";
    cout << minWindow(s, t) << endl;
}
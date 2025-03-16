#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

/*Using unordered_map*/
int lengthOfLongestSubstring1(string s)
{
    unordered_map<char, bool> char_hash;
    int left = 0;
    int right = 0;
    int max_len = INT32_MIN;

    while (right < s.size())
    {
        if (char_hash.count(s[right]))
        {
            max_len = max(max_len, right - left);
            left++;
            right = left;
            char_hash.clear();
        }
        char_hash[s[right]] = true;
        right++;
    }
    return max(max_len, right - left);
}

/*Using unordered set*/
int lengthOfLongestSubstring(string s)
{
    unordered_set<char> char_set;
    int left = 0;
    int right = 0;
    int max_len = 0;

    while (right < s.size())
    {
        if (char_set.count(s[right]))
        {
            while (char_set.count(s[right]))
                char_set.erase(s[left++]);
        }
        char_set.insert(s[right]);
        max_len = max(max_len, right - left);
        right++;
    }
    return max_len;
}
int main()
{
    string input = "abcdefg";
    cout << lengthOfLongestSubstring(input) << endl;
}
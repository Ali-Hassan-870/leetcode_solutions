#include <algorithm>
#include <iostream>

using namespace std;

/*Time O(n) and space O(1).
The strings in C++ are mutable so i means we also solve it in-place and our space complexity becomes O(1). In this method we first reverse the entire string s and then reverse the individual word. */

string reverseWords(string &s)
{
    reverse(s.begin(), s.end()); // reverse the entire string

    int n = s.length();
    int left, right, i;
    i = left = right = 0;

    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;
        if (i == n)
            break;
        while (i < n && s[i] != ' ')
        {
            s[right] = s[i];
            right++;
            i++;
        }
        reverse(s.begin() + left, s.begin() + right); // reverse individual word
        s[right] = ' ';
        right++;
        left = right; // update the left
        i++;
    }
    s.resize(right - 1); // remove the last space
    return s;
}
int main()
{
    string input = " asdasd df f";

    cout << "\"" << reverseWords(input) << "\"" << endl;
}
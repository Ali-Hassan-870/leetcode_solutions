#include <algorithm>
#include <iostream>

using namespace std;

int lengthOfLastWord(string s)
{
    int n = s.length();
    int end = n - 1;

    while (end >= 0 && s[end] == ' ')
        end--;

    if (end < 0)
        return 0;

    int start = end;
    while (start >= 0 && s[start] != ' ')
        start--;

    return end - start;
}
int main()
{
    string input = "luffy is still joyboy";

    cout << lengthOfLastWord(input) << endl;
    // lengthOfLastWord(input);
}
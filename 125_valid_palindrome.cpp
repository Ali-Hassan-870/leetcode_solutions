#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (isalnum(s[i]))
            s[j++] = tolower(s[i]);
    }

    int x = 0, y = j - 1;
    while (x < y)
    {
        if (s[x] != s[y])
            return false;
        x++, y--;
    }
    return true;
}
int main()
{
    string input = " ";

    cout << isPalindrome(input) << endl;
}
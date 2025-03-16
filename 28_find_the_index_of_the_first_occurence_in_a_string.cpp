#include <iostream>
using namespace std;

int strStr(string haystack, string needle)
{
    if (haystack.length() < needle.length())
        return -1;

    int i = 0;
    int j = 0;

    while (i <= haystack.length() - needle.length())
    {
        j = 0;
        while (j < needle.length() && haystack[i + j] == needle[j])
            j++;

        if (j == needle.length())
            return i;

        i++;
    }
    return -1;
}
int main()
{
    string haystack = "mississippi";
    string needle = "issip";

    cout << strStr(haystack, needle) << endl;

    return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> romanValues = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int integerValue = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int currValue = romanValues[s[i]];
        int nextValue = (i + 1 < n) ? romanValues[s[i + 1]] : 0; //out of bounds check

        if (nextValue > currValue)
        {
            integerValue += (nextValue - currValue);
            i++; // Skip the next character since it's already processed
        }
        else
            integerValue += currValue;
    }
    return integerValue;
}
int main()
{
    string input = "III";

    cout << romanToInt(input) << endl;
}
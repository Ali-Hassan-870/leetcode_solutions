#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string intToRoman(int num)
{
    vector<pair<int, string>> roman_values = {
        {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};

    string output_string = "";
    for (int i = roman_values.size() - 1; i >= 0; i--)
    {
        while (num >= roman_values[i].first)
        {
            num -= roman_values[i].first;
            output_string += roman_values[i].second;
        }
    }
    return output_string;
}

int main()
{
    int input = 1994;
    cout << intToRoman(input) << endl;
}
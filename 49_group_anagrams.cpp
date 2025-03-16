#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> map;
    vector<vector<string>> output;

    for (const string &s : strs)
    {
        string sorted_str = s;
        sort(sorted_str.begin(), sorted_str.end());
        map[sorted_str].push_back(s);
    }

    for (auto &pair : map)
        output.push_back(pair.second);

    return output;
}
void display(vector<vector<string>> str)
{
    for (int i = 0; i < str.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < str[i].size(); j++)
            cout << str[i][j] << ", ";
        cout << "]" << endl;
    }
}

int main()
{
    vector<string> input = {"a"};
    display(groupAnagrams(input));
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> partitonLabels(string s)
{
    int n = s.size();
    vector<int> lastOccurence(26, 0);
    vector<int> partitions;

    for (int i = 0; i < n; i++)
        lastOccurence[s[i] - 'a'] = i;

    int start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        end = max(end, lastOccurence[s[i] - 'a']);
        if (i == end)
        {
            partitions.push_back((end - start) + 1);
            start = end + 1;
        }
    }
    return partitions;
}
int main()
{
    string input = "ababcbacadefegdehijhklij";
    vector<int> output = partitonLabels(input);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}
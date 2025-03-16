#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fullyJustify(vector<string> &words, int maxWidth)
{
    int n = words.size();
    vector<string> output;
    output.push_back("");
    int index = 0;

    // Step 1: Group words into lines
    for (int i = 0; i < n; i++)
    {
        if ((output[index].size() + words[i].size()) > maxWidth)
        {
            // Remove trailing space from the previous line
            if (!output[index].empty() && output[index].back() == ' ')
                output[index].pop_back();
            index++;
            output.push_back("");
        }
        output[index] += words[i] + " ";
    }
    // Remove trailing space from the last line
    if (!output[index].empty() && output[index].back() == ' ')
        output[index].pop_back();

    int m = output.size();
    vector<int> count(m, 0);

    // Step 2: Count the number of spaces in each line
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < output[i].size(); j++)
            if (output[i][j] == ' ')
                count[i]++;
    }

    // Step 3: Justify each line
    for (int i = 0; i < output.size(); i++)
    {
        int x = output[i].size();
        int spaces_to_add = maxWidth - x;

        if (count[i] == 0 || i == m - 1)
            output[i] += string(spaces_to_add, ' ');
        else if (spaces_to_add > 0)
        {
            int spaces_per_gap = spaces_to_add / count[i];
            int extra_spaces = spaces_to_add % count[i];

            for (int j = 0; j < x; j++)
            {
                if (output[i][j] == ' ')
                {
                    int spaces = spaces_per_gap + (extra_spaces > 0 ? 1 : 0);
                    output[i].replace(j, 1, spaces + 1, ' ');
                    j += spaces;
                    x += spaces; // By adding spaces the size of individual line also increease by the number of spaces
                    extra_spaces--;
                }
            }
        }
    }
    return output;
}
int main()
{
    vector<string> input = {"What", "must", "be", "acknowledgment", "shall", "be"};
    vector<string> output = fullyJustify(input, 16);
    for (int i = 0; i < output.size(); i++)
    {
        cout << "|" << output[i] << "|" << endl;
    }
}
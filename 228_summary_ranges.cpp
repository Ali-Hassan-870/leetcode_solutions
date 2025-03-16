#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    if (nums.size() == 1)
        return {to_string(nums[0])};

    vector<string> output;
    int i = 0, j = 1;

    while (j < nums.size())
    {
        if (nums[j] == nums[j - 1] + 1)
        {
            j++;
        }
        else if (i == j - 1)
        {
            output.push_back(to_string(nums[i]));
            i++;
            j++;
        }
        else
        {
            output.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
            i=j;
            j++;
        }
    }

    return output;
}

void display(vector<string> input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << "  ";
    }
    cout << endl;
}

int main()
{
    vector<int> input = {0, 1, 2, 4, 5, 7};
    display(summaryRanges(input));
    return 0;
}

// cout << nums[i] << " first " << nums[j] << endl;
// cout << nums[i] << " second " << nums[j] <<  endl;

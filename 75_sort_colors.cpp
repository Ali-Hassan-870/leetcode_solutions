#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    vector<int> frequency(3, 0);

    for (int i = 0; i < n; i++)
        frequency[nums[i]]++;

    int x = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < frequency[i]; j++)
            nums[x++] = i;
    }
}

int main()
{
    vector<int> input = {2, 0, 2, 1, 1, 0};
    sortColors(input);

    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    return 0;
}
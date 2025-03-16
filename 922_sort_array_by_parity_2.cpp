#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParityII(vector<int> &nums)
{
    int i = 0, j = 1; // Two Pointers
    while (j < nums.size())
    {
        if ((nums[i] + i) % 2 == 0)
            i++, j++;
        else
        {
            if ((nums[j] + j) % 2 == 1 && (nums[i] + nums[j]) % 2 == 1)
            {
                swap(nums[i], nums[j]);
                i++;
                j = i + 1;
            }
            else
                j++;
        }
    }
    return nums;
}

int main()
{
    vector<int> input = {4,2,5,7};
    vector<int> output = sortArrayByParityII(input);

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}
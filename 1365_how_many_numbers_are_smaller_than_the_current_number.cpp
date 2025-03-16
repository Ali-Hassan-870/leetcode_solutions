#include <iostream>
#include <vector>
using namespace std;

/* Using hashing: time O(n) and space O(1) */
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    int count[101] = {0};
    int n = nums.size();

    for (int i = 0; i < n; i++)
        count[nums[i]]++;

    for (int i = 1; i < 101; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            nums[i] = 0;
        else
            nums[i] = count[nums[i] - 1];
    }
    return nums;
}

/* Brute force approach: time O(n^2) and space O(n) */
vector<int> smallerNumbersThanCurrent2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> output(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[i] > nums[j])
                output[i]++;
        }
    }
    return output;
}
int main()
{
    vector<int> input = {8, 1, 2, 2, 3};
    vector<int> output = smallerNumbersThanCurrent2(input);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}
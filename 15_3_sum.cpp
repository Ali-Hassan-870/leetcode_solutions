#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> triplets_set;

    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int total = nums[i] + nums[j] + nums[k];
            if (total > 0)
                k--;
            else if (total < 0)
                j++;
            else
                triplets_set.insert({nums[i], nums[j++], nums[k--]});
        }
    }

    vector<vector<int>> output;

    for (auto t : triplets_set)
        output.push_back(t);

    return output;
}

int main()
{
    vector<int> input = {-1,0,1,2,-1,-4};
    vector<vector<int>> output = threeSum(input);
    for (int i = 0; i < output.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << "  ";
        }
        cout << "] ";
        
    }
    
}
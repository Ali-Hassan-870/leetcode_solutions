#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(nums[i]) != map.end() && (i - map[nums[i]]) <= k)
            return true;
        map[nums[i]] = i;
    }
    return false;
}
int main()
{
    vector<int> input = {1, 2, 3, 1, 2, 3};
    int k = 2;
    cout << containsNearbyDuplicate(input, k) << endl;
    return 0;
}

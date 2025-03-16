#include <iostream>
#include <unordered_set>
#include <vector>

using std::vector;

bool containsDuplicate(vector<int> &nums)
{
    std::unordered_set<int> nums_set;

    for (int num : nums)
    {
        if (nums_set.find(num) != nums_set.end())
            return true;

        nums_set.insert(num);
    }
    return false;
}

int main()
{
    vector<int> input = {1,2,3,4};
    std::cout << containsDuplicate(input) << std::endl;
    return 0;
}
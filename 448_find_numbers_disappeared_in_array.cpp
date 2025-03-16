#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::unordered_set;
using std::vector;

// Using set
//  vector<int> findDisappearedNumbers(vector<int> &nums)
//  {
//      unordered_set<int> set;
//      vector<int> output;

//     for (const int num : nums)
//         set.insert(num);

//     for (int i = 1; i <= nums.size(); i++)
//     {
//         if (set.find(i) == set.end())
//             output.push_back(i);
//     }

//     return output;
// }

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int n = nums.size();
    vector<int> output;

    for (int i = 0; i < n; i++)
    {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0)
            nums[index] = -nums[index];
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            output.push_back(i + 1);
    }
    return output;
}

int main()
{
    vector<int> input = {1, 1};
    vector<int> result = findDisappearedNumbers(input);

    for (const int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
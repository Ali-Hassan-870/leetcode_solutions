#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int> &nums)
{
    if (nums.size() <= 1)
        return 0;

    int farthest = 0;
    int count = 0;
    int currentEnd = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        farthest = max(farthest, nums[i] + i);

        if (currentEnd == i)
        {
            currentEnd = farthest;
            count++;

            if (currentEnd >= nums.size())
                return count;
        }
    }
    return count;
}

int main()
{
    vector<int> temp = {2,3,1,1,4};

    cout << jump(temp) << endl;
}
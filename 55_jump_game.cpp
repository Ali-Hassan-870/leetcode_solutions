#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int> &nums)
{
    int farthest = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > farthest)
            return false;

        if ((nums[i] + i) > farthest)
            farthest = nums[i] + i;

        if (farthest >= (nums.size() - 1))
            return true;
    }
    return false;
}

int main()
{
    vector<int> temp = {1, 2, 3};

    if (canJump(temp) == 0)
        cout << "False" << endl;
    else
        cout << "True" << endl;
}
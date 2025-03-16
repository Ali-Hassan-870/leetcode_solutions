#include <iostream>
#include <vector>

int missingNumber(std::vector<int> &nums)
{
    const int n = nums.size();
    int sum = n * (n + 1) / 2;

    for (const int num : nums)
        sum -= num;

    return sum;
}

int main()
{
    std::vector<int> input = {9,6,4,2,3,5,7,0,1};
    std::cout << missingNumber(input) << std::endl;
    return 0;
}
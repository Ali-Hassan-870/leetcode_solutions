#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right)
    {
        if (numbers[left] + numbers[right] == target)
            return {left + 1, right + 1};
        else if (numbers[left] + numbers[right] > target)
            right--;
        else
            left++;
    }
    return {};
}
int main()
{
    vector<int> input = {2,7,11,15};
    int target = 9;
    vector<int> output = twoSum(input, target);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << "  ";
    }
    cout << endl;

    return 0;
}
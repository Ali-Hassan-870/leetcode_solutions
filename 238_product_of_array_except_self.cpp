#include <iostream>
#include <vector>
using namespace std;

/*Solution No 1: Time O(N) , Space O(N)*/
vector<int> productExceptSelf1(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    vector<int> output(n, 1);

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] * nums[i - 1];

    for (int i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] * nums[i + 1];

    for (int i = 0; i < n; i++)
        output[i] = prefix[i] * suffix[i];

    return output;
}

/*Solution no 2: Time O(N) space O(1).*/
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 1);

    for (int i = n - 2; i >= 0; i--)
        result[i] = result[i + 1] * nums[i + 1];

    int left = 1;
    for (int i = 0; i < n; i++)
    {
        result[i] *= left;
        left *= nums[i];
    }

    return result;
}

int main()
{
    vector<int> input = {-1, 1, 0, -3, 3};
    vector<int> output = productExceptSelf(input);

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}
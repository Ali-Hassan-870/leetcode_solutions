#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{

    k = k % nums.size();

    if (nums.size() <= 1 || k == 0)
        return;

    int i = 0;
    int j = nums.size() - k - 1;

    while (i < j)
        swap(nums[i++], nums[j--]);

    int p = nums.size() - k;
    int q = nums.size() - 1;

    while (p < q)
        swap(nums[p++], nums[q--]);

    int x = 0;
    int y = nums.size() - 1;

    while (x < y)
        swap(nums[x++], nums[y--]);
}
void display(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> temp = {-1, -100, 3, 99};

    rotate(temp, 2);
    display(temp);
}
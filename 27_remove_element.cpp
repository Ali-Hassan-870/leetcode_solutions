#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int i = 0;
    int j = nums.size() - 1;

    while (i != j + 1)
    {
        if (nums[i] == val)
            swap(nums[i], nums[j--]);
        else
            i++;
    }
    return i;
}
void display(vector<int> x)
{
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> a = {0, 1, 2, 2, 3, 0, 4, 2};
    cout << removeElement(a, 2) << endl;
    display(a);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
// we will be using Boyer–Moore majority vote algorithm
int majorityElement(vector<int> &nums)
{
    int count = 0;
    int element = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            element = nums[i];
            count++;
        }

        else if (nums[i] == element)
            count++;
        else
            count--;
    }
    return element;
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
    vector<int> temp = {6,5,5};

    cout << majorityElement(temp) << endl;

    display(temp);
}
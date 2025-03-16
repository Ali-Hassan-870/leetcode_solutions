#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{

    if (nums.empty())
        return -1;
    
    int index = 0;
    for(int i =1; i<nums.size();i++)
    {
        if(nums[index] != nums[i])
        {
            nums[index+1] = nums[i];
            index++;
        }
    }
    return ++index;
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
    vector<int> a = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(a) << endl;
    display(a);

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int index = 0;

    for(int i =0; i<nums.size();i++)
    {
        if(i==0 || i==1 || nums[i] != nums[index-2])
            nums[index++] = nums[i];
    }
    return index;
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
    vector<int> temp = {1,1,1,2,2,3};

    cout << removeDuplicates(temp) << endl;

    display(temp);

}
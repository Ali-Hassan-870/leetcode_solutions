#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    if (n == 0)
        return;

    int index1 = m - 1;
    int index2 = n - 1;
    int main_index = m + n - 1;

    while (index2 >= 0)
    {
        if (index1 >= 0 && nums1[index1] > nums2[index2])
        {
            nums1[main_index] = nums1[index1];
            index1--;
            
        }
        else
        {
            nums1[main_index] = nums2[index2];
            index2--;
        }
        main_index--;
    }
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
    vector<int> a = {1,2,3,0,0,0};
    vector<int> b = {2,5,6};

    merge(a,3,b,3);
    display(a);

    return 0;
}
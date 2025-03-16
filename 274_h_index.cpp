#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

bool comparator(int a, int b)
{
    return a>b;
}
int hIndex(vector<int>& citations)
{
    int count = 0;
    sort(citations.begin(), citations.end(), comparator);

    for (int i = 0; i < citations.size(); i++)
    {
        if(citations[i] >= i+1)
        {
            count++;
        }
        else{
            return count;
        }
    }
    
}

int main()
{
    vector<int> temp = {1,3,1};

    cout << hIndex(temp) << endl;
}
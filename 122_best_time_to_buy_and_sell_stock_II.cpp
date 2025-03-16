#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{

    if (prices.size() == 1)
        return 0;

    int maxProf = 0;
    int buyIndex = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < prices[i - 1])
            buyIndex = i;

        if (prices[i] - prices[buyIndex] > 0)
        {
            maxProf += prices[i] - prices[buyIndex];
            buyIndex = i;
        }
    }
    return maxProf;
}

int main()
{
    vector<int> temp = {7,1,5,3,6,4};

    cout << maxProfit(temp) << endl;
}
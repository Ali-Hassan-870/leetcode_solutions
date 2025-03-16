#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    if (prices.size() == 1)
        return 0;

    int maxprof = 0;
    int cheapest = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < prices[cheapest])
            cheapest = i;

        if (prices[i] - prices[cheapest] > maxprof)
            maxprof = prices[i] - prices[cheapest];
    }

    return maxprof;
}

int main()
{
    vector<int> temp = {7,1,5,3,6,4};

    cout << maxProfit(temp) << endl;
}
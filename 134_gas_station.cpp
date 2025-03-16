#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int totalgas = 0;
    int totalCost = 0;
    int gasTank = 0;
    int startIndex = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        totalgas += gas[i];
        totalCost += cost[i];
        gasTank += gas[i] - cost[i];

        if (gasTank < 0)
        {
            startIndex = i+1;
            gasTank = 0;
        }
    }

    if (totalgas >= totalCost)
        return startIndex;
    else
        return -1;
}

int main()
{
    vector<int> gasInput = {5, 1, 2, 3, 4};
    vector<int> costInput = {4, 4, 1, 5, 1};

    cout << canCompleteCircuit(gasInput, costInput) << endl;
    // canCompleteCircuit(gasInput, costInput);

    return 0;
}

#include <iostream>
#include <unordered_set>
using namespace std;

bool isHappy(int n)
{
    int num = n;
    int sum = 0;
    unordered_set<int> set;

    while (true)
    {
        while (num != 0)
        {
            int temp = num % 10;
            num = num / 10;
            sum += temp * temp;
        }
        if (sum == 1)
            return true;
        if (set.find(sum) != set.end())
            return false;

        set.insert(sum);
        num = sum;
        sum = 0;
    }
}

int main()
{
    cout << isHappy(2) << endl;
    return 0;
}
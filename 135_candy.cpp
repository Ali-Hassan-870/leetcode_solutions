#include <iostream>
#include <vector>
using namespace std;

/* Solution no 1: time complexity O(1) and space complexity O(N).
In this solution we take a vector to store the number of candies assign to each children. Then we first traverse the ratings array from left to right and then from right to left and at the end sum up the candies array to return the minimum candies required to distribute among the childs.*/

int candy(vector<int> &ratings)
{
    int n = ratings.size();

    if (n == 1)
        return 1;

    vector<int> candies(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
            candies[i] = max(candies[i], candies[i + 1] + 1);
    }

    int minCandies = 0;
    for (int candy : candies)
        minCandies += candy;

    return minCandies;
}

/* Solution No 2: time complexity O(N) space complexity O(1).
In this method we solve the problem using peak and valley method without using the extra space. */

int candySolution2(vector<int> &ratings)
{
    if (ratings.empty())
        return 0;

    int n = ratings.size();

    if (n == 1)
        return 1;

    int i = 1;
    int minCandies = n;

    while (i < n)
    {
        if (ratings[i] == ratings[i - 1])
        {
            i++;
            continue;
        }

        int peak = 0;
        while (ratings[i] > ratings[i - 1])
        {
            peak++;
            i++;
            minCandies += peak;
            if (i == n)
                return minCandies;
        }

        int valley = 0;
        while (i < n && ratings[i] < ratings[i - 1])
        {
            valley++;
            i++;
            minCandies += valley;
        }
        minCandies -= min(peak, valley); // only keep the peak value
    }
    return minCandies;
}

int main()
{
    vector<int> input = {1, 0, 2, 1, 3, 2, 1};
    int output = candySolution2(input);
    cout << "function output: " << output << endl;

    return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;

/* Solution no 1: using hash table time O(n+m) space O(n). */
int numJewelsInStones(string jewels, string stones)
{
    int n = jewels.size();
    int m = stones.size();

    unordered_map<char, int> jewels_map;
    for (int i = 0; i < n; i++)
    {
        jewels_map[jewels[i]] = i; // insert values in hash table (unordered_map)
    }

    int jewels_count = 0;
    for (int i = 0; i < m; i++)
    {
        if (jewels_map.count(stones[i])) // check if value is present
            jewels_count++;
    }
    return jewels_count;
}

/* solution no 2: Using brute force time O(n*m) space O(1) */
int numJewelsInStones(string jewels, string stones)
{
    int n = jewels.size();
    int m = stones.size();

    if (n == 0 || m == 0) // handle edge case
        return 0;

    int jewels_count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (stones[i] == jewels[j])
                jewels_count++;
        }
    }

    return jewels_count;
}
int main()
{
    string jewel_input = "xyz";
    string stones_input = "ZZZXXxxxyyyXKJSISzyx";
    cout << numJewelsInStones(jewel_input, stones_input) << endl;

    return 0;
}
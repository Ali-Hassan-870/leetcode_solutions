#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char> &s)
{
    int i = 0;
    int j = s.size() - 1;
    while (i < j)
        swap(s[i++], s[j--]);
}
int main()
{
    vector<char> input = {'H', 'a', 'n', 'n', 'a', 'h'};
    reverseString(input);
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    return 0;
}
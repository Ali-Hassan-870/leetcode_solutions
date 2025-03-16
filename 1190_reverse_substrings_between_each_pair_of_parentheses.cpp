#include <iostream>
#include <stack>
using namespace std;

/*Solution no 1: Time O(N^2) Space O(N)*/
string reverseParentheses(string s)
{
    string output = "";
    stack<char> stack;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            string temp = "";
            while (!stack.empty() && stack.top() != '(')
            {
                temp += stack.top();
                stack.pop();
            }

            if (!stack.empty())
                stack.pop();

            for (int i = 0; i < temp.length(); i++)
                stack.push(temp[i]);
        }
        else
            stack.push(s[i]);
    }

    while (!stack.empty())
    {
        output = stack.top() + output;
        stack.pop();
    }

    return output;
}
int main()
{
    string a = "((abc)def)";
    cout << reverseParentheses(a) << endl;
}
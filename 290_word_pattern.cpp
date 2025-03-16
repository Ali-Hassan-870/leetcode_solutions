#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> map;         // map pattern -> s
    unordered_map<string, char> reverse_map; // map s -> pattern
    string word;
    stringstream s_stream(s);
    int index = 0;

    while (s_stream >> word)
    {
        if (index >= pattern.size())
            return false;

        if (map.find(pattern[index]) != map.end())
        {
            if (map[pattern[index]] != word)
                return false;
        }
        else
        {
            if (reverse_map.find(word) != reverse_map.end())
                return false;
            map[pattern[index]] = word;
            reverse_map[word] = pattern[index];
        }
        index++;
    }
    return index == pattern.size(); // if pattern is fully matched
}

int main()
{
    string pattern_input = "abba";
    string s_input = "dog c cat dog";
    cout << wordPattern(pattern_input, s_input) << endl;
    return 0;

    // string str = "dog cat cat dog";
    // string word;
    // vector<string> words;  // Store extracted words

    // stringstream ss(str); // Create a stream from the string

    // while (ss >> word) {  // Extract words separated by spaces
    //     words.push_back(word);
    // }

    // // Print extracted words
    // for (const string &w : words) {
    //     cout << w << endl;
    // }
}
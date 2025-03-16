#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> findSubstring(string s, vector<string> &words) {
    int n = s.size();                     // Length of the string
    int word_len = words[0].size();      // Length of each word
    int words_count = words.size();      // Number of words
    int total_len = word_len * words_count; // Total length of concatenated words

    if (total_len > n) return {};        // Early exit if total length is more than string length

    unordered_map<string, int> words_map;
    for (const auto &word : words) {
        words_map[word]++;               // Count frequency of each word
    }

    vector<int> output;

    // Iterate over possible starting positions for substrings
    for (int i = 0; i < word_len; ++i) {
        unordered_map<string, int> seen_words;
        int left = i, right = i;
        int count = 0;

        // Slide the window across the string
        while (right + word_len <= n) {
            string word = s.substr(right, word_len);
            right += word_len;

            if (words_map.find(word) != words_map.end()) {
                seen_words[word]++;
                count++;

                // Adjust window if the word count exceeds expected frequency
                while (seen_words[word] > words_map[word]) {
                    string left_word = s.substr(left, word_len);
                    seen_words[left_word]--;
                    count--;
                    left += word_len;
                }

                // If all words are matched, record the start index
                if (count == words_count) {
                    output.push_back(left);
                    // Remove the leftmost word and adjust the window
                    string left_word = s.substr(left, word_len);
                    seen_words[left_word]--;
                    count--;
                    left += word_len;
                }
            } else {
                // If word is not in words_map, reset window
                seen_words.clear();
                count = 0;
                left = right;
            }
        }
    }
    return output;
}

int main()
{
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar", "foo", "the"};
    vector<int> result = findSubstring(s, words);

    if (result.size() == 0)
        cout << "result is empty" << endl;
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << "  ";
}
// Link: https://www.geeksforgeeks.org/problems/balancing-consonants-and-vowels-ratio/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int countBalanced(vector<string> &arr)
    {
        int n = arr.size();
        int res = 0;
        int prefix = 0;

        unordered_map<int, int> freq;

        freq[0] = 1;

        for (int i = 0; i < n; i++)
        {
            int score = 0;
            for (char ch : arr[i])
            {
                if (isVowel(ch))
                    score++;
                else
                    score--;
            }

            prefix += score;

            res += freq[prefix];

            freq[prefix]++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> arr = {"aeio", "aa", "bc", "ot", "cdbd"};
    int result = sol.countBalanced(arr);
    cout << "Number of balanced substrings: " << result << endl;

    arr = {"ab", "be"};
    result = sol.countBalanced(arr);
    cout << "Number of balanced substrings: " << result << endl;

    arr = {"tz", "gfg", "ae"};
    result = sol.countBalanced(arr);
    cout << "Number of balanced substrings: " << result << endl;
    return 0;
}
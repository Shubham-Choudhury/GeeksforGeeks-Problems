// Link: https://www.geeksforgeeks.org/problems/k-pangrams0909/1

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool kPangram(string str, int k)
    {
        int n = str.size(), spaces = 0;
        unordered_set<char> m;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == ' ')
            {
                spaces++;
            }
            else
            {
                m.insert(str[i]);
            }
        }
        if (26 - m.size() <= k && 26 - m.size() <= n - spaces && n - spaces >= 26)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution obj;
    string str = "the quick brown fox jumps over the lazy dog";
    int k = 0;
    cout << obj.kPangram(str, k) << endl;

    str = "aaaaaaaaaaaaaaaaaaaaaaaaaa";
    k = 25;
    cout << obj.kPangram(str, k) << endl;

    str = "a b c d e f g h i j k l m";
    k = 20;
    cout << obj.kPangram(str, k) << endl;
    return 0;
}
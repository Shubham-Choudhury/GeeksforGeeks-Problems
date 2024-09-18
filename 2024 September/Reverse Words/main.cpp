// Link: https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string reverseWords(string str)
    {
        vector<string> temp;

        string t = "";

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '.')
            {
                temp.push_back(t);
                t = "";
            }
            else
            {
                t += str[i];
            }
            if (i == str.length() - 1)
            {
                temp.push_back(t);
            }
        }

        string ans = "";

        for (int i = temp.size() - 1; i >= 0; i--)
        {
            ans += temp[i];
            if (i != 0)
            {
                ans += '.';
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    string str = "i.like.this.program.very.much";
    cout << obj.reverseWords(str) << endl;

    str = "pqr.mno";
    cout << obj.reverseWords(str) << endl;
    return 0;
}
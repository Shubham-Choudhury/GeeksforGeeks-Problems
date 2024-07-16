// Link: https://www.geeksforgeeks.org/problems/remaining-string3515/1

#include <iostream>
using namespace std;

class Solution
{
public:
    string printString(string s, char ch, int count)
    {
        int c = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (ch == s[i])
            {
                c++;
            }
            if (c == count)
            {
                return s.substr(i + 1);
            }
        }
        return "";
    }
};

int main()
{
    Solution obj;
    string s = "Thisisdemostring";
    char ch = 'i';
    int count = 3;
    cout << obj.printString(s, ch, count) << endl;

    s = "Thisisdemostri";
    ch = 'i';
    count = 3;
    cout << obj.printString(s, ch, count) << endl;
    return 0;
}
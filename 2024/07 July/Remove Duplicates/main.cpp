// Link: https://www.geeksforgeeks.org/problems/remove-duplicates3034/1

#include <iostream>
using namespace std;

class Solution
{
public:
    string removeDups(string str)
    {
        int unique[128] = {0};
        string result;

        for (int i = 0; i < str.length(); i++)
        {
            if (unique[str[i]] == 0)
            {
                result += str[i];
                unique[str[i]] = 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution obj;

    string str = "zvvo";
    cout << obj.removeDups(str) << endl;

    str = "gfg";
    cout << obj.removeDups(str) << endl;
    return 0;
}
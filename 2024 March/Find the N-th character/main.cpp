// Link: https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char nthCharacter(string s, int r, int n)
    {
        long long int previous = 0;
        long long int next;
        int power = int(pow(2, r)) - 1;
        int i;
        for (i = 0; i < n; i++)
        {
            next = previous + power;
            if (n >= previous && n <= next)
                break;
            previous = next + 1;
        }

        string temp;
        temp.push_back(s[i]);
        for (int j = 0; j < r; j++)
        {
            string temp1;
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] == '0')
                {
                    temp1.push_back('0');
                    temp1.push_back('1');
                }
                else
                {
                    temp1.push_back('1');
                    temp1.push_back('0');
                }
            }
            temp.clear();
            temp = temp1;
            temp1.clear();
        }

        return temp[n - previous];
    }
};

int main()
{
    Solution obj;
    string s = "1100";
    int r = 2;
    int n = 3;
    cout << obj.nthCharacter(s, r, n) << endl;
    s = "1010";
    r = 1;
    n = 2;
    cout << obj.nthCharacter(s, r, n) << endl;
    return 0;
}
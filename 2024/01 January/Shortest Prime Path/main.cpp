// Link: https://www.geeksforgeeks.org/problems/shortest-prime-path--141631/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int Num1, int Num2)
    {
        if (Num1 == Num2)
            return 0;

        vector<int> sieve(10000, 1);
        sieve[0] = 0, sieve[1] = 0;
        for (int i = 2; i <= 9999; i++)
        {
            if (sieve[i])
            {
                for (int j = i * i; j <= 9999; j += i)
                    sieve[j] = 0;
            }
        }

        int ans = -1;
        string str1 = to_string(Num1), str2 = to_string(Num2);
        map<string, int> mp;
        queue<pair<string, int>> q;
        q.push({str1, 0});
        mp[str1]++;
        while (!q.empty())
        {
            string str = q.front().first;
            int step = q.front().second;
            q.pop();
            if (str == str2)
            {
                ans = step;
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j <= 9; j++)
                {
                    if (!i && !j)
                        continue;
                    char ch = str[i];
                    str[i] = j + '0';
                    if (sieve[stoi(str)] && !mp[str])
                    {
                        q.push({str, step + 1});
                        mp[str]++;
                    }
                    str[i] = ch;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int Num1 = 1033;
    int Num2 = 8179;
    cout << obj.solve(Num1, Num2) << endl;
    Num1 = 1033;
    Num2 = 1033;
    cout << obj.solve(Num1, Num2) << endl;
    return 0;
}
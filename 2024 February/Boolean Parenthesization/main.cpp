// Link: https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWays(int n, string s)
    {

        vector<vector<int>> tru(n, vector<int>(n, 0));
        vector<vector<int>> fals(n, vector<int>(n, 0));

        int md = 1003;

        for (int itr = 0; itr < n; itr = itr + 2)
        {

            for (int i = 0; i + itr < n; i = i + 2)
            {

                int j = i + itr;

                if (i == j)
                {
                    tru[i][j] = s[i] == 'T' ? 1 : 0;
                    fals[i][j] = s[i] == 'F' ? 1 : 0;
                }

                for (int k = i + 1; k < j; k = k + 2)
                {

                    int left_tru = tru[i][k - 1];
                    int right_tru = tru[k + 1][j];
                    int left_fals = fals[i][k - 1];
                    int right_fals = fals[k + 1][j];

                    if (s[k] == '|')
                    {

                        tru[i][j] += left_tru * right_tru + left_tru * right_fals + right_tru * left_fals;
                        fals[i][j] += left_fals * right_fals;
                    }
                    else if (s[k] == '&')
                    {

                        tru[i][j] += left_tru * right_tru;
                        fals[i][j] += left_fals * right_fals + left_tru * right_fals + right_tru * left_fals;
                    }
                    else if (s[k] == '^')
                    {

                        tru[i][j] += left_tru * right_fals + right_tru * left_fals;
                        fals[i][j] += left_tru * right_tru + left_fals * right_fals;
                    }
                }

                tru[i][j] = (tru[i][j]) % md;
                fals[i][j] = (fals[i][j]) % md;
            }
        }

        return tru[0][n - 1];
    }
};

int main()
{
    Solution obj;
    int n = 7;
    string str = "T|T&F^T";
    cout << obj.countWays(n, str) << endl;
    n = 5;
    str = "T^F|F";
    cout << obj.countWays(n, str) << endl;
    return 0;
}
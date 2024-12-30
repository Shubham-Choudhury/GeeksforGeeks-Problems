// Link: https://www.geeksforgeeks.org/problems/candy/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCandy(int N, vector<int> &ratings)
    {
        vector<int> choc(N, 1);

        for (int i = 1; i < N; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                choc[i] = choc[i - 1] + 1;
            }
        }

        for (int i = N - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                choc[i] = max(choc[i], choc[i + 1] + 1);
            }
        }

        int ans = 0;
        for (auto i : choc)
        {
            ans += i;
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    int N = 3;
    vector<int> ratings{1, 0, 2};
    cout << obj.minCandy(N, ratings) << endl;
    return 0;
}
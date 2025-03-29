// Link: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        int n = deadline.size();
        vector<pair<int, int>> p;
        int maxi = 0;

        for (int i = 0; i < n; i++)
        {
            p.push_back({profit[i], deadline[i]});
            maxi = max(maxi, deadline[i]);
        }

        sort(p.rbegin(), p.rend());
        set<int> s;
        for (int i = 1; i <= maxi; i++)
        {
            s.insert(i);
        }

        int sum = 0, cnt = 0;

        for (int i = 0; i < p.size(); i++)
        {
            if (s.empty())
                break;
            auto it = s.upper_bound(p[i].second);

            if (it != s.begin())
            {
                it--;
                sum += p[i].first;
                cnt++;
                s.erase(it);
            }
        }

        return {cnt, sum};
    }
};

int main()
{
    Solution sol;
    vector<int> deadline = {2, 1, 2, 1, 3};
    vector<int> profit = {100, 19, 27, 25, 15};
    vector<int> result = sol.jobSequencing(deadline, profit);
    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;

    deadline = {4, 1, 1, 1};
    profit = {20, 10, 40, 30};
    result = sol.jobSequencing(deadline, profit);
    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;

    deadline = {3, 1, 2, 2};
    profit = {50, 10, 20, 30};
    result = sol.jobSequencing(deadline, profit);
    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;
    return 0;
}

// Link: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
    vector<int> JobScheduling(Job arr[], int n)
    {
        vector<pair<int, int>> p;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            p.push_back({arr[i].profit, arr[i].dead});
            maxi = max(maxi, arr[i].dead);
        }

        sort(p.rbegin(), p.rend());
        vector<int> vis(maxi + 1, 0);

        set<int> s;
        for (int i = 1; i <= maxi; i++)
        {
            s.insert(i);
        }

        int sum = 0;
        int cnt = 0;

        for (int i = 0; i < p.size(); i++)
        {
            if (s.empty())
                break;
            auto it = s.upper_bound(p[i].second);

            if ((*it) == p[i].second)
            {
                sum += p[i].first;
                cnt++;
                if (it == s.end())
                    it--;
                s.erase(it);
            }
            else if (it != s.begin())
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
    Solution obj;
    Job arr1[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}};
    int n = sizeof(arr1) / sizeof(Job);
    vector<int> ans = obj.JobScheduling(arr1, n);
    cout << ans[0] << " " << ans[1] << endl;

    Job arr2[] = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 1, 15}};

    n = sizeof(arr2) / sizeof(Job);
    ans = obj.JobScheduling(arr2, n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
};
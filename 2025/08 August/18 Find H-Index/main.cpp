// Link: https://www.geeksforgeeks.org/problems/find-h-index--165609/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> freq(n + 1);

        for (int i = 0; i < n; i++)
        {
            if (citations[i] >= n)
                freq[n] += 1;
            else
                freq[citations[i]] += 1;
        }

        int idx = n;

        int s = freq[n];
        while (s < idx)
        {
            idx--;
            s += freq[idx];
        }

        return idx;
    }
};

int main()
{
    Solution sol;
    vector<int> citations = {3, 0, 5, 3, 0};
    int result = sol.hIndex(citations);
    cout << "H-Index: " << result << endl;

    citations = {5, 1, 2, 4, 1};
    result = sol.hIndex(citations);
    cout << "H-Index: " << result << endl;

    citations = {0, 0};
    result = sol.hIndex(citations);
    cout << "H-Index: " << result << endl;
    return 0;
}
// Link: https://www.geeksforgeeks.org/problems/find-h-index--165609/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size();
        for (int i = 0; i < n; ++i)
        {

            if (citations[i] < i + 1)
            {
                return i;
            }
        }
        return n;
    }
};

int main()
{
    Solution object;
    vector<int> citations = {3, 0, 5, 3, 0};
    cout << object.hIndex(citations) << endl;

    citations = {5, 1, 2, 4, 1};
    cout << object.hIndex(citations) << endl;

    citations = {0, 0, 0};
    cout << object.hIndex(citations) << endl;
    return 0;
}
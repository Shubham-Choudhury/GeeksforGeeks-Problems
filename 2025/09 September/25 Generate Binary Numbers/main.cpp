// Link: https://www.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<string> generateBinary(int n)
    {
        vector<string> res;
        queue<string> q;

        q.push("1");

        while (n--)
        {
            string s1 = q.front();
            q.pop();
            res.push_back(s1);

            string s2 = s1;

            q.push(s1.append("0"));

            q.push(s2.append("1"));
        }
        return res;
    }
};

int main()
{
    Solution obj;
    int n = 4;
    vector<string> ans = obj.generateBinary(n);
    cout << "Binary numbers from 1 to " << n << " are: ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    n = 6;
    ans = obj.generateBinary(n);
    cout << "Binary numbers from 1 to " << n << " are: ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
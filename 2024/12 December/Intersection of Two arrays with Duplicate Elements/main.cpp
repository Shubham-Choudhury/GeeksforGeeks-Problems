// Link: https://www.geeksforgeeks.org/problems/intersection-of-two-arrays-with-duplicate-elements/1

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> intersectionWithDuplicates(vector<int> &a, vector<int> &b)
    {
        vector<int> op;
        set<int> s;
        set<int> t;
        for (int i = 0; i < a.size(); i++)
        {
            s.insert(a[i]);
        }

        for (int i = 0; i < b.size(); i++)
        {
            t.insert(b[i]);
        }

        for (int x : t)
        {
            if (s.find(x) != s.end())
            {
                op.push_back(x);
            }
        }

        return op;
    }
};

int main()
{
    Solution object;
    vector<int> a = {1, 2, 1, 3, 1};
    vector<int> b = {3, 1, 3, 4, 1};
    vector<int> op = object.intersectionWithDuplicates(a, b);
    for (int x : op)
    {
        cout << x << " ";
    }
    cout << endl;

    a = {1, 1, 1};
    b = {1, 1, 1, 1, 1};
    op = object.intersectionWithDuplicates(a, b);
    for (int x : op)
    {
        cout << x << " ";
    }
    cout << endl;

    a = {1, 2, 3};
    b = {4, 5, 6};
    op = object.intersectionWithDuplicates(a, b);
    for (int x : op)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
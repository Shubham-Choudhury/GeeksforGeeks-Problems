// Link: https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int findUnion(vector<int> &a, vector<int> &b)
    {
        a.insert(a.end(), b.begin(), b.end());
        unordered_set<int> s(a.begin(), a.end());
        return s.size();
    }
};

int main()
{
    Solution object;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3};
    cout << object.findUnion(a, b) << endl;

    a = {85, 25, 1, 32, 54, 6};
    b = {85, 2};
    cout << object.findUnion(a, b) << endl;

    a = {1, 2, 1, 1, 2};
    b = {2, 2, 1, 2, 1};
    cout << object.findUnion(a, b) << endl;
    return 0;
}
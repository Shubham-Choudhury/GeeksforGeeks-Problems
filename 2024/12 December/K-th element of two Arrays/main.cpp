// Link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        int n = a.size(), m = b.size();
        vector<int> arr(n + m);
        int i = 0, j = 0, d = 0;
        while (i < n && j < m)
        {

            if (a[i] < b[j])
                arr[d++] = a[i++];

            else
                arr[d++] = b[j++];
        }

        while (i < n)
            arr[d++] = a[i++];

        while (j < m)
            arr[d++] = b[j++];

        return arr[k - 1];
    }
};

int main()
{
    Solution object;
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    cout << object.kthElement(a, b, k) << endl;

    a = {100, 112, 256, 349, 770};
    b = {72, 86, 113, 119, 265, 445, 892};
    k = 7;
    cout << object.kthElement(a, b, k) << endl;

    return 0;
}
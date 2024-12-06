// Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int merge(vector<int> &v, int l, int mid, int r)
    {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        vector<int> v1(n1), v2(n2);
        for (int i = 0; i < n1; i++)
        {
            v1[i] = v[i + l];
        }
        for (int j = 0; j < n2; j++)
        {
            v2[j] = v[mid + 1 + j];
        }
        int i = 0, j = 0, n = l;
        int count = 0;
        while (i < n1 && j < n2)
        {
            if (v1[i] <= v2[j])
            {
                v[n] = v1[i];
                i++;
                n++;
            }
            else
            {
                v[n] = v2[j];
                j++;
                n++;
                count += (n1 - i);
            }
        }

        while (i < n1)
        {
            v[n] = v1[i];
            i++;
            n++;
        }
        while (j < n2)
        {
            v[n] = v2[j];
            j++;
            n++;
        }
        return count;
    }

    int mergesort(vector<int> &v, int l, int r)
    {
        int count = 0;
        if (l < r)
        {
            int mid = (l + r) / 2;
            count += mergesort(v, l, mid);
            count += mergesort(v, mid + 1, r);
            count += merge(v, l, mid, r);
        }
        return count;
    }

    int inversionCount(vector<int> &arr)
    {
        return mergesort(arr, 0, arr.size() - 1);
    }
};

int main()
{
    Solution object;
    vector<int> v = {2, 4, 1, 3, 5};
    cout << object.inversionCount(v) << endl;

    v = {2, 3, 4, 5, 6};
    cout << object.inversionCount(v) << endl;

    v = {10, 10, 10};
    cout << object.inversionCount(v) << endl;
    return 0;
}
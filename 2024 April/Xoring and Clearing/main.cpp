// Link: https://www.geeksforgeeks.org/problems/xoring-and-clearing/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printArr(int n, int arr[])
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
            if (i < n - 1)
                cout << " ";
        }
        cout << endl;
    }

    void setToZero(int n, int arr[])
    {
        for (int i = 0; i < n; i++)
            arr[i] = 0;
    }

    void xor1ToN(int n, int arr[])
    {

        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] ^ i;
        }
    }
};

int main()
{
    Solution obj;
    int arr1[] = {10, 20, 30, 40};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    obj.xor1ToN(n1, arr1);
    obj.printArr(n1, arr1);
    obj.setToZero(n1, arr1);
    obj.printArr(n1, arr1);

    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    obj.xor1ToN(n2, arr2);
    obj.printArr(n2, arr2);
    obj.setToZero(n2, arr2);
    obj.printArr(n2, arr2);
    return 0;
}
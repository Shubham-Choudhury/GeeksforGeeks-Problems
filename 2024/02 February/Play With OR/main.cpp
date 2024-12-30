// Link: https://www.geeksforgeeks.org/problems/play-with-or5515/1

#include <bits/stdc++.h>
using namespace std;

int *game_with_number(int arr[], int n)
{
    int x = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        int p = arr[i];
        arr[i] |= x;
        x = p;
    }
    return arr;
}

int main()
{
    int arr1[] = {10, 11, 1, 2, 3};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int *res = game_with_number(arr1, n);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    int arr2[] = {5, 9, 2, 6};
    n = sizeof(arr2) / sizeof(arr2[0]);
    res = game_with_number(arr2, n);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
// Link: https://www.geeksforgeeks.org/problems/transform-to-prime4635/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool primecheck(int n)
    {
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    int minNumber(int arr[], int N)
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];

        int sum1 = sum;
        while (primecheck(sum) != 1)
            sum++;

        return sum - sum1;
    }
};

int main()
{
    Solution obj;
    int arr[] = {2, 4, 6, 8, 12};
    int n = 5;
    cout << obj.minNumber(arr, n) << endl;

    int arr1[] = {1, 5, 7};
    int n1 = 3;
    cout << obj.minNumber(arr1, n1) << endl;

    return 0;
}
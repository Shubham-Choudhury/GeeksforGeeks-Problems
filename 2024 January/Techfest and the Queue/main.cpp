// Link: https://www.geeksforgeeks.org/problems/techfest-and-the-queue1044/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int factors(int num)
    {
        int factorSum = 0;
        if (num <= 1)
            return 0;
        while (num % 2 == 0)
        {
            factorSum++;
            num /= 2;
        }
        for (int i = 3; i <= sqrt(num); i += 2)
        {
            while (num % i == 0 && num > 0)
            {
                factorSum++;
                num /= i;
            }
        }
        if (num > 2)
            factorSum++;
        return factorSum;
    }
    int sumOfPowers(int a, int b)
    {
        int sum = 0;
        while (a <= b && (b - a) <= 100000)
        {
            sum += factors(a);
            a++;
        }
        return sum;
    }
};

int main()
{
    Solution obj;
    int a = 9;
    int b = 12;
    cout << obj.sumOfPowers(a, b);
    return 0;
}
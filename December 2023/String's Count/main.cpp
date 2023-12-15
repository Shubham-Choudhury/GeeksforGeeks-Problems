// Link: https://www.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints1135/1

#include <bits/stdc++.h>
using namespace std;

long long int countStr(long long int n)
{
    // complete the function here
    long long int ans = 0;
    ans = 1;
    ans += n;
    ans += n;
    ans += n * (n - 1);
    ans += n * (n - 1) * (n - 2) / 2;
    ans += n * (n - 1) / 2;
    return ans;
}

int main()
{
    long long int n = 1;
    cout << countStr(n) << endl;
    n = 3;
    cout << countStr(n) << endl;
    return 0;
}
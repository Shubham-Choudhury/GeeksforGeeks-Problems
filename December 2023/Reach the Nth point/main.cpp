// Link: https://www.geeksforgeeks.org/problems/reach-the-nth-point5433/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int expo(int n, vector<int> &DP)
	{
		if (n == 0)
			return 1;
		if (DP[n] != -1)
			return DP[n];
		long long ans = 0LL;
		if (n >= 1)
			ans = (ans + expo(n - 1, DP)) % 1000000007;
		if (n >= 2)
			ans = (ans + expo(n - 2, DP)) % 1000000007;
		return DP[n] = ans;
	}
	int nthPoint(int n)
	{
		vector<int> DP(n + 1, -1);
		return expo(n, DP);
	}
};

int main()
{
	Solution obj;
	int n = 4;
	cout << obj.nthPoint(n) << endl;
	return 0;
}
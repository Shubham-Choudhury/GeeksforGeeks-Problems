// Link: https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1

#include<bits/stdc++.h>
using namespace std;

#define ll long long

//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	       ll mod = 1e9 + 7;
	    ll a[n], b[n];
	    a[0] = b[0] = 1;
	    
	    for(int i = 1; i < n; i++){
	        a[i] = (a[i - 1] + b[i - 1]) % mod;
	        b[i] = a[i - 1] % mod;
	    }
	    
	    return (a[n - 1] + b[n - 1]) % mod;
	}
};

int main(){
    Solution sol;
    int N=3;
    cout << sol.countStrings(N)<<endl;
    return 0;
}
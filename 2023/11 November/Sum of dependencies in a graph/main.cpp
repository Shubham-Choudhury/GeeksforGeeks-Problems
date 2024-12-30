// Link: https://www.geeksforgeeks.org/problems/sum-of-dependencies-in-a-graph5311/1

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    int sumOfDependencies(vector<int> adj[], int V) {
        int ans = 0;
        for(int i=0;i<V;i++)
        {
            ans += adj[i].size();
        }
        return ans;
    }
};

int main(){
    Solution obj;
    int v=4;
    int e=3;
    vector<int> adj[v];
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(3);
    cout<<obj.sumOfDependencies(adj,v);
    return 0;
}
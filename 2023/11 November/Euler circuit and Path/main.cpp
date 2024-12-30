// Link: https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int isEulerCircuit(int V, vector<int>adj[]){
	   int cnt=0;
        for(int i=0;i<V;i++){
            if(adj[i].size()%2==0){
                cnt++;
            }
        }
        if(cnt==V) return 2;
        if(cnt==V-2) return 1;
        return 0; 
	}
};

int main(){
    Solution obj;
    int V,E;
    cin>>V>>E;
    vector<int>adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    cout<<obj.isEulerCircuit(V,adj);
    return 0;
}
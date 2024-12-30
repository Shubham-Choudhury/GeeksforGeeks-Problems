// Link: https://www.geeksforgeeks.org/problems/minimum-distance-between-two-numbers/1

#include <bits\stdc++.h>
using namespace std;

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        int mini = INT_MAX;
        int l = -1 , r = -1;
        for(int i = 0 ; i<n ;i++){
            if(a[i]==x) l = i;
            else if(a[i]==y) r = i;
            if(l!=-1 && r!=-1) mini = min(mini , abs(l-r));
        }
        if(mini == INT_MAX) return -1;
     return mini ;
    }
};

int main(){
    Solution obj;
    int n = 4;
    int a[] = {1,2,3,4};
    int x = 1 , y = 4;
    cout<<obj.minDist(a,n,x,y);
    return 0;
}
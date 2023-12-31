// Link: https://www.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        string s1 = "";
        int n1 = str1.size();
        s1.append(str1, 2, n1 - 2);
        s1.append(str1, 0, 2);

        string s2 = "";
        s2.append(str1, n1 - 2, n1 - 1);
        s2.append(str1, 0, n1 - 2);
        return (s1 == str2 || s2 == str2);
    }
};

int main(){
    Solution obj;
    string a="amazon";
    string b="azonam";
    cout<<obj.isRotated(a,b);
    return 0;
}
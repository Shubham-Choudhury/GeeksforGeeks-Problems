// Link: https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    bool pythagoreanTriplet(vector<int> &arr)
    {
        int n = arr.size();
        int maxEle = 0;
        for (int ele : arr)
            maxEle = max(maxEle, ele);

        vector<bool> vis(maxEle + 1, 0);

        for (int ele : arr)
            vis[ele] = true;

        for (int a = 1; a <= maxEle; a++)
        {

            if (vis[a] == false)
                continue;

            for (int b = 1; b <= maxEle; b++)
            {

                if (vis[b] == false)
                    continue;

                int c = sqrt(a * a + b * b);

                if ((c * c) != (a * a + b * b) || c > maxEle)
                    continue;

                if (vis[c] == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 2, 4, 6, 5};
    if (sol.pythagoreanTriplet(arr))
        cout << "Yes, there exists a Pythagorean triplet." << endl;
    else
        cout << "No, there does not exist a Pythagorean triplet." << endl;

    arr = {3, 8, 5};
    if (sol.pythagoreanTriplet(arr))
        cout << "Yes, there exists a Pythagorean triplet." << endl;
    else
        cout << "No, there does not exist a Pythagorean triplet." << endl;

    arr = {1, 1, 1};
    if (sol.pythagoreanTriplet(arr))
        cout << "Yes, there exists a Pythagorean triplet." << endl;
    else
        cout << "No, there does not exist a Pythagorean triplet." << endl;
    return 0;
}
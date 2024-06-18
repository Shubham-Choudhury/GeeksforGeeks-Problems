// Link: https://www.geeksforgeeks.org/problems/rectangles-in-a-circle0457/1

#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int rectanglesInCircle(int r)
    {
        int count, maxLength;
        double i;

        count = 0;
        for (i = 0.5; i <= r; i += 0.5)
        {
            maxLength = sqrt(r * r - i * i) * 2;
            count += maxLength;
        }

        return count;
    }
};

int main()
{
    Solution obj;
    int r = 1;
    cout << obj.rectanglesInCircle(r) << endl;
    r = 2;
    cout << obj.rectanglesInCircle(r) << endl;
    return 0;
}
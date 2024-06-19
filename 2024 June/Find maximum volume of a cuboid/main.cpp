// Link: https://www.geeksforgeeks.org/problems/magical-box5306/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double maxVolume(double perimeter, double area)
    {
        // double area = 2(l*b+b*h+h*l);
        // double perimeter = 4(l+b+h);
        // double volume = (l*b*h);
        double temp_value = perimeter - sqrt(perimeter * perimeter - (24 * area));
        double base_side_length = pow(temp_value / 12, 2);
        double height = perimeter / 4 - (2 * (temp_value / 12));
        double volume = base_side_length * height;
        return volume;
    }
};

int main()
{
    Solution obj;
    double perimeter = 22, area = 15;
    cout << obj.maxVolume(perimeter, area) << endl;
    perimeter = 20, area = 5;
    cout << obj.maxVolume(perimeter, area) << endl;

    return 0;
}
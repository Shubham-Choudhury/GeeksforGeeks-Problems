// Link: https://www.geeksforgeeks.org/problems/check-if-two-line-segments-intersect0017/1

#include <iostream>
using namespace std;

class Solution
{
public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[])
    {
        double m1 = (double)(q1[1] - p1[1]) / (double)(q1[0] - p1[0]);
        double m2 = (double)(q2[1] - p2[1]) / (double)(q2[0] - p2[0]);
        if (m1 == m2)
        {
            return "false";
        }

        bool chk211 = p2[1] - p1[1] - m1 * (p2[0] - p1[0]) > 0 ? true : false;
        bool chk212 = q2[1] - p1[1] - m1 * (q2[0] - p1[0]) > 0 ? true : false;
        bool chk121 = p1[1] - p2[1] - m2 * (p1[0] - p2[0]) > 0 ? true : false;
        bool chk122 = q1[1] - p2[1] - m2 * (q1[0] - p2[0]) > 0 ? true : false;

        if ((chk211 == true && chk212 == true) || (chk211 == false && chk212 == false) ||
            (chk121 == true && chk122 == true) || (chk121 == false && chk122 == false))
        {
            return "false";
        }
        return "true";
    }
};

int main()
{
    Solution obj;
    int p11[] = {1, 1};
    int q11[] = {10, 1};
    int p21[] = {1, 2};
    int q21[] = {10, 2};
    cout << obj.doIntersect(p11, q11, p21, q21) << endl;

    int p12[] = {10, 0};
    int q12[] = {0, 10};
    int p22[] = {0, 0};
    int q22[] = {10, 10};
    cout << obj.doIntersect(p12, q12, p22, q22) << endl;

    return 0;
}
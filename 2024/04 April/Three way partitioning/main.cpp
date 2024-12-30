// Link: https://www.geeksforgeeks.org/problems/three-way-partitioning/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        int n = array.size();

        int start = 0, end = n - 1;

        for (int i = 0; i <= end;)
        {
            if (array[i] < a)
                swap(array[i++], array[start++]);

            else if (array[i] > b)
                swap(array[i], array[end--]);

            else
                i++;
        }
    }
};

int main()
{
    Solution obj;
    vector<int> array = {1, 2, 3, 3, 4};
    int a = 1, b = 2;
    obj.threeWayPartition(array, a, b);

    array = {1, 4, 3, 6, 2, 1};
    a = 1, b = 3;
    obj.threeWayPartition(array, a, b);

    return 0;
}
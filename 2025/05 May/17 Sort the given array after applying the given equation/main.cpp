// Link: https://www.geeksforgeeks.org/problems/sort-the-given-array-after-applying-the-given-equation0304/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int evaluate(int x, int A, int B, int C)
    {
        return A * x * x + B * x + C;
    }

    vector<int> sortArray(vector<int> &arr, int A, int B, int C)
    {
        int n = arr.size();
        vector<int> newArr(n);

        int left = 0, right = n - 1;
        int index = (A >= 0) ? n - 1 : 0;

        while (left <= right)
        {
            int leftVal = evaluate(arr[left], A, B, C);
            int rightVal = evaluate(arr[right], A, B, C);

            if (A >= 0)
            {
                if (leftVal > rightVal)
                {
                    newArr[index--] = leftVal;
                    left++;
                }
                else
                {
                    newArr[index--] = rightVal;
                    right--;
                }
            }
            else
            {
                if (leftVal < rightVal)
                {
                    newArr[index++] = leftVal;
                    left++;
                }
                else
                {
                    newArr[index++] = rightVal;
                    right--;
                }
            }
        }

        return newArr;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {-4, -2, 0, 2, 4};
    int A = 1, B = 3, C = 5;
    vector<int> result = obj.sortArray(arr, A, B, C);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    arr = {-3, -1, 2, 4};
    A = -1, B = 0, C = 0;
    result = obj.sortArray(arr, A, B, C);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
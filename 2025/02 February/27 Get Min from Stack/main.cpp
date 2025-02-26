// Link: https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> stack;
    vector<int> minStack;

public:
    Solution()
    {
        stack.clear();
        minStack.clear();
    }

    // Add an element to the top of Stack
    void push(int x)
    {
        stack.push_back(x);

        if (minStack.empty() || x <= minStack.back())
        {
            minStack.push_back(x);
        }
    }

    // Remove the top element from the Stack
    void pop()
    {
        if (stack.empty())
        {
            return;
        }

        if (stack.back() == minStack.back())
        {
            minStack.pop_back();
        }
        stack.pop_back();
    }

    // Returns top element of the Stack
    int peek()
    {
        if (stack.empty())
        {
            return -1;
        }
        return stack.back();
    }

    // Finds minimum element of Stack
    int getMin()
    {
        if (minStack.empty())
        {
            return -1;
        }
        return minStack.back();
    }
};

int main()
{
    Solution object;
    object.push(2);
    object.push(3);
    cout << object.peek() << endl;
    cout << object.getMin() << endl;
    object.push(1);
    cout << object.getMin() << endl;

    return 0;
}
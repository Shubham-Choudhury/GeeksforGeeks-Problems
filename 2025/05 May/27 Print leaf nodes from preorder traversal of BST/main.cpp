// Link: https://www.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> leafNodes(vector<int> &preorder)
    {
        stack<int> s;
        vector<int> leaves;
        int n = preorder.size();

        for (int i = 0, j = 1; j < n; i++, j++)
        {
            bool found = false;
            if (preorder[i] > preorder[j])
            {
                s.push(preorder[i]);
            }
            else
            {

                while (!s.empty())
                {
                    if (preorder[j] > s.top())
                    {
                        s.pop();
                        found = true;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if (found)
            {
                leaves.push_back(preorder[i]);
            }
        }
        leaves.push_back(preorder[n - 1]);

        return leaves;
    }
};

int main()
{
    Solution sol;
    vector<int> preorder = {5, 2, 10};
    vector<int> result = sol.leafNodes(preorder);
    cout << "Leaf nodes: ";
    for (int leaf : result)
    {
        cout << leaf << " ";
    }
    cout << endl;

    preorder = {4, 2, 1, 3, 6, 5};
    result = sol.leafNodes(preorder);
    cout << "Leaf nodes: ";
    for (int leaf : result)
    {
        cout << leaf << " ";
    }
    cout << endl;

    preorder = {8, 2, 5, 10, 12};
    result = sol.leafNodes(preorder);
    cout << "Leaf nodes: ";
    for (int leaf : result)
    {
        cout << leaf << " ";
    }
    cout << endl;
    return 0;
}
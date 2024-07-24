// Link: https://www.geeksforgeeks.org/problems/array-to-bst4443/1

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
        : data(val), left(nullptr), right(nullptr) {}
};

bool help(Node *root, long long int up, long long int l)
{
    if (root->data >= up || root->data <= l)
        return false;
    bool ans = true;
    if (root->left)
        ans = help(root->left, root->data, l);
    if (ans && root->right)
        ans = help(root->right, up, root->data);
    return ans;
}

bool isValidBST(Node *root)
{
    return help(root, 3147483648, -3147483649);
}

int Height(Node *root)
{

    if (root == NULL)
        return 0;

    int leftHeight = Height(root->left);

    int rightHight = Height(root->right);

    if (leftHeight == -1 || rightHight == -1 || abs(leftHeight - rightHight) > 1)
        return -1;

    return max(leftHeight, rightHight) + 1;
}

bool isBalanced(Node *root)
{

    if (root == NULL)
        return true;

    if (Height(root) == -1)
        return false;
    return true;
}

class Solution
{
public:
    Node *solve(int s, int e, vector<int> &nums)
    {
        if (s >= e)
            return NULL;
        int mid = (s + e) / 2;
        Node *root = new Node(nums[mid]);
        root->left = solve(s, mid - 1, nums);
        root->right = solve(mid + 1, e, nums);
        return root;
    }

    Node *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        Node *root = solve(0, n - 1, nums);
        return root;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution obj;
    Node *root = obj.sortedArrayToBST(nums);
    cout << isValidBST(root) << endl;
    cout << isBalanced(root) << endl;

    nums = {1, 2, 3, 4};
    root = obj.sortedArrayToBST(nums);
    cout << isValidBST(root) << endl;
    cout << isBalanced(root) << endl;
    return 0;
}
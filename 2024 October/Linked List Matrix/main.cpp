// Link: https://www.geeksforgeeks.org/problems/linked-list-matrix/1

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *right, *down;

    Node(int x)
    {
        data = x;
        right = NULL;
        down = NULL;
    }
};

void display(Node *head)
{
    Node *Rp;
    Node *Dp = head;
    while (Dp)
    {
        Rp = Dp;
        while (Rp)
        {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

class Solution
{
public:
    Node *constructLinkedMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<Node *>> v(n, vector<Node *>(n, nullptr));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                v[i][j] = new Node(mat[i][j]);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i < n - 1)
                {
                    v[i][j]->down = v[i + 1][j];
                }

                if (j < n - 1)
                {
                    v[i][j]->right = v[i][j + 1];
                }
            }
        }

        return v[0][0];
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    Node *head = obj.constructLinkedMatrix(mat);
    display(head);

    mat = {{23, 28}, {23, 28}};
    head = obj.constructLinkedMatrix(mat);
    display(head);
    return 0;
}
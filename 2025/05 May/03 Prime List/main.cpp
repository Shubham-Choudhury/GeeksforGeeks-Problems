// Link: https://www.geeksforgeeks.org/problems/prime-list--170646/1

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}

Node *createList(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < arr.size(); i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n == 1 or n <= 0)
            return false;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    Node *primeList(Node *head)
    {
        Node *root = head;
        while (head != NULL)
        {
            int temp = head->val;

            if (isPrime(temp))
            {
                head = head->next;
                continue;
            }
            else
            {
                int temp2 = temp;
                while (!isPrime(temp) and !isPrime(temp2))
                {
                    temp++;
                    temp2--;
                }

                if (isPrime(temp) and isPrime(temp2))
                {
                    head->val = min(temp, temp2);
                }
                else if (isPrime(temp2))
                {
                    head->val = temp2;
                }
                else
                {
                    head->val = temp;
                }

                head = head->next;
            }
        }
        return root;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 6, 10};
    Node *head = createList(arr);
    cout << "Original List: ";
    printList(head);
    head = obj.primeList(head);
    cout << "Modified List: ";
    printList(head);

    arr = {1, 15, 20};
    head = createList(arr);
    cout << "Original List: ";
    printList(head);
    head = obj.primeList(head);
    cout << "Modified List: ";
    printList(head);
    return 0;
}
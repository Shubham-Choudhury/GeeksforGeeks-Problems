// Link: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int x)
  {
    data = x;
    next = nullptr;
  }
};

Node *createLinkedList(vector<int> arr)
{
  Node *head = new Node(arr[0]);
  Node *tail = head;

  for (int i = 1; i < arr.size(); i++)
  {
    tail->next = new Node(arr[i]);
    tail = tail->next;
  }

  return head;
}

void printLinkedList(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

class Solution
{
public:
  Node *segregate(Node *head)
  {
    if (!head || !(head->next))
      return head;

    Node *zeroD = new Node(0);
    Node *oneD = new Node(0);
    Node *twoD = new Node(0);

    Node *zero = zeroD, *one = oneD, *two = twoD;

    Node *curr = head;
    while (curr)
    {

      if (curr->data == 0)
      {
        zero->next = curr;
        zero = zero->next;
        curr = curr->next;
      }
      else if (curr->data == 1)
      {
        one->next = curr;
        one = one->next;
        curr = curr->next;
      }
      else
      {
        two->next = curr;
        two = two->next;
        curr = curr->next;
      }
    }

    zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
    one->next = twoD->next;
    two->next = NULL;

    head = zeroD->next;

    delete zeroD;
    delete oneD;
    delete twoD;

    return head;
  }
};

int main()
{
  Solution sol;

  vector<int> arr = {1, 2, 2, 1, 2, 0, 2, 2};
  Node *head = createLinkedList(arr);
  cout << "Original Linked List: " << endl;
  printLinkedList(head);
  head = sol.segregate(head);
  cout << "Sorted Linked List: " << endl;
  printLinkedList(head);
  cout << endl;

  arr = {2, 2, 0, 1};
  head = createLinkedList(arr);
  cout << "Original Linked List: " << endl;
  printLinkedList(head);
  head = sol.segregate(head);
  cout << "Sorted Linked List: " << endl;
  printLinkedList(head);
  cout << endl;

  return 0;
}
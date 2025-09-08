// Link: https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
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

vector<Node *> createKSortedLinkedLists(vector<vector<int>> lists)
{
  vector<Node *> heads;

  for (int i = 0; i < lists.size(); i++)
  {
    heads.push_back(createLinkedList(lists[i]));
  }

  return heads;
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

class Compare
{
public:
  bool operator()(Node *a, Node *b) { return a->data > b->data; }
};

class Solution
{
public:
  Node *mergeKLists(vector<Node *> &arr)
  {
    priority_queue<Node *, vector<Node *>, Compare> pq;

    for (Node *head : arr)
    {
      if (head != nullptr)
        pq.push(head);
    }

    Node *dummy = new Node(-1);
    Node *tail = dummy;

    while (!pq.empty())
    {
      Node *top = pq.top();
      pq.pop();

      tail->next = top;
      tail = top;

      if (top->next != nullptr)
      {
        pq.push(top->next);
      }
    }

    return dummy->next;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> lists = {
      {1, 3, 7},
      {2, 4, 8},
      {9}};
  vector<Node *> heads = createKSortedLinkedLists(lists);
  cout << "Linked Lists are: " << endl;
  for (Node *head : heads)
  {
    printLinkedList(head);
  }
  Node *mergedHead = sol.mergeKLists(heads);
  cout << "Merged Linked List is: " << endl;
  printLinkedList(mergedHead);
  cout << endl;

  lists = {
      {1, 3},
      {8},
      {4, 5, 6}};
  heads = createKSortedLinkedLists(lists);
  cout << "Linked Lists are: " << endl;
  for (Node *head : heads)
  {
    printLinkedList(head);
  }
  mergedHead = sol.mergeKLists(heads);
  cout << "Merged Linked List is: " << endl;
  printLinkedList(mergedHead);
  cout << endl;

  return 0;
}
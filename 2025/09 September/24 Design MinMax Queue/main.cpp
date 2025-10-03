// Link: https://www.geeksforgeeks.org/problems/design-minmax-queue/1

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

class SpecialQueue
{
    queue<int> q1;
    deque<int> q2;

public:
    void enqueue(int x)
    {
        q1.push(x);
        while (!q2.empty() && q2.back() > x)
        {
            q2.pop_back();
        }
        q2.push_back(x);
    }

    void dequeue()
    {
        if (q1.empty())
        {
            cout << "Queue is empty\n";
            return;
        }
        int frontVal = q1.front();
        if (frontVal == q2.front())
        {
            q2.pop_front();
        }
        q1.pop();
    }

    int getMin()
    {
        if (q1.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return q2.front();
    }

    int getFront()
    {
        if (q1.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return q1.front();
    }

    int getMax()
    {
        if (q1.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return q2.back();
    }
};

int main()
{
    SpecialQueue sq;
    sq.enqueue(4);
    sq.enqueue(2);
    cout << "Front: " << sq.getFront() << endl;
    cout << "Min: " << sq.getMin() << endl;
    sq.dequeue();
    cout << "Max: " << sq.getMax() << endl;

    SpecialQueue sq2;
    sq2.enqueue(3);
    cout << "Min: " << sq2.getMin() << endl;
    sq2.enqueue(5);
    cout << "Max: " << sq2.getMax() << endl;
    return 0;
}
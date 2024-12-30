# Link: https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, new_value):
        new_node = Node(new_value)
        if self.head is None:
            self.head = new_node
        else:
            self.tail.next = new_node
        self.tail = new_node


class Solution:
    def countPair(self, head1, head2, n1, n2, x):
        """
        head1:  head of linkedList 1
        head2:  head of linkedList 2
        n1:  len of  linkedList 1
        n2:  len of linkedList 1
        x:   given sum
        """
        d = {}
        count = 0
        while head1:
            d[x - head1.data] = d.get(x - head1.data, 0) + 1
            head1 = head1.next
        while head2:
            count += d.get(head2.data, 0)
            head2 = head2.next
        return count


if __name__ == "__main__":
    obj = Solution()
    # head1 = 1->2->3->4->5->6
    # head2 = 11->12->13
    h1 = [1, 2, 3, 4, 5, 6]
    head1 = LinkedList()
    for i in h1:
        head1.append(i)
    n1 = len(h1)
    h2 = [11, 12, 13]
    head2 = LinkedList()
    for i in h2:
        head2.append(i)
    n2 = len(h2)
    x = 15
    print(obj.countPair(head1, head2, n1, n2, x))

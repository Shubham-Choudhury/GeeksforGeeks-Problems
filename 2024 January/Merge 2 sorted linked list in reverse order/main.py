# Link: https://www.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def mergeResult(self, h1, h2):
        cur = Node(None)
        while h1 or h2:
            if h1 and h2:
                if h1.data <= h2.data:
                    nxt = h1
                    h1 = h1.next
                elif h1.data > h2.data:
                    nxt = h2
                    h2 = h2.next
            elif h1:
                nxt = h1
                h1 = h1.next
            else:
                nxt = h2
                h2 = h2.next
            nxt.next = cur.next
            cur.next = nxt
        return cur.next


if __name__ == "__main__":
    obj = Solution()
    N = 4
    M = 3
    list1 = Node(5)
    list1.next = Node(10)
    list1.next.next = Node(15)
    list1.next.next.next = Node(40)
    list2 = Node(2)
    list2.next = Node(3)
    list2.next.next = Node(20)
    result = obj.mergeResult(list1, list2)
    while result:
        print(result.data, end=" ")
        result = result.next
    print()

    N = 2
    M = 2
    list1 = Node(1)
    list1.next = Node(3)
    list2 = Node(2)
    list2.next = Node(4)
    result = obj.mergeResult(list1, list2)
    while result:
        print(result.data, end=" ")
        result = result.next

    print()

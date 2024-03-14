# Link: https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def reverse(self, head):
        cur = head
        prev = None
        while cur:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp
        return prev

    def merge(self, node1, node2):
        new = Node(-1)
        p = node1
        q = node2
        r = new
        while p and q:
            if p.data <= q.data:
                r.next = p
                r = r.next
                p = p.next
            else:
                r.next = q
                q = q.next
                r = r.next
        while p:
            r.next = p
            p = p.next
            r = r.next
        while q:
            r.next = q
            q = q.next
            r = r.next
        return new.next

    def sort(self, h1):
        if h1.next == None:
            return h1
        asi = h1
        des = h1.next
        des_p = des
        asi_p = asi
        if des.next == None or des.next.next == None:
            return h1
        while asi and des:
            asi.next = des.next
            if not asi.next:
                break
            des.next = asi.next.next
            if asi.next != None:
                asi = asi.next
            if des.next != None:
                des = des.next
        rev = self.reverse(des_p)
        return self.merge(asi_p, rev)


class Llist:
    def __init__(self):
        self.head = None

    def insert(self, data, tail):
        node = Node(data)

        if not self.head:
            self.head = node
            return node

        tail.next = node
        return node


def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next


if __name__ == "__main__":
    obj = Solution()
    l = [1, 9, 2, 8, 3, 7]
    n = len(l)
    ll = Llist()
    temp = ll.head
    for i in range(n - 1):
        temp = ll.insert(l[i], temp)
    ans = obj.sort(ll.head)
    printList(ans)
    print()
    l = [13, 99, 21, 80, 50]
    n = len(l)
    ll = Llist()
    temp = ll.head
    for i in range(n - 1):
        temp = ll.insert(l[i], temp)
    ans = obj.sort(ll.head)
    printList(ans)
    print()

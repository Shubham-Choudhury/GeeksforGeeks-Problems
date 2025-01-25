# Link: https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1


class Node:

    def __init__(self, val):
        self.next = None
        self.data = val


class linkedList:

    def __init__(self):
        self.head = None
        self.tail = None

    def add(self, num):
        if self.head is None:
            self.head = Node(num)
            self.tail = self.head
        else:
            self.tail.next = Node(num)
            self.tail = self.tail.next

    def isLoop(self):
        if self.head is None:
            return False

        fast = self.head.next
        slow = self.head

        while slow != fast:
            if fast is None or fast.next is None:
                return False
            fast = fast.next.next
            slow = slow.next

        return True

    def loopHere(self, position):
        if position == 0:
            return

        walk = self.head
        for _ in range(1, position):
            walk = walk.next
        self.tail.next = walk

    def length(self):
        walk = self.head
        ret = 0
        while walk:
            ret += 1
            walk = walk.next
        return ret


class Solution:
    def removeLoop(self, head):
        k = set()
        temp = head
        prev = None
        while temp:
            if temp in k:
                prev.next = None
                break
            k.add(temp)
            prev = temp
            temp = temp.next

        return head


if __name__ == "__main__":
    solution = Solution()
    linked_list = linkedList()
    arr = [1, 3, 4]
    for i in arr:
        linked_list.add(i)
    linked_list.loopHere(2)
    print(solution.removeLoop(linked_list.head))

    linked_list = linkedList()
    arr = [1, 8, 3, 4]
    for i in arr:
        linked_list.add(i)
    linked_list.loopHere(0)
    print(solution.removeLoop(linked_list.head))

    linked_list = linkedList()
    arr = [1, 2, 3, 4]
    for i in arr:
        linked_list.add(i)
    linked_list.loopHere(1)
    print(solution.removeLoop(linked_list.head))

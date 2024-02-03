# Link: https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1


class node:
    def __init__(self):
        self.data = None
        self.next = None


class Solution:
    def decimalValue(self, head):
        MOD = 10**9 + 7
        decimal_value = 0
        while head:
            decimal_value = (decimal_value * 2 + head.data) % MOD
            head = head.next
        return decimal_value


if __name__ == "__main__":
    obj = Solution()
    head = node()
    head.data = 0
    head.next = node()
    head.next.data = 1
    head.next.next = node()
    head.next.next.data = 1
    print(obj.decimalValue(head))
    head = node()
    head.data = 1
    head.next = node()
    head.next.data = 1
    head.next.next = node()
    head.next.next.data = 1
    head.next.next.next = node()
    head.next.next.next.data = 0
    print(obj.decimalValue(head))

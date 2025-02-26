# Link: https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1


class Solution:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    # Add an element to the top of Stack
    def push(self, x):
        self.stack.append(x)
        if not self.min_stack or x <= self.min_stack[-1]:
            self.min_stack.append(x)

    # Remove the top element from the Stack
    def pop(self):
        if not self.stack:
            return
        if self.stack[-1] == self.min_stack[-1]:
            self.min_stack.pop()
        self.stack.pop()

    # Returns top element of the Stack
    def peek(self):
        if not self.stack:
            return -1
        return self.stack[-1]

    # Finds minimum element of Stack
    def getMin(self):
        if not self.min_stack:
            return -1
        return self.min_stack[-1]


if __name__ == "__main__":
    object = Solution()
    object.push(2)
    object.push(3)
    print(object.peek())
    print(object.getMin())
    object.push(1)
    print(object.getMin())

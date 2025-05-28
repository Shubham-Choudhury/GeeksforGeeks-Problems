# Link: https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1


class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


def createBinaryTree(arr: list) -> Node:
    if len(arr) == 0 or arr[0] == "N":
        return None

    root = Node(int(arr[0]))
    queue = [root]
    i = 1

    while queue and i < len(arr):
        currNode = queue.pop(0)

        if arr[i] != "N":
            currNode.left = Node(int(arr[i]))
            queue.append(currNode.left)
        i += 1

        if i >= len(arr):
            break

        if arr[i] != "N":
            currNode.right = Node(int(arr[i]))
            queue.append(currNode.right)
        i += 1

    return root


class Solution:
    def sumOfRootToLeaf(self, root, sum, length, maxLen, maxSum):
        if not root:
            if length > maxLen[0]:
                maxLen[0] = length
                maxSum[0] = sum

            elif length == maxLen[0] and sum > maxSum[0]:
                maxSum[0] = sum
            return

        self.sumOfRootToLeaf(root.left, sum + root.data, length + 1, maxLen, maxSum)
        self.sumOfRootToLeaf(root.right, sum + root.data, length + 1, maxLen, maxSum)

    def sumOfLongRootToLeafPath(self, root):
        if not root:
            return 0
        maxSum = [-float("inf")]
        maxLen = [0]
        self.sumOfRootToLeaf(root, 0, 0, maxLen, maxSum)
        return maxSum[0]


if __name__ == "__main__":
    obj = Solution()
    arr = [4, 2, 5, 7, 1, 2, 3, "N", "N", 6, "N"]
    root = createBinaryTree(arr)
    print(obj.sumOfLongRootToLeafPath(root))

    arr = [1, 2, 3, 4, 5, 6, 7]
    root = createBinaryTree(arr)
    print(obj.sumOfLongRootToLeafPath(root))

    arr = [10, 5, 15, 3, 7, "N", 20, 1]
    root = createBinaryTree(arr)
    print(obj.sumOfLongRootToLeafPath(root))

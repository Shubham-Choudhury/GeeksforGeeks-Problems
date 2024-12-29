# Link: https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1


class Solution:
    def findUnion(self, a, b):
        a.extend(b)
        s = set(a)
        return len(s)


if __name__ == "__main__":
    object = Solution()
    a = [1, 2, 3, 4, 5]
    b = [1, 2, 3]
    print(object.findUnion(a, b))

    a = [85, 25, 1, 32, 54, 6]
    b = [85, 2]
    print(object.findUnion(a, b))

    a = [1, 2, 1, 1, 2]
    b = [2, 2, 1, 2, 1]
    print(object.findUnion(a, b))

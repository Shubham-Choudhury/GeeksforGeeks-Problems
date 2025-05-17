# Link: https://www.geeksforgeeks.org/problems/sort-the-given-array-after-applying-the-given-equation0304/1


class Solution:
    def evaluate(self, x, A, B, C):
        return A * x * x + B * x + C

    def sortArray(self, arr, A, B, C):
        transformed = [self.evaluate(x, A, B, C) for x in arr]

        transformed.sort()

        return transformed


if __name__ == "__main__":
    obj = Solution()
    arr = [-4, -2, 0, 2, 4]
    A = 1
    B = 3
    C = 5
    result = obj.sortArray(arr, A, B, C)
    print(result)

    arr = [-3, -1, 2, 4]
    A = -1
    B = 0
    C = 0
    result = obj.sortArray(arr, A, B, C)
    print(result)

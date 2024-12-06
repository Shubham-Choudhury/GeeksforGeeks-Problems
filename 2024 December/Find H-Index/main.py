# Link: https://www.geeksforgeeks.org/problems/find-h-index--165609/1

class Solution:
    def hIndex(self, citations):
        citations.sort(reverse=True)
        n = len(citations)
        for i in range(n):
            if citations[i] < i + 1:
                return i
        return n


if __name__ == "__main__":
    object = Solution()
    citations = [3, 0, 5, 3, 0]
    print(object.hIndex(citations))

    citations = [5, 1, 2, 4, 1]
    print(object.hIndex(citations))

    citations = [0, 0, 0]
    print(object.hIndex(citations))

# Link: https://www.geeksforgeeks.org/problems/find-h-index--165609/1


class Solution:
    def hIndex(self, citations):
        n = len(citations)
        freq = [0] * (n + 1)

        for citation in citations:
            if citation >= n:
                freq[n] += 1
            else:
                freq[citation] += 1

        idx = n

        s = freq[n]
        while s < idx:
            idx -= 1
            s += freq[idx]

        return idx


if __name__ == "__main__":
    sol = Solution()
    citations = [3, 0, 5, 3, 0]
    result = sol.hIndex(citations)
    print(f"The H-Index is: {result}")

    citations = [5, 1, 2, 4, 1]
    result = sol.hIndex(citations)
    print(f"The H-Index is: {result}")

    citations = [0, 0]
    result = sol.hIndex(citations)
    print(f"The H-Index is: {result}")

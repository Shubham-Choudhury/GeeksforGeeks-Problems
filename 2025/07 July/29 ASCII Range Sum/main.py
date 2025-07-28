# Link: https://www.geeksforgeeks.org/problems/ascii-range-sum/1


class Solution:
    def asciirange(self, s):
        result = []
        n = len(s)

        first = [-1] * 26
        last = [-1] * 26

        for i in range(n):
            idx = ord(s[i]) - ord("a")
            if first[idx] == -1:
                first[idx] = i
            else:
                last[idx] = i

        for i in range(26):
            if first[i] != -1 and last[i] != -1:
                sumval = 0
                for j in range(first[i] + 1, last[i]):
                    sumval += ord(s[j])
                if sumval != 0:
                    result.append(sumval)

        return result


if __name__ == "__main__":
    solution = Solution()
    s = "abacab"
    result = solution.asciirange(s)
    print(f"ASCII Range Sum for '{s}': {result}")

    s = "acdac"
    result = solution.asciirange(s)
    print(f"ASCII Range Sum for '{s}': {result}")

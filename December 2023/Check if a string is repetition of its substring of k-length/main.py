# Link: https://www.geeksforgeeks.org/problems/check-if-a-string-is-repetition-of-its-substring-of-k-length3302/1


class Solution:
    def kSubstrConcat(self, n, s, k):
        if n % k != 0:
            return 0
        unique_substrings, unique_substring_count = set(), 0
        for i in range(0, n, k):
            current_substring = s[i : i + k]
            if current_substring not in unique_substrings:
                if unique_substring_count == 2:
                    return 0
                else:
                    unique_substring_count += 1
                unique_substrings.add(current_substring)
        return 1


if __name__ == "__main__":
    obj = Solution()
    N = 4
    K = 2
    S = "bdac"
    print(obj.kSubstrConcat(N, S, K))

    N = 5
    K = 2
    S = "abcde"
    print(obj.kSubstrConcat(N, S, K))

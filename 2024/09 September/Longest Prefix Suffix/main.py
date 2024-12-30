# Link: https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1


class Solution:
    def lps(self, str):
        lps = [0] * len(str)
        prefix, suffix = 0, 1

        while suffix < len(lps):
            if str[prefix] == str[suffix]:
                lps[suffix] = prefix + 1
                prefix += 1
                suffix += 1
            else:
                if prefix == 0:
                    lps[suffix] = 0
                    suffix += 1
                else:
                    prefix = lps[prefix - 1]

        return lps[-1]


if __name__ == "__main__":
    obj = Solution()
    str = "abab"
    print(obj.lps(str))

    str = "aaaa"
    print(obj.lps(str))

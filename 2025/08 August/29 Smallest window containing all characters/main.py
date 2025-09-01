# Link: https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1


class Solution:
    def smallestWindow(self, s, p):
        len1 = len(s)
        len2 = len(p)

        if len1 < len2:
            return ""

        countP = [0] * 256
        countS = [0] * 256

        for char in p:
            countP[ord(char)] += 1

        start = 0
        start_idx = -1
        min_len = float("inf")
        count = 0

        for j in range(len1):
            countS[ord(s[j])] += 1

            if countP[ord(s[j])] != 0 and countS[ord(s[j])] <= countP[ord(s[j])]:
                count += 1

            if count == len2:
                while (
                    countS[ord(s[start])] > countP[ord(s[start])]
                    or countP[ord(s[start])] == 0
                ):
                    if countS[ord(s[start])] > countP[ord(s[start])]:
                        countS[ord(s[start])] -= 1
                    start += 1

                length = j - start + 1
                if min_len > length:
                    min_len = length
                    start_idx = start

        if start_idx == -1:
            return ""

        return s[start_idx : start_idx + min_len]


if __name__ == "__main__":
    sol = Solution()
    s = "timetopractice"
    p = "toc"
    result = sol.smallestWindow(s, p)
    print(f"Smallest window in '{s}' containing all characters of '{p}' is: '{result}'")

    s = "zoomlazapzo"
    p = "oza"
    result = sol.smallestWindow(s, p)
    print(f"Smallest window in '{s}' containing all characters of '{p}' is: '{result}'")

    s = "zoom"
    p = "zooe"
    result = sol.smallestWindow(s, p)
    print(f"Smallest window in '{s}' containing all characters of '{p}' is: '{result}'")

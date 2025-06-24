# Link: https://www.geeksforgeeks.org/problems/check-frequencies4211/1


class Solution:
    def sameFreq(self, s: str) -> bool:
        freq = [0] * 26

        for char in s:
            freq[ord(char) - ord("a")] += 1

        maxFreq = float("-inf")
        minFreq = float("inf")
        maxFreq_count = 0
        minFreq_count = 0

        for f in freq:
            if f == 0:
                continue

            if f == maxFreq:
                maxFreq_count += 1

            if f == minFreq:
                minFreq_count += 1

            if f > maxFreq:
                maxFreq = f
                maxFreq_count = 1

            if f < minFreq:
                minFreq = f
                minFreq_count = 1

        if maxFreq - minFreq == 0:
            return True
        elif maxFreq - minFreq == 1 and (
            maxFreq_count == 1 or (minFreq_count == 1 and minFreq == 1)
        ):
            return True
        else:
            return False


if __name__ == "__main__":
    obj = Solution()
    s = "xyyz"
    result = obj.sameFreq(s)
    print(
        "Frequencies can be made equal"
        if result
        else "Frequencies cannot be made equal"
    )

    s = "xyyzz"
    result = obj.sameFreq(s)
    print(
        "Frequencies can be made equal"
        if result
        else "Frequencies cannot be made equal"
    )

    s = "xxxxyyzz"
    result = obj.sameFreq(s)
    print(
        "Frequencies can be made equal"
        if result
        else "Frequencies cannot be made equal"
    )

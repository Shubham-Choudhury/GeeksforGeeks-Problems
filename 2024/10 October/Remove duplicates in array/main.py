# Link: https://www.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/1


class Solution:
    def removeDuplicate(self, arr):
        seen = set()
        ans = []

        for num in arr:
            if num not in seen:
                ans.append(num)
                seen.add(num)

        return ans


if __name__ == "__main__":
    obj = Solution()
    arr = [2, 2, 3, 3, 7, 5]
    ans = obj.removeDuplicate(arr)
    print(" ".join(map(str, ans)))

    arr = [2, 2, 5, 5, 7, 7]
    ans = obj.removeDuplicate(arr)
    print(" ".join(map(str, ans)))

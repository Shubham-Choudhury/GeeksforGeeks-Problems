# Link: https://www.geeksforgeeks.org/problems/majority-vote/1


class Solution:
    def findMajority(self, nums):
        n = len(nums)
        if n == 0:
            return [-1]

        candidate1, candidate2, count1, count2 = -1, -1, 0, 0

        for num in nums:
            if num == candidate1:
                count1 += 1
            elif num == candidate2:
                count2 += 1
            elif count1 == 0:
                candidate1 = num
                count1 = 1
            elif count2 == 0:
                candidate2 = num
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1

        count1, count2 = 0, 0

        for num in nums:
            if num == candidate1:
                count1 += 1
            elif num == candidate2:
                count2 += 1

        result = []
        if count1 > n / 3:
            result.append(candidate1)
        if count2 > n / 3:
            result.append(candidate2)

        return result if result else [-1]


if __name__ == "__main__":
    obj = Solution()
    nums = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
    result = obj.findMajority(nums)
    print(" ".join(map(str, result)))
    nums = [1, 2, 3, 4, 5]
    result = obj.findMajority(nums)
    print(" ".join(map(str, result)))

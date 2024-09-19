# Link: https://www.geeksforgeeks.org/problems/facing-the-sun2126/1


class Solution:
    def countBuildings(self, height):
        maxi = float("-inf")
        ans = 0
        for it in height:
            if maxi < it:
                ans += 1
            maxi = max(maxi, it)

        return ans


if __name__ == "__main__":
    obj = Solution()
    height = [7, 4, 8, 2, 9]
    print(obj.countBuildings(height))

    height = [2, 3, 4, 5]
    print(obj.countBuildings(height))

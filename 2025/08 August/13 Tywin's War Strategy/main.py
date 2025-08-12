# Link: https://www.geeksforgeeks.org/problems/tywins-war-strategy0527/1


class Solution:
    def minSoldiers(self, arr, k):
        n = len(arr)
        need = (n + 1) // 2
        costs = []

        for num in arr:
            if num % k == 0:
                costs.append(0)
            else:
                costs.append(k - (num % k))

        costs.sort()

        total = sum(costs[:need])

        return total


if __name__ == "__main__":
    sol = Solution()
    arr = [5, 6, 3, 2, 1]
    k = 2
    result = sol.minSoldiers(arr, k)
    print(result)

    arr = [3, 5, 6, 7, 9, 10]
    k = 4
    result = sol.minSoldiers(arr, k)
    print(result)

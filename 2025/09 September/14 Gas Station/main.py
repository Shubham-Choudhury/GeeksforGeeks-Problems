# Link: https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1


class Solution:
    def startStation(self, gas, cost):
        n = len(gas)

        totalGas = 0
        currGas = 0
        startIdx = 0

        for i in range(n):
            currGas += gas[i] - cost[i]
            totalGas += gas[i] - cost[i]

            if currGas < 0:
                currGas = 0
                startIdx = i + 1

        if totalGas < 0:
            return -1

        return startIdx


if __name__ == "__main__":
    sol = Solution()
    gas = [4, 5, 7, 4]
    cost = [6, 6, 3, 5]
    result = sol.startStation(gas, cost)
    print(f"Starting gas station index: {result}")

    gas = [3, 9]
    cost = [7, 6]
    result = sol.startStation(gas, cost)
    print(f"Starting gas station index: {result}")

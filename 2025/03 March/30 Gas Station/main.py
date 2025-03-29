# Link: https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1


class Solution:
    def startStation(self, gas, cost):
        check = 0
        n = len(gas)
        for i in range(n):
            check += gas[i] - cost[i]
        if check < 0:
            return -1
        index = 0
        store = 0
        for i in range(n):
            store += gas[i] - cost[i]
            if store < 0:
                index = i + 1
                store = 0
        return index


if __name__ == "__main__":
    obj = Solution()
    gas = [4, 5, 7, 4]
    cost = [6, 6, 3, 5]
    result = obj.startStation(gas, cost)
    print("Starting station index:", result)

    gas = [1, 2, 3, 4, 5]
    cost = [3, 4, 5, 1, 2]
    result = obj.startStation(gas, cost)
    print("Starting station index:", result)

    gas = [3, 9]
    cost = [7, 6]
    result = obj.startStation(gas, cost)
    print("Starting station index:", result)

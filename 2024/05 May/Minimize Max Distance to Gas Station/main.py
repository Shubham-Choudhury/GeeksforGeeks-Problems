# Link: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1


class Solution:
    def findSmallestMaxDist(self, stations, K):
        start, end = 0, stations[-1] - stations[0]
        while end - start > 1e-5:
            mid = (start + end) / 2
            if self.isPossible(stations, K, mid):
                end = mid
            else:
                start = mid
        return end

    def isPossible(self, stations, k, maxDist):
        stationsToAdd = 0
        for i in range(1, len(stations)):
            stationsToAdd += (stations[i] - stations[i - 1]) // maxDist
        return stationsToAdd <= k


if __name__ == "__main__":
    obj = Solution()
    stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    K = 9
    print(obj.findSmallestMaxDist(stations, K))

    stations = [3, 6, 12, 19, 33, 44, 67, 72, 89, 95]
    K = 2
    print(obj.findSmallestMaxDist(stations, K))

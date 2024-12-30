# Link: https://www.geeksforgeeks.org/problems/water-the-plants--170646/1


class Solution:
    def min_sprinklers(self, gallery, n):
        sprinklers = []
        for i in range(n):
            if gallery[i] != -1:
                sprinklers.append((i - gallery[i], i + gallery[i]))

        sprinklers.sort()

        target, idx, result = 0, 0, 0

        while target < n:
            if idx == len(sprinklers) or sprinklers[idx][0] > target:
                return -1

            max_range = sprinklers[idx][1]
            while idx + 1 < len(sprinklers) and sprinklers[idx + 1][0] <= target:
                idx += 1
                max_range = max(max_range, sprinklers[idx][1])
            target = max_range + 1
            result += 1
            idx += 1

        return result


if __name__ == "__main__":
    obj = Solution()
    gallery = [2, 3, 4, -1, 2, 0, 0, -1, 0]
    n = len(gallery)
    print(obj.min_sprinklers(gallery, n))
    gallery = [2, 3, 4, -1, 0, 0, 0, 0, 0]
    n = len(gallery)
    print(obj.min_sprinklers(gallery, n))

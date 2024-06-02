# Link: https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1

from typing import List


class Solution:
    def constructList(self, q: int, queries: List[List[int]]) -> List[int]:
        xr = 0
        ans = []
        for i in range(len(queries) - 1, -1, -1):
            if queries[i][0] == 0:
                ans.append(queries[i][1] ^ xr)
            else:
                xr ^= queries[i][1]

        ans.append(xr)
        ans.sort()
        return ans


if __name__ == "__main__":
    obj = Solution()
    queries = [[0, 6], [0, 3], [0, 2], [1, 4], [1, 5]]
    q = len(queries)
    print(obj.constructList(q, queries))

    queries = [[0, 2], [1, 3], [0, 5]]
    q = len(queries)
    print(obj.constructList(q, queries))

# Link: https://www.geeksforgeeks.org/problems/alien-dictionary/1

from collections import deque
from typing import List


class Solution:
    def findOrder(self, alien_dict: List[str], N: int, K: int) -> str:
        adj = [[] for _ in range(K)]
        for i in range(N - 1):
            s1 = alien_dict[i]
            s2 = alien_dict[i + 1]

            length = min(len(s1), len(s2))

            for ptr in range(length):
                if s1[ptr] != s2[ptr]:
                    adj[ord(s1[ptr]) - ord("a")].append(ord(s2[ptr]) - ord("a"))
                    break

        ans = []
        q = deque()
        inDegree = [0] * K

        for i in range(K):
            for it in adj[i]:
                inDegree[it] += 1

        for i in range(K):
            if inDegree[i] == 0:
                q.append(i)

        while q:
            node = q.popleft()
            ans.append(node)

            for it in adj[node]:
                inDegree[it] -= 1
                if inDegree[it] == 0:
                    q.append(it)

        result = ""
        for it in ans:
            result += chr(it + ord("a"))

        return result


if __name__ == "__main__":
    obj = Solution()
    N = 5
    K = 4
    dict1 = ["baa", "abcd", "abca", "cab", "cad"]
    print(obj.findOrder(dict1, N, K))

    N = 3
    K = 3
    dict2 = ["caa", "aaa", "aab"]
    print(obj.findOrder(dict2, N, K))

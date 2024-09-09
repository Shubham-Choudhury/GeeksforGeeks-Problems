# Link: https://www.geeksforgeeks.org/problems/circle-of-strings4530/1

from collections import defaultdict, deque

class Solution:
    def isCircle(self, arr):
        n = len(arr)
        start = defaultdict(int)
        end = defaultdict(int)
        
        for s in arr:
            start[s[0]] += 1
            end[s[-1]] += 1
        
        for char in start:
            if start[char] != end[char]:
                return 0
        
        graph = defaultdict(list)
        visited = [False] * n
        
        for i in range(n):
            graph[arr[i][0]].append(i)
        
        q = deque([0])
        visited[0] = True
        count = 1
        
        while q:
            idx = q.popleft()
            lastChar = arr[idx][-1]
            for nextIdx in graph[lastChar]:
                if not visited[nextIdx]:
                    visited[nextIdx] = True
                    q.append(nextIdx)
                    count += 1
        
        return 1 if count == n else 0

if __name__ == "__main__":
    obj = Solution()
    arr = ["abc", "bcd", "cdf"]
    print(obj.isCircle(arr))
    arr = ["ab", "bc", "cd", "da"]
    print(obj.isCircle(arr))


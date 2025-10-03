# Link: https://www.geeksforgeeks.org/problems/queue-reversal/1


class Solution:
    def reverseQueue(self, q):
        st = []

        while q:
            st.append(q[0])
            q.popleft()

        while st:
            q.append(st.pop())


if __name__ == "__main__":
    from collections import deque

    sol = Solution()
    arr = [5, 10, 15, 20, 25]
    q = deque(arr)
    sol.reverseQueue(q)
    print(f"Reversed Queue: {list(q)}")

    arr = [1, 2, 3, 4, 5]
    q = deque(arr)
    sol.reverseQueue(q)
    print(f"Reversed Queue: {list(q)}")

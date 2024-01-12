# Link: https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

"""
Function Arguments :
        @param  : q ( given queue to be used), k(Integer )
        @return : list, just reverse the first k elements of queue and return new queue
"""


class Solution:
    def modifyQueue(self, q, k):
        # code here
        ans = []
        wer = []
        n = len(q)
        for i in range(k):
            ans.append(q.pop(0))
        while q:
            wer.append(q.pop(0))
        while ans:
            q.append(ans.pop())

        for i in range(0, len(wer)):
            q.append(wer[i])
        return q


if __name__ == "__main__":
    obj = Solution()
    q = [1, 2, 3, 4, 5]
    k = 3
    print(obj.modifyQueue(q, k))
    q = [4, 3, 2, 1]
    k = 4
    print(obj.modifyQueue(q, k))

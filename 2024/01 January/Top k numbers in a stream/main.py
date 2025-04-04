# Link: https://www.geeksforgeeks.org/problems/top-k-numbers3425/1


class Solution:
    def kTop(self, a, N, K):
        final_ans = []
        top = [0 for i in range(K + 1)]
        freq = {i: 0 for i in range(K + 1)}
        for m in range(N):
            if a[m] in freq.keys():
                freq[a[m]] += 1
            else:
                freq[a[m]] = 1
            top[K] = a[m]

            i = top.index(a[m])
            i -= 1

            while i >= 0:
                if freq[top[i]] < freq[top[i + 1]]:
                    top[i], top[i + 1] = top[i + 1], top[i]

                elif (freq[top[i]] == freq[top[i + 1]]) and (top[i] > top[i + 1]):
                    top[i], top[i + 1] = top[i + 1], top[i]
                else:
                    break
                i -= 1

            i = 0
            ans = []
            while i < K and top[i] != 0:
                ans.append(top[i])
                i += 1

            final_ans += [ans]
        return final_ans


if __name__ == "__main__":
    obj = Solution()
    N = 5
    K = 4
    arr = [5, 2, 1, 3, 2]
    ans = obj.kTop(arr, N, K)
    for i in ans:
        print(i, end=" ")
    print()

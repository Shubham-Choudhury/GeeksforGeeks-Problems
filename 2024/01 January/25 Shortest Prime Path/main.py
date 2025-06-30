# Link: https://www.geeksforgeeks.org/problems/shortest-prime-path--141631/1


class Solution:
    def solve(self, Num1, Num2):
        if Num1 == Num2:
            return 0

        sieve = [1] * 10000
        sieve[0] = 0
        sieve[1] = 0
        for i in range(2, 10000):
            if sieve[i]:
                for j in range(i * i, 10000, i):
                    sieve[j] = 0

        ans = -1
        str1 = str(Num1)
        str2 = str(Num2)
        mp = {}
        q = []
        q.append((str1, 0))
        mp[str1] = 1
        while q:
            s, step = q.pop(0)
            if s == str2:
                ans = step
                break

            for i in range(4):
                for j in range(10):
                    if i == 0 and j == 0:
                        continue
                    ch = list(s)
                    ch[i] = str(j)
                    new_str = "".join(ch)
                    if sieve[int(new_str)] and not mp.get(new_str):
                        q.append((new_str, step + 1))
                        mp[new_str] = 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    Num1 = 1033
    Num2 = 8179
    print(obj.solve(Num1, Num2))
    Num1 = 1033
    Num2 = 1033
    print(obj.solve(Num1, Num2))

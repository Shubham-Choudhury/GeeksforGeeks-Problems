# Link: https://www.geeksforgeeks.org/problems/account-merge/1

from collections import defaultdict


class DisjointSet:
    def __init__(self, n: int):
        self.rank = [0] * (n + 1)
        self.parent = list(range(n + 1))

    def find_upar(self, node: int) -> int:
        if node == self.parent[node]:
            return node
        self.parent[node] = self.find_upar(self.parent[node])
        return self.parent[node]

    def union_by_rank(self, u: int, v: int) -> None:
        u_v = self.find_upar(u)
        u_u = self.find_upar(v)
        if u_v == u_u:
            return
        if self.rank[u_v] > self.rank[u_u]:
            self.parent[u_u] = u_v
        elif self.rank[u_v] < self.rank[u_u]:
            self.parent[u_v] = u_u
        else:
            self.parent[u_v] = u_u
            self.rank[u_u] += 1


class Solution:
    def accountsMerge(self, accounts):
        n = len(accounts)
        helper = {}
        ds = DisjointSet(n)

        for i in range(n):
            for j in range(1, len(accounts[i])):
                mail = accounts[i][j]
                if mail not in helper:
                    helper[mail] = i
                else:
                    ds.union_by_rank(i, helper[mail])

        merged = defaultdict(list)
        for mail, node in helper.items():
            merged[ds.find_upar(node)].append(mail)

        ans = []
        for i in range(n):
            if not merged[i]:
                continue
            merged[i].sort()
            temp = [accounts[i][0]] + merged[i]
            ans.append(temp)

        return ans


if __name__ == "__main__":
    obj = Solution()
    accounts = [
        ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
        ["John", "johnsmith@mail.com", "john00@mail.com"],
        ["Mary", "mary@mail.com"],
        ["John", "johnnybravo@mail.com"],
    ]
    ans = obj.accountsMerge(accounts)
    for i in ans:
        print(i)
    print()

    accounts = [
        ["Gabe", "Gabe00@m.co", "Gabe3@m.co", "Gabe1@m.co"],
        ["Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"],
        ["Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"],
        ["Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"],
        ["Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"],
    ]
    ans = obj.accountsMerge(accounts)
    for i in ans:
        print(i)
    print()

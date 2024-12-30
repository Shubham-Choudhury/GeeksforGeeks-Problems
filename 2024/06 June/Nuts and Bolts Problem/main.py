# Link: https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1


class Solution:
    def matchPairs(self, n, nuts, bolts):
        order = {"!": 0, "#": 1, "$": 2, "%": 3, "&": 4, "*": 5, "?": 6, "@": 7, "^": 8}

        nuts.sort(key=lambda x: order[x])
        bolts.sort(key=lambda x: order[x])


if __name__ == "__main__":
    obj = Solution()
    nuts = ["@", "%", "$", "#", "^"]
    bolts = ["%", "@", "#", "$", "^"]
    n = len(nuts)
    obj.matchPairs(n, nuts, bolts)
    print(nuts, bolts)

    nuts = ["^", "&", "%", "@", "#", "*", "$", "?", "!"]
    bolts = ["?", "#", "@", "%", "&", "*", "$", "^", "!"]
    n = len(nuts)
    obj.matchPairs(n, nuts, bolts)
    print(nuts, bolts)

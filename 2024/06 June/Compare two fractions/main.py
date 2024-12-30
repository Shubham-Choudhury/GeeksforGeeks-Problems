# Link: https://www.geeksforgeeks.org/problems/compare-two-fractions4438/1


class Solution:
    def compareFrac(self, str):
        fractions = str.split(", ")
        frac1 = fractions[0].split("/")
        frac2 = fractions[1].split("/")

        a, b = int(frac1[0]), int(frac1[1])
        c, d = int(frac2[0]), int(frac2[1])

        if a * d > b * c:
            return "{}/{}".format(a, b)
        elif a * d < b * c:
            return "{}/{}".format(c, d)
        else:
            return "equal"


if __name__ == "__main__":
    obj = Solution()
    s = "5/6, 11/45"
    print(obj.compareFrac(s))

    s = "8/1, 8/1"
    print(obj.compareFrac(s))

    s = "10/17, 9/10"
    print(obj.compareFrac(s))

    s = "0/43, 0/43"
    print(obj.compareFrac(s))

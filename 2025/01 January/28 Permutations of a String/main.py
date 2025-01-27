# Link: https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1


class Solution:
    def findPermutation(self, s):
        s = "".join(sorted(s))
        stack = [(s, "")]
        result = []

        while stack:
            remaining, path = stack.pop()

            if not remaining:
                result.append(path)
                continue

            used = set()
            for i in range(len(remaining)):
                if remaining[i] in used:
                    continue

                used.add(remaining[i])
                stack.append((remaining[:i] + remaining[i + 1 :], path + remaining[i]))

        return result


if __name__ == "__main__":
    object = Solution()
    s = "ABC"
    ans = object.findPermutation(s)
    print(" ".join(ans))

    s = "ABSG"
    ans = object.findPermutation(s)
    print(" ".join(ans))

    s = "AAA"
    ans = object.findPermutation(s)
    print(" ".join(ans))

# Link: https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1


def max_sum(a, n):
    total = sum(a)
    cur = sum(i * a[i] for i in range(n))
    ans = cur

    for i in range(1, n):
        cur = cur - (total - a[i - 1]) + a[i - 1] * (n - 1)
        ans = max(ans, cur)

    return ans


if __name__ == "__main__":
    a = [8, 3, 1, 2]
    n = len(a)
    print(max_sum(a, n))

    a = [1, 2, 3]
    n = len(a)
    print(max_sum(a, n))

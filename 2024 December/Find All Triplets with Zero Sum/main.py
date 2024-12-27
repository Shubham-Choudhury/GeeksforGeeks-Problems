# Link: https://www.geeksforgeeks.org/problems/find-all-triplets-with-zero-sum/1


class Solution:
    def findTriplets(self, arr):
        n = len(arr)
        mpp = {arr[i]: i for i in range(n)}
        st = set()

        for i in range(n):
            for j in range(i + 1, n):
                third = -(arr[i] + arr[j])
                if third in mpp and mpp[third] != i and mpp[third] != j:
                    temp = tuple(sorted([i, j, mpp[third]]))
                    st.add(temp)
                mpp[arr[j]] = j

        return [list(triplet) for triplet in st]


if __name__ == "__main__":
    object = Solution()
    arr = [0, -1, 2, -3, 1]
    result = object.findTriplets(arr)
    for triplet in result:
        print(" ".join(map(str, triplet)))
    print()

    arr = [1, -2, 1, 0, 5]
    result = object.findTriplets(arr)
    for triplet in result:
        print(" ".join(map(str, triplet)))
    print()

    arr = [2, 3, 1, 0, 5]
    result = object.findTriplets(arr)
    for triplet in result:
        print(" ".join(map(str, triplet)))
    print()

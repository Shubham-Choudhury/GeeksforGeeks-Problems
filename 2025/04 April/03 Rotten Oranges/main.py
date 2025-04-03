# Link: https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

class Solution:
    def orangesRotting(self, mat):
        rows, cols = len(mat), len(mat[0])
        queue, fresh, time = [], 0, 0
    
        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 2:
                    queue.append((i, j))
                elif mat[i][j] == 1:
                    fresh += 1
    
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        while queue and fresh:
            new_queue = []
            for r, c in queue:
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < cols and mat[nr][nc] == 1:
                        mat[nr][nc] = 2
                        fresh -= 1
                        new_queue.append((nr, nc))
            queue = new_queue
            time += 1
    
        return time if fresh == 0 else -1

if __name__ == "__main__":
    obj = Solution()
    mat = [[0, 1, 2], [0, 1, 2], [2, 1, 1]]
    result = obj.orangesRotting(mat)
    print(result)

    mat = [[2, 2, 0, 1]]
    result = obj.orangesRotting(mat)
    print(result)

    mat = [[2, 2, 2], [0, 2, 0]]
    result = obj.orangesRotting(mat)
    print(result)
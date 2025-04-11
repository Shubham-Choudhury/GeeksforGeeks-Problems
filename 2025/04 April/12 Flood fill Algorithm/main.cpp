// Link: https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {

        if (image[sr][sc] == newColor)
        {
            return image;
        }

        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        queue<pair<int, int>> q;
        int oldColor = image[sr][sc];
        q.push({sr, sc});

        image[sr][sc] = newColor;

        while (!q.empty())
        {
            pair<int, int> front = q.front();
            int x = front.first, y = front.second;
            q.pop();

            for (const pair<int, int> &direction : directions)
            {
                int nx = x + direction.first;
                int ny = y + direction.second;

                if (nx >= 0 && nx < image.size() &&
                    ny >= 0 && ny < image[0].size() &&
                    image[nx][ny] == oldColor)
                {

                    image[nx][ny] = newColor;
                    q.push({nx, ny});
                }
            }
        }

        return image;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> image = {{1, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    int sr = 1;
    int sc = 2;
    int newColor = 2;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);
    for (const auto &row : result)
    {
        for (const auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;

    image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    sr = 1;
    sc = 1;
    newColor = 2;
    result = sol.floodFill(image, sr, sc, newColor);
    for (const auto &row : result)
    {
        for (const auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;

    image = {{0, 1, 0}, {0, 1, 0}};
    sr = 0;
    sc = 1;
    newColor = 0;
    result = sol.floodFill(image, sr, sc, newColor);
    for (const auto &row : result)
    {
        for (const auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
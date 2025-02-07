#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> queryResults(int maxBalls, vector<vector<int>> &colorUpdates)
    {
        vector<int> distinctColorCounts;
        unordered_map<int, int> ballToColor;    // Maps ball ID to its current color
        unordered_map<int, int> colorFrequency; // Tracks how many balls have each color

        for (const auto &update : colorUpdates)
        {
            int ballId = update[0];
            int newColor = update[1];

            // Remove old color count
            int oldColor = ballToColor[ballId];
            if (colorFrequency.count(oldColor))
            {
                colorFrequency[oldColor]--;
                if (colorFrequency[oldColor] == 0)
                {
                    colorFrequency.erase(oldColor);
                }
            }

            // Update with new color
            ballToColor[ballId] = newColor;
            colorFrequency[newColor]++;

            distinctColorCounts.push_back(colorFrequency.size());
        }
        return distinctColorCounts;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> queries = {{1, 1}, {2, 2}, {3, 3}};
    int limit = 3;
    cout << "\nTest case 1:" << endl;
    vector<int> result = solution.queryResults(limit, queries);

    cout << "Results: ";
    for (int &count : result)
        cout << count << " ";

    cout << endl;

    cout << "\nTest case 2:" << endl;
    queries = {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}};
    limit = 4;
    result = solution.queryResults(limit, queries);

    cout << "Results: ";
    for (int count : result)
    {
        cout << count << " ";
    }
    cout << endl;

    cout << "\nTest case 3:" << endl;
    queries = {{1, 4}, {2, 5}, {1, 3}, {3, 4}};
    limit = 4;
    result = solution.queryResults(limit, queries);
    vector<int> expected = {1, 2, 2, 3};

    cout << "Results: ";
    for (int count : result)
    {
        cout << count << " ";
    }
    cout << endl;

    // Validate output
    if (result == expected)
    {
        cout << "Test case 3 passed!" << endl;
    }
    else
    {
        cout << "Test case 3 failed!" << endl;
        cout << "Expected: ";
        for (int num : expected)
        {
            cout << num << " ";
        }
        cout << "\nActual:   ";
        for (int num : result)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve() {
    // Read input size and target sum
    int size, targetSum;
    cin >> size >> targetSum;

    // Read array elements
    vector<int> numbers(size);
    for (auto &num : numbers) {
        cin >> num;
    }

    // Initialize window boundaries
    // start: inclusive start of the window
    // end: exclusive end of the window (points to element after last valid element)
    int start = 0, end = 0;

    // Current sum of elements in the window
    int64_t windowSum = 0;

    // Count of valid subarrays (where sum <= targetSum)
    int64_t validSubarrays = 0;

    // Process all possible windows starting at 'start'
    while (start < size) {
        // Expand window by moving end pointer right while sum is valid
        while (end < size && windowSum + numbers[end] <= targetSum) {
            windowSum += numbers[end];
            end++;
        }

        // Calculate valid subarrays for current window
        // Since 'end' is exclusive, (end - start) gives window size
        // For window [start, end), all subarrays ending at positions
        // [start, end) are valid
        validSubarrays += end - start;

        // Move start pointer right:
        // If window is empty (end <= start), just move both pointers
        // Otherwise, remove start element from window sum
        if (end <= start) {
            start++;
            end = start;
        } else {
            windowSum -= numbers[start];
            start++;
        }
    }

    cout << validSubarrays << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}
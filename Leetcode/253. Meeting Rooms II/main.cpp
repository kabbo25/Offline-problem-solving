#include <bits/stdc++.h>
using namespace std;

class MeetingScheduler {
public:
    /**
     * Determines the minimum number of meeting rooms required to accommodate all meetings
     *
     * Algorithm:
     * 1. Sort meetings by end time to optimize room allocation
     * 2. For each meeting, try to reuse a room that has finished its previous meeting
     * 3. If no room is available, allocate a new room
     *
     * @param meetingTimes Vector of meeting intervals where each interval is [startTime, endTime]
     * @return Minimum number of rooms required
     */
    static int calculateMinRoomsRequired(vector<vector<int>>& meetingTimes) {
        // Sort meetings by end time for optimal room allocation
        sort(meetingTimes.begin(), meetingTimes.end(),
             [](const vector<int>& meeting1, const vector<int>& meeting2) {
                 return meeting1[1] < meeting2[1];
             });

        int totalRoomsNeeded = 0;
        // Store end times of ongoing meetings
        multiset<int> activeRoomEndTimes;

        // Process each meeting
        for(const auto& meeting : meetingTimes) {
            int currentMeetingStart = meeting[0];
            int currentMeetingEnd = meeting[1];

            // Find the first room that becomes available after the current meeting's start time
            auto availableRoomIter = activeRoomEndTimes.upper_bound(currentMeetingStart);

            if(availableRoomIter == activeRoomEndTimes.begin() || activeRoomEndTimes.empty()) {
                // No room available - need to allocate a new room
                activeRoomEndTimes.insert(currentMeetingEnd);
                totalRoomsNeeded++;
            } else {
                // Reuse the room that finished earliest
                availableRoomIter = prev(availableRoomIter);
                activeRoomEndTimes.erase(availableRoomIter);  // Remove previous meeting
                activeRoomEndTimes.insert(currentMeetingEnd); // Schedule current meeting
            }
        }
        return totalRoomsNeeded;
    }
};

// Test function to run a single test case
void runTestCase(const vector<vector<int>>& meetings, int expectedRooms, int testNumber) {
    cout << "Test Case " << testNumber << ":" << endl;
    cout << "Input: [";
    for(size_t i = 0; i < meetings.size(); i++) {
        cout << "[" << meetings[i][0] << "," << meetings[i][1] << "]";
        if(i < meetings.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    int result = MeetingScheduler::calculateMinRoomsRequired(const_cast<vector<vector<int>> &>(meetings));
    cout << "Output: " << result << endl;
    cout << "Expected: " << expectedRooms << endl;
    cout << "Status: " << (result == expectedRooms ? "PASSED" : "FAILED") << endl << endl;
}

int main() {
    // Test Case 1: Overlapping meetings requiring multiple rooms
    vector<vector<int>> testCase1 = {{0, 30}, {5, 10}, {15, 20}};
    runTestCase(testCase1, 2, 1);

    // Test Case 2: Non-overlapping meetings requiring single room
    vector<vector<int>> testCase2 = {{7, 10}, {2, 4}};
    runTestCase(testCase2, 1, 2);

    // Test Case 3: Partially overlapping meetings
    vector<vector<int>> testCase3 = {{2, 11}, {6, 16}, {11, 16}};
    runTestCase(testCase3, 2, 3);

    return 0;
}
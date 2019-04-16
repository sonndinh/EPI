class Solution {
public:
    // Time complexity O(nlgn).
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // Sort intervals using start times.
        sort(intervals.begin(), intervals.end(), 
             [] (const vector<int>& a, const vector<int>& b) -> bool {
                 return a[0] < b[0];
             });
        // Use min-heap to store the latest finish times for the rooms.
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        int num_rooms = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            if (min_heap.empty()) {
                ++num_rooms;
                min_heap.emplace(intervals[i][1]);
            } else {
                int min_end_time = min_heap.top();
                if (min_end_time <= intervals[i][0]) {
                    // Can put this event to the same room.
                    min_heap.pop();
                    min_heap.emplace(intervals[i][1]);
                } else {
                    // Put to a new room.
                    min_heap.emplace(intervals[i][1]);
                    ++num_rooms;
                }
            }
        }
        return num_rooms;
    }
};

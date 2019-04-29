class Solution {
public:
    struct Compare {
        bool operator() (const vector<int>& a, const vector<int>& b) {
            int dist_a = a.at(0)*a.at(0) + a.at(1)*a.at(1);
            int dist_b = b.at(0)*b.at(0) + b.at(1)*b.at(1);
            return (dist_a > dist_b);
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if (points.size() <= K) return points;
        
        priority_queue<vector<int>, vector<vector<int>>, Compare> heap(points.begin(), points.end());
        vector<vector<int>> ret;
        while (K > 0) {
            const vector<int>& point = heap.top();
            ret.emplace_back(point);
            heap.pop();
            --K;
        }
        
        return ret;
    }
};

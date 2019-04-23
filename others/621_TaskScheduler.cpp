class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char c : tasks) {
            count[c - 'A']++;
        }
        priority_queue<int, vector<int>, less<int>> ready_queue;
        for (int task : count) {
            if (task > 0)
                ready_queue.push(task);
        }
        int time = 0;
        
        while (!ready_queue.empty()) {
            int task = ready_queue.top();
            ready_queue.pop();
            vector<int> tmp;
            if (--task > 0)
                tmp.push_back(task);
            ++time;
            int i = 0;
            
            while (i < n) {
                if (ready_queue.empty() && tmp.empty())
                    break;
                if (!ready_queue.empty()) {
                    int next = ready_queue.top();
                    ready_queue.pop();
                    if (--next > 0)
                        tmp.push_back(next);
                }
                ++time;
                ++i;
            }

            for (int task : tmp) {
                ready_queue.push(task);
            }
        }
        
        return time;
    }
};

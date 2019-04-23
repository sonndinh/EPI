// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if (n <= 0)
            return -1;
        
        int tmp = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(tmp, i)) {
                tmp = i;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (i != tmp && (!knows(i, tmp) || knows(tmp, i)))
                return -1;
        }
        
        return tmp;
    }
	
    int findCelebrity2(int n) {
        unordered_set<int> persons;
        for (int i = 0; i < n; ++i) {
            persons.insert(i);
        }
        
        int celeb = -1;
        while (persons.size() > 1) {
            unordered_set<int>::iterator it = persons.begin();
            int per_a = *it;
            while (++it != persons.end()) {
                int per_b = *it;
                if (knows(per_a, per_b)) {
                    // per_a cannot be a celeb.
                    persons.erase(per_a);
                } else if (knows(per_b, per_a)) {
                    // per_b cannot be a celeb.
                    persons.erase(per_b);
                } else {
                    // Both cannot be a celeb.
                    persons.erase(per_a);
                    persons.erase(per_b);
                }
                break;
            }
        }
        
        if (!persons.empty()) {
            // Final check whether the last person is a celeb.
            int last_per = *(persons.begin());
            celeb = last_per;
            for (int i = 0; i < n; ++i) {
                if (i != last_per && (!knows(i, last_per) || knows(last_per, i))) {
                    celeb = -1;
                    break;
                }
            }
        }
        
        return celeb;
    }
};

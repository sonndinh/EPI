class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0; 
        if (prices.empty())
            return max_profit;
        int min = prices[0];
        
        for (int i = 1; i < prices.size(); ++i) {
            int tmp = prices[i] - min;
            if (tmp > max_profit)
                max_profit = tmp;
            if (min > prices[i])
                min = prices[i];
        }
        return max_profit;
    }
};

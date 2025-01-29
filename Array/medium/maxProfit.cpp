int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxPro = 0;
        int n = prices.size();
        for(int i = 1; i < n; i++) {
            int cost = prices[i] - mini;
            maxPro = max(maxPro, cost);
            mini = min(mini, prices[i]);
        }
        return maxPro;
    }
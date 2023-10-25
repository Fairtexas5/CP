/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a 
different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0){return 0;}

        int min = prices[0];
        int max_profit = 0;
        for(int i=0; i<n; i++){
            if (prices[i] < min)
                min = prices[i];
            else
                max_profit = max(max_profit, prices[i] - min);
        }
        return max_profit;
    }
};


int main() {
    Solution solution;
    vector<int> prices;
    int result = solution.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;
    return 0;
}
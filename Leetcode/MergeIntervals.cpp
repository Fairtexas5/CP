class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {return {};}
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> merged;
        //Ye preallocate kardega memory jisse reallocations kam karni pade, fixed memory
        merged.reserve(intervals.size());

        for (const auto& interval : intervals) {
            if (merged.empty() || interval[0] > merged.back()[1]) {
                merged.emplace_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};

class Solution {
public:
    static bool comp(const pair<int,int>& a, const pair<int,int>& b) {
        return a.first < b.first;
    }

    int bs(const vector<pair<int,int>>& map, int target) {
        int l = 0;
        int r = map.size() - 1;
        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (map[mid].first <= target) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> map;
        int n = difficulty.size();
        for (int i = 0; i < n; i++) {
            map.push_back({difficulty[i], profit[i]});
        }
        
        // Use static member function for sorting
        sort(map.begin(), map.end(), comp);
        
        // Alternatively, use a lambda function:
        // sort(map.begin(), map.end(), [](const auto& a, const auto& b) {
        //     return a.first < b.first;
        // });

        // Update maximum profit for each difficulty level
        for (int i = 1; i < n; i++) {
            map[i].second = max(map[i-1].second, map[i].second);
        }

        sort(worker.begin(), worker.end());
        
        int sum = 0;
        for (int i = 0; i < worker.size(); i++) {
            int mid = bs(map, worker[i]);
            if (mid != -1) {  // Check if a suitable job was found
                sum += map[mid].second;
            }
        }
        return sum;
    }
};
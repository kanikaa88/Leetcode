class Solution {
    public:
        int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
            int n = startTime.size();
            vector<int> gaps;
    
            // Step 1: Build gaps array
            gaps.push_back(startTime[0]);
            for (int i = 1; i < n; ++i)
                gaps.push_back(startTime[i] - endTime[i - 1]);
            gaps.push_back(eventTime - endTime[n - 1]);
    
            // Step 2: Build prefix and suffix max arrays
            vector<int> prefixMax(n + 1), suffixMax(n + 2);
            prefixMax[0] = gaps[0];
            for (int i = 1; i <= n; ++i)
                prefixMax[i] = max(prefixMax[i - 1], gaps[i]);
    
            suffixMax[n] = gaps[n];
            for (int i = n - 1; i >= 0; --i)
                suffixMax[i] = max(suffixMax[i + 1], gaps[i]);
    
            // Step 3: Try removing each meeting
            int maxTime = *max_element(gaps.begin(), gaps.end());
    
            for (int i = 0; i < n; ++i) {
                int duration = endTime[i] - startTime[i];
                int merged = gaps[i] + gaps[i + 1];
    
                int left = i > 0 ? prefixMax[i - 1] : 0;
                int right = (i + 2 <= n) ? suffixMax[i + 2] : 0;
    
                int extra = (max(left, right) >= duration) ? duration : 0;
                maxTime = max(maxTime, merged + extra);
            }
    
            return maxTime;
        }
    };
    
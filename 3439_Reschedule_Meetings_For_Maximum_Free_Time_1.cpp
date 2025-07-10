class Solution {
    public:
        int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
            vector<int> gaps;
    
            // Gap before first meeting
            gaps.push_back(startTime[0]);
    
            // Gaps between meetings
            for (int i = 1; i < startTime.size(); ++i) {
                gaps.push_back(startTime[i] - endTime[i - 1]);
            }
    
            // Gap after last meeting
            gaps.push_back(eventTime - endTime.back());
    
            // Sliding window of size k+1
            int window = 0;
            for (int i = 0; i <= k; ++i)
                window += gaps[i];
    
            int maxGap = window;
    
            for (int i = k + 1; i < gaps.size(); ++i) {
                window += gaps[i] - gaps[i - (k + 1)];
                maxGap = max(maxGap, window);
            }
    
            return maxGap;
        }
    };
    
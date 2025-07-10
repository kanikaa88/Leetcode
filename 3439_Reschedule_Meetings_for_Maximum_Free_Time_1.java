class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        List<Integer> gaps = new ArrayList<>();

        // Gap before first meeting
        gaps.add(startTime[0]);

        // Gaps between meetings
        for (int i = 1; i < startTime.length; i++) {
            gaps.add(startTime[i] - endTime[i - 1]);
        }

        // Gap after last meeting
        gaps.add(eventTime - endTime[endTime.length - 1]);

        // Sliding window of size k+1
        int window = 0;
        for (int i = 0; i <= k; i++)
            window += gaps.get(i);

        int maxGap = window;

        for (int i = k + 1; i < gaps.size(); i++) {
            window += gaps.get(i) - gaps.get(i - (k + 1));
            maxGap = Math.max(maxGap, window);
        }

        return maxGap;
    }
}

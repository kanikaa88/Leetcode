class Solution {
    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.length;
        int[] gaps = new int[n + 1];

        // Step 1: Build gaps
        gaps[0] = startTime[0];
        for (int i = 1; i < n; i++)
            gaps[i] = startTime[i] - endTime[i - 1];
        gaps[n] = eventTime - endTime[n - 1];

        // Step 2: Build prefix/suffix max
        int[] prefixMax = new int[n + 1];
        int[] suffixMax = new int[n + 2];
        prefixMax[0] = gaps[0];
        for (int i = 1; i <= n; i++)
            prefixMax[i] = Math.max(prefixMax[i - 1], gaps[i]);

        suffixMax[n] = gaps[n];
        for (int i = n - 1; i >= 0; i--)
            suffixMax[i] = Math.max(suffixMax[i + 1], gaps[i]);

        // Step 3: Try removing each meeting
        int maxTime = 0;
        for (int g : gaps)
            maxTime = Math.max(maxTime, g);

        for (int i = 0; i < n; i++) {
            int duration = endTime[i] - startTime[i];
            int merged = gaps[i] + gaps[i + 1];

            int left = (i > 0) ? prefixMax[i - 1] : 0;
            int right = (i + 2 <= n) ? suffixMax[i + 2] : 0;

            int extra = (Math.max(left, right) >= duration) ? duration : 0;
            maxTime = Math.max(maxTime, merged + extra);
        }

        return maxTime;
    }
}

var maxFreeTime = function(eventTime, k, startTime, endTime) {
    const gaps = [];

    // Gap before first meeting
    gaps.push(startTime[0]);

    // Gaps between meetings
    for (let i = 1; i < startTime.length; i++) {
        gaps.push(startTime[i] - endTime[i - 1]);
    }

    // Gap after last meeting
    gaps.push(eventTime - endTime[endTime.length - 1]);

    // Sliding window of size k+1
    let window = 0;
    for (let i = 0; i <= k; i++) {
        window += gaps[i];
    }

    let maxGap = window;

    for (let i = k + 1; i < gaps.length; i++) {
        window += gaps[i] - gaps[i - (k + 1)];
        maxGap = Math.max(maxGap, window);
    }

    return maxGap;
};

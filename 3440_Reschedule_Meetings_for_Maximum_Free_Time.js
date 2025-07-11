var maxFreeTime = function(eventTime, startTime, endTime) {
    const n = startTime.length;
    const gaps = [];

    // Step 1: Build gaps array
    gaps.push(startTime[0]);
    for (let i = 1; i < n; i++) {
        gaps.push(startTime[i] - endTime[i - 1]);
    }
    gaps.push(eventTime - endTime[n - 1]);

    // Step 2: Prefix and suffix max
    const prefixMax = Array(n + 1).fill(0);
    const suffixMax = Array(n + 2).fill(0);
    prefixMax[0] = gaps[0];
    for (let i = 1; i <= n; i++) {
        prefixMax[i] = Math.max(prefixMax[i - 1], gaps[i]);
    }

    suffixMax[n] = gaps[n];
    for (let i = n - 1; i >= 0; i--) {
        suffixMax[i] = Math.max(suffixMax[i + 1], gaps[i]);
    }

    // Step 3: Try each meeting for removal
    let maxTime = Math.max(...gaps);

    for (let i = 0; i < n; i++) {
        const duration = endTime[i] - startTime[i];
        const merged = gaps[i] + gaps[i + 1];

        const left = i > 0 ? prefixMax[i - 1] : 0;
        const right = (i + 2 <= n) ? suffixMax[i + 2] : 0;
        const extra = Math.max(left, right) >= duration ? duration : 0;

        maxTime = Math.max(maxTime, merged + extra);
    }

    return maxTime;
};

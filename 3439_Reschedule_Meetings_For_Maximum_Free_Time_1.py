from typing import List

class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        # Step 1: Build free gaps before, between, and after meetings
        gaps = []
        gaps.append(startTime[0])  # before first meeting

        for i in range(1, len(startTime)):
            gaps.append(startTime[i] - endTime[i - 1])  # between meetings

        gaps.append(eventTime - endTime[-1])  # after last meeting

        # Step 2: Use sliding window of size (k+1)
        window = sum(gaps[:k + 1])  # initial window
        maxGap = window

        for i in range(k + 1, len(gaps)):
            window += gaps[i] - gaps[i - (k + 1)]
            maxGap = max(maxGap, window)

        return maxGap

from typing import List

class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        n = len(startTime)
        gaps = []
        gaps.append(startTime[0])  # before first meeting
        for i in range(1, n):
            gaps.append(startTime[i] - endTime[i - 1])  # between meetings
        gaps.append(eventTime - endTime[-1])  # after last meeting

        # Build prefix max and suffix max arrays
        prefixMax = [0] * (n + 1)
        suffixMax = [0] * (n + 2)

        prefixMax[0] = gaps[0]
        for i in range(1, n + 1):
            prefixMax[i] = max(prefixMax[i - 1], gaps[i])

        suffixMax[n] = gaps[n]
        for i in range(n - 1, -1, -1):
            suffixMax[i] = max(suffixMax[i + 1], gaps[i])

        maxTime = max(gaps)  # case: don't move anything

        for i in range(n):
            duration = endTime[i] - startTime[i]
            merged = gaps[i] + gaps[i + 1]

            left = prefixMax[i - 1] if i > 0 else 0
            right = suffixMax[i + 2] if i + 2 <= n else 0
            extra = duration if max(left, right) >= duration else 0

            maxTime = max(maxTime, merged + extra)

        return maxTime

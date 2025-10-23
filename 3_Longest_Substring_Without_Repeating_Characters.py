class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen=[]
        ans=0
        for c in s:
            if c in seen:
                seen=seen[seen.index(c)+1:]
            seen.append(c)
            ans=max(ans,len(seen))
        return ans
        
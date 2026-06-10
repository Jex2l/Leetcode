class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        st = set()
        res = 0
        for val in nums:
            st.add(val)
        for val in nums:
            if val in st and (val - 1) not in st:
                cur = val
                cnt = 0
                while cur in st:
                    st.remove(cur)
                    cur += 1
                    cnt += 1
                res = max(res, cnt)
        return res

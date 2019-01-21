class LongestSubstring:
    def lengthOfLongestSubstring(self, s):
        """
        Given a string, find the length of the longest substring without repeating characters
        :type s: str
        :rtype: int
        """
        chars = {}
        max_len = 0
        head = 0

        for i, ch in enumerate(s):
            if chars.get(ch) is not None:
                head = max(head, chars[ch] + 1)
            chars[ch] = i
            max_len = max(max_len, i - head + 1)
        return max_len

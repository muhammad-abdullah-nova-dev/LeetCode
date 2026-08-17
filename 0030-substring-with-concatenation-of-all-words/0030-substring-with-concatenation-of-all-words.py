class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:

        ans = []

        word_len = len(words[0])
        word_count = len(words)

        need = {}

        for word in words:
            need[word] = need.get(word, 0) + 1

        for offset in range(word_len):

            left = offset
            count = 0

            window = {}

            right = offset

            while right + word_len <= len(s):

                word = s[right:right + word_len]

                # Word is not required
                if word not in need:

                    window.clear()
                    count = 0
                    left = right + word_len

                    right += word_len
                    continue

                # Add word
                window[word] = window.get(word, 0) + 1
                count += 1

                # Too many copies
                while window[word] > need[word]:

                    left_word = s[left:left + word_len]

                    window[left_word] -= 1

                    left += word_len
                    count -= 1

                # All words found
                if count == word_count:

                    ans.append(left)

                    left_word = s[left:left + word_len]

                    window[left_word] -= 1

                    left += word_len
                    count -= 1

                right += word_len

        return ans
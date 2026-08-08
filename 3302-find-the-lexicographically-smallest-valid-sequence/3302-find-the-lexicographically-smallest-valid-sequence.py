class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:

        n = len(word1)
        m = len(word2)

        # nxtIdx[i][c] = first index >= i
        # where character c occurs in word1
        nxtIdx = [[-1] * 26 for _ in range(n + 1)]

        for i in range(n - 1, -1, -1):

            nxtIdx[i] = nxtIdx[i + 1].copy()

            nxtIdx[i][ord(word1[i]) - ord('a')] = i

        # suff[j] = position where word2[j]
        # can be matched from the right
        suff = [-1] * m

        k = m - 1

        for i in range(n - 1, -1, -1):

            if k < 0:
                break

            if word1[i] == word2[k]:
                suff[k] = i
                k -= 1

        ans = []

        i = 0
        j = 0

        used = False

        while i < n and j < m:

            idx = nxtIdx[i][ord(word2[j]) - ord('a')]

            # Mismatch already used
            if used:

                if idx == -1:
                    return []

                if j < m - 1 and suff[j + 1] <= idx:
                    return []

                ans.append(idx)

                i = idx + 1
                j += 1

            # Mismatch still available
            else:

                # Exact match
                if word1[i] == word2[j]:

                    ans.append(i)

                    i += 1
                    j += 1

                # Use mismatch here
                elif (
                    j == m - 1
                    or (suff[j + 1] != -1 and i < suff[j + 1])
                ):

                    used = True

                    ans.append(i)

                    i += 1
                    j += 1

                # Skip current index
                else:
                    i += 1

        if len(ans) == m:
            return ans

        return []
class Solution {
    fun scoreOfParentheses(s: String): Int {
        return calculateScore(s, 0, s.length)
    }

    private fun calculateScore(s: String, i: Int, j: Int): Int {
        var ans = 0
        var bal = 0
        var start = i

        for (k in start until j) {
            bal += if (s[k] == '(') 1 else -1
            if (bal == 0) {
                if (k - start == 1) {
                    ans++
                } else {
                    ans += 2 * calculateScore(s, start + 1, k)
                }
                start = k + 1
            }
        }
        return ans
    }
}
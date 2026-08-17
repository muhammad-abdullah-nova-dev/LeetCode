class Solution {
    public List<Integer> findSubstring(String s, String[] words) {

        List<Integer> ans = new ArrayList<>();

        int wordLen = words[0].length();
        int wordCount = words.length;

        HashMap<String, Integer> need = new HashMap<>();

        for (String word : words) {
            need.put(word, need.getOrDefault(word, 0) + 1);
        }

        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int count = 0;

            HashMap<String, Integer> window = new HashMap<>();

            for (int right = offset;
                 right + wordLen <= s.length();
                 right += wordLen) {

                String word = s.substring(right, right + wordLen);

                // Word is not required
                if (!need.containsKey(word)) {

                    window.clear();
                    count = 0;
                    left = right + wordLen;

                    continue;
                }

                // Add word
                window.put(
                    word,
                    window.getOrDefault(word, 0) + 1
                );

                count++;

                // Too many copies
                while (window.get(word) > need.get(word)) {

                    String leftWord =
                        s.substring(left, left + wordLen);

                    window.put(
                        leftWord,
                        window.get(leftWord) - 1
                    );

                    left += wordLen;
                    count--;
                }

                // All words found
                if (count == wordCount) {

                    ans.add(left);

                    String leftWord =
                        s.substring(left, left + wordLen);

                    window.put(
                        leftWord,
                        window.get(leftWord) - 1
                    );

                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
}
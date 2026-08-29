class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;

        int[] sorted = nums.clone();
        Arrays.sort(sorted);

        // Map value -> group
        HashMap<Integer, Integer> numToGroup = new HashMap<>();

        // Map group -> queue of values
        HashMap<Integer, Queue<Integer>> groupToNums = new HashMap<>();

        int group = 0;

        numToGroup.put(sorted[0], group);
        groupToNums.putIfAbsent(group, new LinkedList<>());
        groupToNums.get(group).offer(sorted[0]);

        for (int i = 1; i < n; i++) {
            if (sorted[i] - sorted[i - 1] > limit) {
                group++;
            }

            numToGroup.put(sorted[i], group);
            groupToNums.putIfAbsent(group, new LinkedList<>());
            groupToNums.get(group).offer(sorted[i]);
        }

        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            int g = numToGroup.get(nums[i]);
            result[i] = groupToNums.get(g).poll();
        }

        return result;
    }
}
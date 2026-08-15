/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubsequence = function(nums) {
    let xorValue = 0;
    let hasNonZero = false;

    for (const x of nums) {
        xorValue ^= x;

        if (x !== 0) {
            hasNonZero = true;
        }
    }

    if (xorValue !== 0) {
        return nums.length;
    }

    if (hasNonZero) {
        return nums.length - 1;
    }

    return 0;
};
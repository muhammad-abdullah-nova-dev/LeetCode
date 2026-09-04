var firstStableIndex = function(nums, k) {
    for (let i = 0; i < nums.length; i++) {
        
        let maximum = Math.max(...nums.slice(0, i + 1));
        let minimum = Math.min(...nums.slice(i));

        if (maximum - minimum <= k) {
            return i;
        }
    }

    return -1;
};
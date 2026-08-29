var lexicographicallySmallestArray = function(nums, limit) {
    const n = nums.length;

    const sorted = [...nums].sort((a, b) => a - b);

    // value -> group
    const numToGroup = new Map();

    // group -> values
    const groupToNums = new Map();

    let group = 0;

    numToGroup.set(sorted[0], group);
    groupToNums.set(group, [sorted[0]]);

    for (let i = 1; i < n; i++) {
        if (sorted[i] - sorted[i - 1] > limit) {
            group++;
        }

        numToGroup.set(sorted[i], group);

        if (!groupToNums.has(group)) {
            groupToNums.set(group, []);
        }

        groupToNums.get(group).push(sorted[i]);
    }

    // Pointer for each group
    const pointers = new Map();

    for (const g of groupToNums.keys()) {
        pointers.set(g, 0);
    }

    const result = new Array(n);

    for (let i = 0; i < n; i++) {
        const g = numToGroup.get(nums[i]);

        const index = pointers.get(g);

        result[i] = groupToNums.get(g)[index];

        pointers.set(g, index + 1);
    }

    return result;
};
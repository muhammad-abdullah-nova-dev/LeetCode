var averageOfSubtree = function(root) {
    let ans = 0;
    function dfs(node) {
        if (!node) return [0, 0];
        const [leftSum, leftCnt] = dfs(node.left);
        const [rightSum, rightCnt] = dfs(node.right);
        const totalSum = leftSum + rightSum + node.val;
        const totalCnt = leftCnt + rightCnt + 1;
        if (Math.floor(totalSum / totalCnt) === node.val) ans++;
        return [totalSum, totalCnt];
    }
    dfs(root);
    return ans;
};
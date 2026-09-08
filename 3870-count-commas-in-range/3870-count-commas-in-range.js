/**
 * @param {number} n
 * @return {number}
 */
var countCommas = function(n) {
    let answer = 0;
    let threshold = 1000;

    while (threshold <= n) {
        answer += n - threshold + 1;

        threshold *= 1000;
    }

    return answer;
};
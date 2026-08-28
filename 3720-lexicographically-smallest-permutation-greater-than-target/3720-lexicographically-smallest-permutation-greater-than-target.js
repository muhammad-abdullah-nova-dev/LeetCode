/**
 * @param {string} s
 * @param {string} target
 * @return {string}
 */
var lexGreaterPermutation = function(s, target) {
    const count = Array(26).fill(0);
    for (const ch of s) {
        count[ch.charCodeAt(0) - 97]++;
    }

    const n = s.length;
    let matched = 0;

    while (
        matched < n &&
        count[target.charCodeAt(matched) - 97] > 0
    ) {
        count[target.charCodeAt(matched) - 97]--;
        matched++;
    }

    const start = matched < n ? matched : n - 1;

    for (let i = start; i >= 0; i--) {
        if (i < matched) {
            count[target.charCodeAt(i) - 97]++;
        }

        let bigger = -1;
        for (let ch = target.charCodeAt(i) - 97 + 1; ch < 26; ch++) {
            if (count[ch] > 0) {
                bigger = ch;
                break;
            }
        }

        if (bigger !== -1) {
            count[bigger]--;

            let answer = target.slice(0, i);

            answer += String.fromCharCode(97 + bigger);

            for (let ch = 0; ch < 26; ch++) {
                answer += String.fromCharCode(97 + ch).repeat(count[ch]);
            }

            return answer;
        }
    }

    return "";
};
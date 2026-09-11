function totalNumbers(digits) {
    const s = new Set();
    for (let i = 0, n = digits.length; i < n; i++) {
        for (let j = 0; j < n; j++) {
            for (let k = 0; k < n; k++) {
                if (i !== j && i !== k && j !== k) {
                    s.add(100 * digits[i] + 10 * digits[j] + digits[k]);
                }
            }
        }
    }
    return [...s].filter((v) => v > 99 && !(v % 2)).length;
}
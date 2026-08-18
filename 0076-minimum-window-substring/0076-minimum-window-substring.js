var minWindow = function(s, t) {
    if (t.length > s.length) return "";

    const need = new Map();
    const window = new Map();

    for (const c of t) {
        need.set(c, (need.get(c) || 0) + 1);
    }

    let left = 0;
    let formed = 0;
    const required = need.size;

    let minLen = Infinity;
    let start = 0;

    for (let right = 0; right < s.length; right++) {

        const c = s[right];
        window.set(c, (window.get(c) || 0) + 1);

        if (need.has(c) &&
            window.get(c) === need.get(c)) {
            formed++;
        }

        while (formed === required) {

            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            const leftChar = s[left];
            window.set(leftChar, window.get(leftChar) - 1);

            if (need.has(leftChar) &&
                window.get(leftChar) < need.get(leftChar)) {
                formed--;
            }

            left++;
        }
    }

    return minLen === Infinity
        ? ""
        : s.substring(start, start + minLen);
};
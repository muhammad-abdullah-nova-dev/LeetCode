const maxPalindromes = (s, k) => {
    let res = 0, n = s.length;
    if (k === 1) return n;

    const check = (l, r) => {
        for (; l < r; l++, r--)
            if (s[l] !== s[r]) return false;
        return true;
    };

    for (let i = 0; i <= n - k; i++) {
        if (check(i, i + k - 1)) {
            res++;
            i += k - 1;
        } else if (i < n - k && check(i, i + k)) {
            res++;
            i += k;
        }
    }

    return res;
};
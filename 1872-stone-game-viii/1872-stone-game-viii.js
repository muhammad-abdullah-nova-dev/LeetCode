const stoneGameVIII = A => {
    let s = _.reduce(A, (a, c) => (a.push((a.at(-1) ?? 0) + c), a), []);

    const m = _.memoize(i => 
        (i === A.length - 1) ?
            s[i] : Math.max(m(i + 1), s[i] - m(i + 1))
    );

    return m(1);
};
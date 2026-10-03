const longestValidParentheses = s => {
    let res = 0;
    let A = [-1];
    
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(')
            A.push(i);
        else {
            A.pop();
            
            if (!A.length)
                A.push(i);
            else
                res = Math.max(res, i - A.at(-1));
        }
    }
    
    return res;
};
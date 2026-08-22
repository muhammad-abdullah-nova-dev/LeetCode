var checkDivisibility = function(n) {
    let sum = 0;
    let product = 1;
    let newVar = n;

    while (newVar !== 0) {
        let temp = newVar % 10;
        sum += temp;
        product *= temp;
        newVar = Math.floor(newVar / 10);
    }

    let newSum = sum + product;

    return n % newSum === 0;
};
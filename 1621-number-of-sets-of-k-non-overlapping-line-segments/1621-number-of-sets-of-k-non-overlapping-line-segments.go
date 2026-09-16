package main

const MOD int64 = 1000000007

func modPow(base, exp int64) int64 {
	result := int64(1)

	for exp > 0 {
		if exp&1 == 1 {
			result = result * base % MOD
		}

		base = base * base % MOD

		exp >>= 1
	}

	return result
}

func numberOfSets(n int, k int) int {
	N := int64(n + k - 1)
	R := int64(2 * k)

	if R > N-R {
		R = N - R
	}

	numerator := int64(1)
	denominator := int64(1)

	for i := int64(1); i <= R; i++ {
		numerator = numerator * (N - R + i) % MOD

		denominator = denominator * i % MOD
	}

	inverseDenominator := modPow(denominator, MOD-2)

	return int(numerator * inverseDenominator % MOD)
}
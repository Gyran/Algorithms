/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/


#include "gmath.h"

template <class T> T chineseRemainder (T a, T n, T b, T m) {
	T x;
	T y;
	T ret;

	extgcd(n, m, x, y);

	ret = a * (y + n) % n * m + b * (x + m) % m * n;

	//printf("%d %d %d %d %d %d\n", a, n, b, m, x, y);

	if (ret >= (n * m)) {
		ret -= n * m;
	}

	return ret;
}

template <class T> T generalChineseRemainder (T a, T n, T b, T m) {
	T ret;
	T d = gcd(n, m);

	b -= a;
	b %= m;
	if (b < 0) {
		b += m;
	}
	if (b % d) {
		return - 1;
	}

	ret = d * chineseRemainder(T(0), n / d, b / d, m / d) + a;

	return ret;
}
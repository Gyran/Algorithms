/*************
Gustav Ahlberg
gusah849@student.liu.se

Div math functions
**************/

#ifndef GMATH_H_GUARD
#define GMATH_H_GUARD

template <class T> int sign (T v) {
	return v < 0 ? -1 : 1;
}

template <class T> T gcd (T a, T b) {
	while (b != 0) {
		T t = b;
		b = a % b;
		a = t;
	}

	return a;
}

template <class T> T extgcd (T a, T b, T &x, T &y) {
	if (b) {
		T d = extgcd<T>(b, a % b, y, x);
		y -= (a / b) * x;
		return d;
	}
	x = 1;
	y = 0;

	return a;
}

template <class T> T lcm(T a, T b) {
	return ((a / gcd<T>(a, b)) * b);
}

#endif
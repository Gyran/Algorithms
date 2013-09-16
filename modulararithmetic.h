/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/

#include "gmath.h"

using namespace std;

template <class T> class ModArithmetic {
	T mod;

public:
	ModArithmetic<T> (T modWith = 1) {
		mod = modWith;
	}

	void setMod(T modWith) {
		mod = modWith;
	}

	T inverse (T a, T b);

	T plus (T a, T b);
	T minus (T a, T b);
	T mul (T a, T b);
	T div (T a, T b);
};

template <class T> T ModArithmetic<T>::plus (T a, T b) {
	return (a + b) % mod;
}

template <class T> T ModArithmetic<T>::minus (T a, T b) {
	return (a - b + mod) % mod;
}

template <class T> T ModArithmetic<T>::mul (T a, T b) {
	return (a * b) % mod;
}

template <class T> T ModArithmetic<T>::div (T a, T b) {
	T x, y;
	T g;
	g = extgcd(b, mod, x, y);

	if (g != 1) {
		return -1;
	}

	T inv = (mod +  x) % mod;

	return (a * inv) % mod;	

}

template <class T> class ModNum {
	ModArithmetic<T> mod;
	T num;

public:
	ModNum<T> (T modWith = 1, T startNum = 0) {
		//printf("en ny med med (%lld %lld)\n", modWith, startNum);
		mod.setMod(modWith);
		num = mod.plus(0, startNum);
	}

	ModNum<T> (ModArithmetic<T> modWith, T startNum = 0) {
		mod = modWith;
		num = mod.plus(0, startNum);
	}

	ModNum<T>& operator= (const T& i) {
		//printf("sätter num till %lld\n", i);
		num = i;
	}

	ModNum<T>& operator+= (const T& n) {
		//printf("%lld + %lld\n", num, n);
		num = mod.plus(num, n);

		return *this;
	}

	ModNum<T>& operator-= (const T& n) {
		//printf("%lld - %lld\n", num, n);
		num = mod.minus(num, n);

		return *this;
	}

	ModNum<T>& operator*= (const T& n) {
		//printf("%lld * %lld\n", num, n);
		num = mod.mul(num, n);

		return *this;
	}

	ModNum<T>& operator/= (const T& n) {
		//printf("%lld / %lld\n", num, n);
		num = mod.div(num, n);

		return *this;
	}

	bool operator< (const ModNum<T>& m) {
		return num < m.num;
	}

	bool operator> (const ModNum<T>& m) {
		return !(this < m);
	}

	bool operator< (const int m) {
		return num < m;
	}


	template <class Y> friend ostream& operator<< (ostream &out, ModNum<Y> &r);
    template <class Y> friend istream& operator>> (istream &in, ModNum<Y> &r);


};

template <class T> ostream& operator<< (ostream &out, ModNum<T>& n) {
	out << n.num;
}

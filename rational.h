/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/

#include <iostream>
#include <cmath>
#include "gmath.h"

using namespace std;

template <class T> class rational {
	T numerator;
	T denominator;

public:
	rational<T> (T nume = 0, T denom = 0) {
		numerator = nume * sign(denom);
		denominator = abs(denom);
		normalize();
	}

	rational<T> (const rational<T>& r) {
		numerator = r.numerator * sign(r.denominator);
		denominator = abs(r.denominator);
	}

	rational<T> operator+ (const rational<T>&);
	rational<T> operator- (const rational<T>&);
	rational<T> operator* (const rational<T>&);
	rational<T> operator/ (const rational<T>&);
	
	rational<T>& operator= (const rational<T>&);

	bool operator== (const rational<T>& r);

	bool operator< (const rational<T>& r);
	bool operator> (const rational<T>& r);

	template <class Y> friend ostream& operator<< (ostream &out, rational<Y> &r);
    template <class Y> friend istream& operator>> (istream &in, rational<Y> &r);

	T getDen() {
		return denominator;
	}

    void normalize();
};


template <class T> rational<T> rational<T>::operator+ (const rational<T>& r) {
	rational<T> n = rational<T>((numerator * r.denominator) + (denominator * r.numerator),
		denominator * r.denominator);

	n.normalize();
	return n;
}


template <class T> rational<T> rational<T>::operator- (const rational<T>& r) {
	rational<T> n = rational<T>((numerator * r.denominator) - (denominator * r.numerator),
		denominator * r.denominator);
	
	n.normalize();
	return n;
}

template <class T> rational<T> rational<T>::operator* (const rational<T>& r) {
	rational<T> n = rational<T>();

	T gcd1 = gcd<T>(numerator, r.denominator);
	T gcd2 = gcd<T>(r.numerator, denominator);

	n.numerator = (numerator / gcd1) * (r.numerator / gcd2);
	n.denominator = (denominator / gcd2) * (r.denominator / gcd1);

	n.normalize();
	return n;
}

template <class T> rational<T> rational<T>::operator/ (const rational<T>& r) {

	rational<T> n = rational<T>();
	
	T gcd1 = gcd<T>(numerator, r.numerator);
	T gcd2 = gcd<T>(r.denominator, denominator);

	n.numerator = (numerator / gcd1) * (r.denominator / gcd2);
	n.denominator = (denominator / gcd2) * (r.numerator / gcd1);

	n.normalize();
	return n;
}

template <class T> rational<T>& rational<T>::operator= (const rational<T>& r) {
	numerator = r.numerator;
	denominator = r.denominator;

	return *this;
}

template <class T> bool rational<T>::operator== (const rational<T>& r) {
	return (numerator == r.numerator && denominator == r.denominator);
}

template <class T> bool rational<T>::operator< (const rational<T>& r) {
	return ((numerator * r.denominator * sign<T>(denominator))
	 < (denominator * r.numerator * sign<T>(r.denominator)));
}

template <class T> bool rational<T>::operator> (const rational<T>& r) {
	return !(this < r);
}

template <class T> ostream& operator<< (ostream &out, rational<T>& r) {
	out << r.numerator;
	out << "/";
	out << r.denominator;
}

template <class T> istream& operator>> (istream &in, rational<T>& r) {
	in >> r.numerator;
	in >> r.denominator;

	r.numerator *= sign(r.denominator);
	r.denominator = abs(r.denominator);

}

template <class T> void rational<T>::normalize () {
	T theGcd = gcd(numerator, denominator);
	numerator /= theGcd;
	denominator /= theGcd;

	numerator *= sign(denominator);
	denominator = abs(denominator);

}
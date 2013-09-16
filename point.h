#pragma once

/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/

#include <iostream>

using namespace std;

template <class T> class Point {
public:
    T x, y;
    Point<T> (T x=T(), T y=T()) : x(x), y(y) { }

    Point<T> operator+ (const Point<T>& p) {
        return Point<T>(x + p.x, y + p.y);
    }

    Point<T> operator- (const Point<T>& p) {
        return Point<T>(x - p.x, y - p.y);
    }

    Point<T> operator* (const T n) {
        return Point<T>(x * n, y * n);
    }

    Point<T> operator/ (const T n) {
        return Point<T>(x / n, y / n);
    }

    bool operator== (const Point<T> p) const {
        return (x == p.x && y == p.y);
    }

    bool operator< (const Point<T> p) const {
        if (x == p.x) {
            return y < p.y;
        } else {
            return x < p.x;
        }
    }

    bool operator> (const Point<T> p) const {
        if (x == p.x) {
            return y > p.y;
        } else {
            return x > p.x;
        }
    }

    T scalarProduct (const Point<T> p) {
        return (x * p.x + y * p.y);
    }

    T crossProduct (const Point<T> p) {
        return (x * p.y - y * p.x);
    }

    double angle () {
        return atan2(y, x);
    }

    double dist () const {
        return sqrt((x * x) + (y * y));
    }

    double angle (const Point<T> p) {
        return acos((x * p.x + y * p.y) / (dist() * p.dist()));
    }

    /*
    double angle (const Point<T> p) {
        T deltaX, deltaY;
        deltaX = p.x - x;
        deltaY = p.y - y;

        return atan2(deltaY, deltaX);
    }*/

    double dist (const Point<T> p) {
        T deltaX, deltaY;
        deltaX = p.x - x;
        deltaY = p.y - y;

        return sqrt((deltaX * deltaX) + (deltaY * deltaY));
    }

    template <class Y> friend ostream& operator<< (ostream &out, Point<Y> &p);

    template <class Y> friend istream& operator>> (istream &in, Point<Y> &p);
};

template <class Y> ostream& operator<< (ostream &out, Point<Y> &p) {
    out << "(";
    out << p.x;
    out << ",";
    out << p.y;
    out << ")";
}

template <class Y> istream& operator>> (istream &in, Point<Y> &p) {
    in >> p.x;
    in >> p.y;
}
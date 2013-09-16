/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/

#include "point.h"
#include "intersect.h"

template <class P> double segmentPointDist (pair<P, P> s, P p) {
    P p1, p2, p2p1;
    Point<double> nearest, pDouble;
    p1 = s.first;
    p2 = s.second;

    if (p1 == p2) {
        return p1.dist(p);
    }

    p2p1 = p2 - p1;
    double dist, u;
    dist = p2p1.dist();

    u = ((p.x - p1.x) * (p2.x - p1.x) + (p.y - p1.y) * (p2.y - p1.y)) / (dist * dist);
    
    if (u <= 0 || 1 < u) {
        return min(p1.dist(p), p2.dist(p));
    }

    nearest = Point<double>(p1.x + u * (p2.x - p1.x), p1.y + u * (p2.y - p1.y));

    pDouble = Point<double>(p.x, p.y);

    return nearest.dist(pDouble);

}

template <class P> double segmentDist (pair<P, P> s1, pair<P, P> s2) {
    if (intersect(s1, s2).size() != 0) {
        return 0.0;
    }

    double ans, tmp;

    ans = segmentPointDist(s2, s1.first);
    ans = min(ans, segmentPointDist(s2, s1.second));
    ans = min(ans, segmentPointDist(s1, s2.first));
    ans = min(ans, segmentPointDist(s1, s2.second));

    return ans;
}
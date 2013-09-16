/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/

#include "point.h"


template <class It> double polygonArea(It begin, It end) {
    double area = 0;

    It i = begin;
    It j = end - 1;

    for (; i != end; j=i++) {
        area += j->crossProduct(*i);
    }

    return area / 2;
}
/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/

#include "point.h"

template <class T, class It> int insidePolygon (Point<T> p, It begin, It end) {
    bool inside = false;

    It j = end - 1;
    Point<T> deltaI, deltaJ;

    for (It i = begin; i != end; i++) {
        deltaI = p - (*i);
        deltaJ = p - (*j);

        if (deltaI.crossProduct(deltaJ) == 0 && deltaI.scalarProduct(deltaJ) <= 0) {
            return 0;
        }

        if ( (max(i->y, j->y) > p.y) && (min(i->y, j->y) <= p.y) &&
            ((*j - *i).crossProduct(p - *i) > 0) == (i->y <= p.y)) {

            inside = !inside;
        }
        j = i;
    }

    if (inside) {
        return 1;
    } else {
        return -1;
    }

}
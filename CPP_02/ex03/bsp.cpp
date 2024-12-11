#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p) {
    Fixed cross1 = (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());
    Fixed cross2 = (c.getX() - b.getX()) * (p.getY() - b.getY()) - (c.getY() - b.getY()) * (p.getX() - b.getX());
    Fixed cross3 = (a.getX() - c.getX()) * (p.getY() - c.getY()) - (a.getY() - c.getY()) * (p.getX() - c.getX());

    return ((cross1 < 0) && (cross2 < 0) && (cross3 < 0)) || ((cross1 > 0) && (cross2 > 0) && (cross3 > 0));
}
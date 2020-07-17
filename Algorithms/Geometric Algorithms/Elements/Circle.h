#pragma once
#include <vector>
#include "Point.h"

struct Circle {
  Point center{};
  double radius = 0;


  Circle() = default;
  Circle(const Point &_center, double _radius) : center(_center), radius(_radius) {}

  bool is_point_inside(const Point &p) const {
    return (distance(center,p) <= radius);
  }

  bool is_enclosing_circle(Point* P, int n) const {
    for(int i =0; i < n; i++) {
      if(!is_point_inside(P[i])) {
        return false;
      }
    }
    return true;
  }

  void construct_circle_by_two_points(const Point &A,const Point &B) {
    center = middle_point(A,B);
    radius = distance(center,A);
  }

  void construct_circle_by_three_points(const Point &A, const Point &B, const Point &C) {
    double D = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));

    center.x = (((A.x * A.x)  + (A.y * A.y)) * (B.y - C.y) +
        ((B.x * B.x)  + (B.y * B.y)) * (C.y - A.y) +
        ((C.x * C.x)  + (C.y * C.y)) * (A.y - B.y)) / D;

    center.y = (((A.x * A.x)  + (A.y * A.y) ) * (C.x - B.x) +
        ((B.x * B.x)  + (B.y * B.y) ) * (A.x - C.x) +
        ((C.x * C.x)  + (C.y * C.y) ) * (B.x - A.x)) / D;

    radius = distance(center,A);
  }

  bool operator<(const Circle &c) const {
    return radius < c.radius;
  }

  friend std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "(" << c.center << ";" << c.radius << ")";
    return out;
  }

};




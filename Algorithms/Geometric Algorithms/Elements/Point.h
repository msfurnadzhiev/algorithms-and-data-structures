#pragma once

#include <iostream>
#include <cmath>
#include <random>
using namespace std;

const unsigned int UPPER_BOUND = 10000;

struct Point {

  double x = 0;
  double y = 0;

  Point() = default;
  Point(double _x, double _y) : x(_x), y(_y) {};

  void set_random_coordinates() {
    x = static_cast<double>(rand() % UPPER_BOUND);
    y = static_cast<double>(rand() % UPPER_BOUND);
  }

  friend double distance(const Point &A, const Point &B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y,2));
  }

  friend Point middle_point(const Point &A, const Point &B) {
    return {(A.x+B.x)/2,(A.y+B.y)/2};
  }

  friend std::ostream& operator<<(std::ostream &out, const Point &A) {
    out << "(" << A.x << "," << A.y << ")";
    return out;
  }
};


void random_points_generator(Point *P, size_t n) {
  srand((int)time(0));
  for(int i=0; i < n; i++) {
    P[i] = {static_cast<double>(rand() % UPPER_BOUND), static_cast<double >(rand() % UPPER_BOUND)};
  }
}

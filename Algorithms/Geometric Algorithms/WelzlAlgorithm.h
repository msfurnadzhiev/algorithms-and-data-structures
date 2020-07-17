
/* Problem: Smallest Enclosing Circle*/

#pragma once
#include <random>
#include "Elements/Circle.h"

void shuffle(Point *P, int index) {
  for(int i = 0; i < index; i++) {
    size_t j = static_cast<double>(rand() % index);
    swap(P[i],P[j]);
  }
}

Circle WelzlAlgorithm(Point *P, size_t n) {

  Circle c; c.construct_circle_by_two_points(P[0],P[1]);

  for(int i=2; i < n; i++) {
    if(!c.is_point_inside(P[i])) {
      shuffle(P,i);
      c.construct_circle_by_two_points(P[i],P[0]);
      for(int j = 1; j < i; j++) {
        if(!c.is_point_inside(P[j])) {
          shuffle(P, j);
          c.construct_circle_by_two_points(P[i], P[j]);
          for (int k = 0; k < j; k++) {
            if(!c.is_point_inside(P[k])) {
              c.construct_circle_by_three_points(P[i],P[j],P[k]);
            }
          }
        }
      }
    }
  }
  return c;
}

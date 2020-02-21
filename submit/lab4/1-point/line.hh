#ifndef LINE_HH_
#define LINE_HH_

#include <string>
#include "point.hh"

struct Line{
  const Point p1, p2;

  Line(const Point& p1 = Point(),const Point& p2 = Point()) : p1(p1), p2(p2) { }

  double length() const;

  std::string toString() const;
};

#endif

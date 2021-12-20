package lab1.moving;

import lab1.utilities.Point;

public interface Movement {
  Point move(Point newPoint);

  static String test() {
    return " ";
  };
}

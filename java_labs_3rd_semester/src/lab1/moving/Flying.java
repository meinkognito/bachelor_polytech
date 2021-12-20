package lab1.moving;

import lab1.utilities.Point;

public class Flying implements Movement {
  @Override
  public Point move(Point newPoint) {
    System.out.println("Flying to " + newPoint.toString());
    return newPoint;
  }

  @Override
  public String toString() {
    return "Flying";
  }
}

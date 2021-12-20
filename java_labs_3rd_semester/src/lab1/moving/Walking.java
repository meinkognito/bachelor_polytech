package lab1.moving;

import lab1.utilities.Point;

public class Walking implements Movement {
  @Override
  public Point move(Point newPoint) {
    System.out.println("Walking to " + newPoint.toString());
    return newPoint;
  }

  @Override
  public String toString() {
    return "Walking";
  }
}

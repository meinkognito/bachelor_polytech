package lab1;

import lab1.moving.*;
import lab1.utilities.*;

public class Hero {
  private final String name;
  private Point currentPoint;
  private Movement movementType;

  public Hero(String name, Point currentPoint, Movement movementType) {
    this.name = name;
    this.currentPoint = currentPoint;
    this.movementType = movementType;
  }

  public void move(Point newPoint) {
    currentPoint = movementType.move(newPoint);
  }

  public void setMovementType(String choice) {
    movementType = switch (choice) {
      case "Walking" -> new Walking();
      case "HorseRiding" -> new HorseRiding();
      case "Driving" -> new Driving();
      case "Flying" -> new Flying();
      case "Teleportation" -> new Teleportation();
      default -> throw new IllegalArgumentException();
    };
    System.out.println("Movement type was switched to " + movementType);
  }

  @Override
  public String toString() {
    return "I am " + name + "\nMy current point is " + currentPoint + "\nMy travel type is " + movementType;
  }
}

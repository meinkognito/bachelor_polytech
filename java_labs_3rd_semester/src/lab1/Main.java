package lab1;

import lab1.moving.*;
import lab1.utilities.*;

import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Hero hero = new Hero("Carl", new Point(0, 0), new Walking());

    Scanner sc = new Scanner(System.in);

    while (true) {
      String command = sc.next();

      if (command.equals("0")) {
        break;
      }
      try {
        switch (command) {
          case "ME" -> System.out.println(hero);
          case "MOVE_TO" -> {
            System.out.println("Enter coordinates to travel");
            hero.move(new Point(sc.nextDouble(), sc.nextDouble()));
          }
          case "CHANGE_MOVEMENT" -> {
            System.out.println("""
                Choose type of movement from the list:
                Walking
                HorseRiding
                Driving
                Flying
                Teleportation""");
            hero.setMovementType(sc.next());
          }
          default -> throw new IllegalArgumentException();
        }
      } catch (IllegalArgumentException e) {
        System.out.println("""
            Incorrect command!
            Try one of these:
            MOVE_TO "point"
            CHANGE_MOVEMENT "movementType"
            ME""");
      }
    }
  }
}

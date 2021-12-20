package lab5;

import java.util.NoSuchElementException;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import java.util.Collections;
import java.util.Collection;
import java.util.List;
import java.util.Map;

public class Main {

  public static void main(String[] args) {

    Integer[] intArray = new Integer[]{1, 2, 1, 3, 4, 2, 1};
    Integer[] intArray2 = new Integer[]{1, 3, 1, 3, 5, 3, 1};
    List<String> stringArray = List.of("pie", "hello", "abc", "lego");
    List<String> stringArray2 = List.of("pie", "hello", "abc", "lego", "aqua");

    System.out.println("Average of the list: " + average(intArray) + "\n");

    System.out.println("String list to uppercase with added prefix\n" + toUppercase(stringArray));

    System.out.print("\nUnique elements squares\n" + uniqueSquares(intArray) + "\n");

    System.out.println("\nSorted strings with letter \"a\" in the beginning\n" +
        startsWithLetterSort(stringArray2, "a"));

    try {
      System.out.println(
          "\nLast element in strings' array: " + getLastElement(List.of(stringArray)));
    } catch (IllegalArgumentException e) {
      e.printStackTrace();
    }

    System.out.println("\nEven numbers sum: " + evenNumbersSum(intArray2));

    System.out.println("\nCreating map from string array\n" + arrayToMap(stringArray));
  }

  private static double average(Integer[] array) {
    return Stream.of(array)
        .mapToDouble(x -> x)
        .average()
        .orElse(0);
  }

  private static List<String> toUppercase(List<String> array) {
    return array.stream()
        .map(x -> x = "_new_" + x.toUpperCase())
        .toList();
  }

  private static List<Integer> uniqueSquares(Integer[] array) {
    return Stream.of(array)
        .filter(x -> (Collections.frequency(List.of(array), x) == 1))
        .map(x -> x * x)
        .toList();
  }

  private static List<String> startsWithLetterSort(Collection<String> array, String letter) {
    return array.stream()
        .filter(x -> x.startsWith(letter))
        .sorted()
        .toList();
  }

  private static <T> T getLastElement(Collection<T> c) throws NoSuchElementException {
    return c.stream()
        .reduce((first, second) -> second)
        .orElseThrow(NoSuchElementException::new);
  }

  private static int evenNumbersSum(Integer[] array) {
    return Stream.of(array)
        .filter(x -> x % 2 == 0)
        .mapToInt(x -> x)
        .sum();
  }

  private static Map<String, String> arrayToMap(List<String> array) {
    return array.stream()
        .collect(Collectors.toMap(s -> s.substring(0, 1), s -> s.substring(1)));
  }
}

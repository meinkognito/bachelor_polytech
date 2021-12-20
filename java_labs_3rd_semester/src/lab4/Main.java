package lab4;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class Main {

  public static void main(String[] args) {
    BankAccount account = new BankAccount(100);
    Class<BankAccount> bankAccountClass = BankAccount.class;

    try {
      for (Method m : bankAccountClass.getDeclaredMethods()) {
        if (m.isAnnotationPresent(OperationCodable.class)) {
          m.setAccessible(true);

          System.out.println(m);
          int code = m.getAnnotation(OperationCodable.class).value();
          for (int i = 0; i < code; i++) {
            m.invoke(account, 20);
            System.out.println(account);
          }

          System.out.println();
        }
      }
    } catch (InvocationTargetException | IllegalAccessException e) {
      e.printStackTrace();
    }
  }
}

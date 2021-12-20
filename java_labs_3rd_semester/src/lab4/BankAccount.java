package lab4;

public class BankAccount {

  private int balance;

  BankAccount() {
    this.balance = 0;
  }

  BankAccount(int balance) {
    this.balance = balance;
  }

  @OperationCodable(2)
  private boolean add(int amount) {
    if (amount < 0) {
      System.err.println("Incorrect amount!");
      return false;
    }
    balance += amount;
    return true;
  }

  @OperationCodable(3)
  private boolean spend(int amount) {
    if (amount > balance || amount < 0) {
      System.err.println("Incorrect amount!");
      return false;
    }
    balance -= amount;
    return true;
  }

  public boolean transfer(BankAccount account, int amount) {
    if (!account.spend(amount)) {
      System.err.println("Incorrect amount or balance!");
      return false;
    }
    balance += amount;
    return true;
  }

  @Override
  public String toString() {
    return "Balance is " + balance;
  }
}

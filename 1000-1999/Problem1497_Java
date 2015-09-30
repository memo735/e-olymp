import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    System.out.println(sqrt(new BigInteger(new Scanner(System.in).nextLine())));
  }

  private static BigInteger sqrt(BigInteger n) {
    BigInteger a = BigInteger.ONE, mid;
    BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
    while(b.compareTo(a) >= 0) {
      mid = new BigInteger(a.add(b).shiftRight(1).toString());
      if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
      else a = mid.add(BigInteger.ONE);
    }
    return a.subtract(BigInteger.ONE);
  }
}

import java.util.*;
import java.math.*;
 
public class Main
{
  public static void main(String[] args)
  {
    Scanner con = new Scanner(System.in);   
    BigInteger a = con.nextBigInteger();
    BigInteger b = con.nextBigInteger();
    BigInteger div = a.divide(b);
    BigInteger mod = a.mod(b);
    System.out.println(div);
    System.out.println(mod);
    con.close();
  }
}

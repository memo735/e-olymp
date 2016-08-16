import java.util.*;
import java.math.*;

public class Main
{
	static BigInteger Cnk(BigInteger n, BigInteger k)
	{
		BigInteger ONE = BigInteger.ONE, CnkRes = ONE;
		if (k.compareTo(n.subtract(k)) > 0) k = n.subtract(k);
		for (BigInteger i = ONE; i.compareTo(k) <= 0; i = i.add(ONE))
			CnkRes = CnkRes.multiply(n.subtract(i).add(ONE)).divide(i);
		return CnkRes;
	}

	public static void main(String[] args)
	{
		Scanner con = new Scanner(System.in);
		int tests = con.nextInt(), group[] = new int[200];
		while (tests-- > 0)
		{
			int w = 0, n = con.nextInt(), g = con.nextInt();
			for (int j = 0; j < g; j++)
			{
				group[j] = con.nextInt();
				w += group[j];
			}
			w = n - w;
			if (w < g - 1) System.out.println("0");
			else System.out.println(Cnk(BigInteger.valueOf(w + 1), BigInteger.valueOf(w - g + 1)));
		}
	}
}

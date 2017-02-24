import java.util.*;
import java.math.*;

public class Main
{
	static BigInteger dp[][];

	static BigInteger f(int n, int d)
	{
		BigInteger s = BigInteger.ZERO;
		if (n < 0 || d < 0) return BigInteger.ZERO;
		if (n == 0) return dp[n][d] = BigInteger.ONE;
		if (dp[n][d].compareTo(BigInteger.ZERO) >= 0) return dp[n][d];
		for (int k = 2; k <= n; k += 2) s = s.add(f(k - 2, d - 1).multiply(f(n - k, d)));
		return dp[n][d] = s;
	}

	public static void main(String[] args)
	{
		Scanner con = new Scanner(System.in);
		while (con.hasNextInt())
		{
			int n = con.nextInt(), d = con.nextInt();
			dp = new BigInteger[n + 1][d + 1];
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= d; j++) dp[i][j] = new BigInteger("-1");

			BigInteger res = new BigInteger("0");
			if (d > n / 2) res = BigInteger.ZERO;
			else
				if (d == n / 2 || d == 1) res = BigInteger.ONE;
				else res = f(n, d).subtract(f(n, d - 1));

			System.out.println(res);
		}
		con.close();
	}
}

import java.io.*;
import java.util.*;

public class Main
{
	static long[] GcdExtended(long a, long b)
	{
		long res[] = new long[3]; // d, x, y
		if (b == 0)
		{
			res[0] = a; res[1] = 1; res[2] = 0;
			return res;
		}
		res = GcdExtended(b, a % b);
		long s = res[2];
		res[2] = res[1] - a / b * res[2];
		res[1] = s;
		return res;
	}

	public static void main(String[] args)
	{
		Scanner con = new Scanner(System.in);
		int tests = con.nextInt();
		while (tests-- > 0)
		{
			long a = con.nextLong(), b = con.nextLong();
			long res[] = GcdExtended(a, b);
			if (res[0] > 1)
				System.out.println("No Solution");
			else
			{
				if (res[1] < 0)
				{
					res[1] += b;
					res[2] -= a;
				}
				System.out.println(res[1] + " " + res[2]);
			}
		}
	}
}

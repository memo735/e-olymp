import java.util.*;

public class Main
{
	//Find the solutions x^2 + B*x + C = 0 in integers   
	static long Solve(long B, long C)
	{
		long D = B * B - 4 * C;
		if (D >= 0)
		{
			long R = (long)(Math.pow(D, 0.5) + 0.5);
			if (D == R * R && (-B + R) % 2 == 0) return (-B + R) / 2;
		}
		return -1;
	}

	public static void FindSolution(long N)
	{
		if (N == 1)
		{
			System.out.println("0 0 0");
			return;
		}
		if (N == 0 || N % 2 == 1)
		{
			System.out.println("Impossible.");
			return;
		}

		boolean Flag = true;
		for (int mEllipses = 0; mEllipses < 100; mEllipses++)
		{
			long C1 = 2 + 2 * mEllipses * (mEllipses - 1);
			if (C1 > N) break;
			for (int pTriangles = 99; pTriangles >= 0; pTriangles--)
			{
				// n^2 + n (4m + 6p - 1) + 2 + 2m (m - 1) + 3p (p - 1) + 6pm - s = 0
				long B = 4 * mEllipses + 6 * pTriangles - 1;
				long C = C1 + 3 * pTriangles * (pTriangles - 1) + 6 * mEllipses * pTriangles;
				if (C > N) continue;
				C -= N;
				long nCircles = Solve(B, C);
				if (nCircles >= 0 && nCircles < 20000)
				{
					System.out.println(mEllipses + " " + nCircles + " " + pTriangles);
					Flag = false;
				}
			}
		}
		if (Flag) System.out.println("Impossible.");
	}

	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		long N = in.nextLong();
		int CaseNo = 0;
		while (N >= 0)
		{
			CaseNo++;
			System.out.println("Case " + CaseNo + ":");
			FindSolution(N);
			N = in.nextLong();
		}
	}
}

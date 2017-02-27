import java.util.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner con = new Scanner(System.in);
		TreeSet<Integer> s = new TreeSet<Integer>();
		int n = con.nextInt();
		for (int i = 0; i < n; i++)
		{
			int k = con.nextInt();
			for (int j = 0; j < k; j++)
			{
				int x = con.nextInt();
				s.add(x);
			}
		}
		System.out.println(s.size());
		con.close();
	}
}

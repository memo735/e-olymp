import java.util.Scanner;
import java.util.Arrays;

public class Djons2{
	public static void main(String[] aaa){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] pr = new int[n][2];
		for ( int i = 0; i < n * 2; i++) pr[i%n][i/n] = sc.nextInt();
		Arrays.sort(pr,(int[] p1, int[] p2) -> Math.min(p1[0], p2[1]) - Math.min(p2[0], p1[1]));
		int result = 0, a = 0 ;
		for (int[] p:pr){
			a += p[0];
			result = Math.max(result, a) + p[1]; 
		}
		System.out.println(result);
	}
}

import java.util.Locale;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Locale.setDefault(Locale.US);
    Scanner in = new Scanner(System.in);

    while(in.hasNextInt()) {
      System.out.format("%.4f\n", getMinimumRatio(in.nextDouble(), in.nextDouble(), in.nextInt()));
    }
  }

  private static double getMinimumRatio(double l, double w, int n) {

    if(n == 1) return Math.max(l, w) / Math.min(l, w);

    double m = Double.MAX_VALUE, lp = l/n, wp = w/n;
    for(int i=1; i<=n/2; i++) {
      m = Math.min(m, Math.max(getMinimumRatio(i * lp, w, i), getMinimumRatio((n - i) * lp, w, n - i)));
      m = Math.min(m, Math.max(getMinimumRatio(l, i * wp, i), getMinimumRatio(l, (n - i) * wp, n - i)));
    }
    return m;
  }
}

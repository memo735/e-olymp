import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.DecimalFormat;

public class Main {

  public static void main(String[] args) throws Exception {

    String[] s = new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ");

    double x1 = Double.parseDouble(s[0]);
    double y1 = Double.parseDouble(s[1]);
    double x2 = Double.parseDouble(s[2]);
    double y2 = Double.parseDouble(s[3]);
    double x3 = Double.parseDouble(s[4]);
    double y3 = Double.parseDouble(s[5]);

    double l1 = len(x1, y1, x2, y2);
    double l2 = len(x1, y1, x3 ,y3);
    double l3 = len(x2, y2, x3, y3);
    DecimalFormat df = new DecimalFormat("#########0.0000");
    System.out.println(df.format(l1+l2+l3).replace(",", ".") + " " + df.format(area(x1,y1,x2,y2,x3,y3)).replace(",", "."));
  }

  private static double len(double a, double b, double c, double d) {
    return Math.sqrt((a-c)*(a-c)+(b-d)*(b-d));
  }

  private static double area(double a, double b, double c, double d, double e, double f) {
    return 0.5*Math.abs((a-e)*(d-b)-(a-c)*(f-b));
  }

}

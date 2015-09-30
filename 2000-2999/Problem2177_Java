import java.util.HashMap;
import java.util.Scanner;

public class Main {

  private static HashMap<Key, Integer> cache = new HashMap<Key, Integer>();

  public static void main(String[] args) {

    Scanner in = new Scanner(System.in);

    while(true) {
      Key k = new Key(in.nextInt(), in.nextInt(), in.nextInt());
      if(k.isFlag()) break;
      System.out.println("w(" + k.a + ", "  + k.b + ", " + k.c + ") = " + w(k));
    }
  }

  private static int w(Key k) {
    if(cache.containsKey(k)) return cache.get(k);
    if(k.min() <= 0) return 1;
    if(k.max() > 20) {
      if(!cache.containsKey(Key.k20)) cache.put(Key.k20, w(Key.k20));
      return cache.get(Key.k20);
    }
    if(k.isSorted()) {
      cache.put(k, w(new Key(k.a, k.b, k.c-1)) + w(new Key(k.a, k.b-1, k.c-1)) - w(new Key(k.a, k.b-1, k.c)));
      return cache.get(k);
    }
    cache.put(k, w(new Key(k.a-1, k.b, k.c)) + w(new Key(k.a-1, k.b-1, k.c)) + w(new Key(k.a-1, k.b, k.c-1)) - w(new Key(k.a-1, k.b-1, k.c-1)));
    return cache.get(k);
  }

  static class Key {
    int a, b, c; static Key k20 = new Key(20, 20, 20);

    Key(int a, int b, int c) { this.a = a; this.b = b; this.c = c; }

    boolean isFlag() { return a == -1 && a == b && b == c; }

    int max() { return Math.max(a, Math.max(b, c)); }

    int min() { return Math.min(a, Math.min(b, c)); }

    boolean isSorted() { return a < b && b < c; }

    @Override
    public String toString()  { return "a: " + a + " b: " + b + " c: " + c; }

    @Override
    public boolean equals(Object obj) {
      if(obj instanceof Key) {
        Key that = (Key)obj;
        return this.a == that.a && this.b == that.b && this.c == that.c;
      }
      return false;
    }

    @Override
    public int hashCode() {
      int result = 31 * a + b;
      result = 31 * result + c;
      return result;
    }
  }
}

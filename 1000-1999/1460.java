import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        short n = sc.nextShort();
        short a = sc.nextShort();
        short b = sc.nextShort();
        short c = sc.nextShort();
        short d = sc.nextShort();


        short[] l = new short[n];

        for (short i = 0; i < n; i++) {
            l[i] = (short)(i + 1);
        }


        short[] first = reverse(getSliceOfArray(l, (short)(a - 1), b));
        short[] changed = replaceRange(l, first, a, b);
        short[] second = reverse(getSliceOfArray(l, (short)(c - 1), d));
        short[] _final = replaceRange(changed, second, c, d);
        print(_final);
    }

    public static short[] getSliceOfArray(short[] arr, short start, short end)
    {

        // Get the slice of the Array
        short[] slice = new short[end - start];

        // Copy elements of arr to slice
        for (short i = 0; i < slice.length; i++) {
            slice[i] = arr[start + i];
        }

        // return the slice
        return slice;
    }

    public static short[] reverse(short[] k) {
        short[] r = new short[k.length];

        for (short i = 0; i < k.length; i++) {
            r[i] = k[k.length - 1 - i];
        }

        return r;
    }

    public static short[] replaceRange(short[] k, short[] dif, short a, short b) {
        short j = 0;
        for (short i = --a; i < b ; i++) {
            k[i] = dif[j];
            j++;
        }
        return k;
    }

    public static void print(short[] k) {
        for (short val : k) {
            System.out.printf("%d ", val);
        }
        System.out.println();

    }

}

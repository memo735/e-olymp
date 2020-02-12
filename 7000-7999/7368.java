import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();

        int[][] l = new int[b][a];

        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j++) {
                l[i][j] = sc.nextByte();
            }
        }

        for (int i = 0; i < b; i++) {
            System.out.printf("%.2f ", findAvg(removeMaxAndMin(l[i])));
        }
    }

    public static void print(int[] k) {
        for (int val : k) {
            System.out.printf("%d ", val);
        }
        System.out.println();

    }

    public static int[] removeMaxAndMin(int[] k) {
        int min = getMinValue(k);
        int max = getMaxValue(k);


        for (int i = 0; i < k.length; i++) {
            if (k[i] == min || k[i] == max) {
                k[i] = 0;
            }
        }
        return k;
    }

    public static double findAvg(int[] k) {
        return (double)findSum(k) / (double) nonZero(k);
    }

    public static int findSum(int[] k) {
        int sum = 0;

        for (int val : k) {
            sum+=val;
        }
        return sum;
    }

    public static int nonZero(int[] k) {

        int cnt = 0;
        for (int value : k) {
            if (value != 0) {
                cnt++;
            }
        }

        return cnt;
    }

    public static int getMaxValue(int[] numbers) {
        int maxValue = numbers[0];
        for (int i = 1; i < numbers.length; i++) {
            if (numbers[i] > maxValue) {
                maxValue = numbers[i];
            }
        }
        return maxValue;
    }

    public static int getMinValue(int[] numbers) {
        int minValue = numbers[0];
        for (int i = 1; i < numbers.length; i++) {
            if (numbers[i] < minValue) {
                minValue = numbers[i];
            }
        }
        return minValue;
    }

}

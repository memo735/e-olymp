using System;
using System.Numerics;

namespace Problem158
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] indeks = new int[n];
            int maxIndeks = 4;
            for (int i = 0; i < n; i++)
            {
                indeks[i] = int.Parse(Console.ReadLine());
                if (indeks[i] > maxIndeks) maxIndeks = indeks[i];
            }

            maxIndeks++;
            BigInteger[] fib = new BigInteger[maxIndeks];
            fib[1] = 1;
            fib[2] = 1;
            fib[3] = 1;
            fib[4] = 1;

            for (int i = 5; i < maxIndeks; i++)
            {
                fib[i] = fib[i - 1] + fib[i - 2] + fib[i - 3] + fib[i - 4];
            }
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine(fib[indeks[i]]);
            }
        }
    }
}

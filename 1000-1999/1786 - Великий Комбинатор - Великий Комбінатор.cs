using System;
using System.Numerics;

namespace Problem1786
{
    class Program
    {
        static BigInteger Comb(int n, int k)
        {
            BigInteger res = 1, i;
            for (i = 1; i <= k; ++i) res = res * (n - k + i) / i;
            return res;
        }

        static void Main()
        {
            string str = Console.ReadLine();
            var mas = str.Split(' ');
            int x = int.Parse(mas[0]);
            int k = int.Parse(mas[1]);
            x = x / 5;
            k++;
            if (x == 0) Console.WriteLine(1);
            else Console.WriteLine(Comb(k + x - 1, x));
        }
    }
}

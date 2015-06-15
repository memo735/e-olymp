using System;
using System.Numerics;

namespace Problem1655
{
    internal class Program
    {
        private static BigInteger EBOB(BigInteger x, BigInteger y)
        {
            while (x*y != 0)
            {
                if (x < y) y = y%x;
                else x = x%y;
            }
            return (x + y);
        }

        private static BigInteger EKOB(BigInteger x, BigInteger y)
        {
            return x*y/EBOB(x, y);
        }


        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            BigInteger ekob = 1;
            for (int i = 1; i <= n; i++)
            {
                ekob = EKOB(ekob, i);
            }
            Console.WriteLine(ekob);
        }
    }
}

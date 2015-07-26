using System;
using System.Numerics;

namespace Problem135
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
            return x + y;
        }

        private static BigInteger EKOB(BigInteger x, BigInteger y)
        {
            return x*y/EBOB(x, y);
        }

        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            BigInteger ekob = BigInteger.Parse(massiv[0]);
            for (int i = 1; i < n; i++)
            {
                ekob = EKOB(ekob, BigInteger.Parse(massiv[i]));
            }
            Console.WriteLine(ekob);
        }
    }
}

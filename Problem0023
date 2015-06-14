using System;

namespace Problem23
{
    internal class Program
    {
        private static long Addim(long x, long y)
        {
            long t = 1;
            long j = 1;
            while (j <= y)
            {
                t = t*x;
                j++;
            }
            return t;
        }

        private static long Say(long n, long k)
        {
            if (n == 2) return k*(k - 1);
            return k*Addim(k - 1, n - 1) - Say(n - 1, k);
        }

        private static long Yoxla(long n, long k)
        {
            if (n == 1) return k;
            if ((k == 1) || ((n%2 == 1) && (k == 2))) return -1;
            if ((k == 2) && (n%2 == 0)) return 2;
            return Say(n, k);
        }

        public static void Main(string[] args)
        {
            int say = 0;
            string str = Console.ReadLine();
            var massiv = str.Split(' ');
            int n = int.Parse(massiv[0]);
            int k = int.Parse(massiv[1]);
            Console.WriteLine(Yoxla(n, k));
        }
    }
}

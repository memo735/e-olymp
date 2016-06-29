using System;

namespace Problem29
{
    internal class Program
    {
        private static bool Pld(long x)
        {
            string y = x.ToString();
            string z = "";
            int len = y.Length;
            for (int i = 0; i < len; i++)
            {
                z = y[i] + z;
            }
            if (y == z) return true;
            return false;
        }

        private static long Guzgu(long x)
        {
            string y = x.ToString();
            string z = "";
            int len = y.Length;
            for (int i = 0; i < len; i++)
            {
                z = y[i] + z;
            }
            return long.Parse(z);
        }

        public static void Main(string[] args)
        {
            long n = long.Parse(Console.ReadLine());
            int say = 0;
            for (int i = 0; i < 10000; i++)
            {
                if (!Pld(n))
                {
                    n = n + Guzgu(n);
                    say++;
                }
                else break;
            }
            Console.WriteLine(say);
        }
    }
}

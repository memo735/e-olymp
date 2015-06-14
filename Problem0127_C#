using System;

namespace Problem127
{
    internal class Program
    {
        private static int Rekursiya(long s)
        {
            long bank = 0;
            for (int i = 1; i < 40; i++)
            {
                bank = 2*bank + i*(i + 1)/2;
                if (bank >= s) return i;
            }
            return 1;
        }

        public static void Main(string[] args)
        {
            long s = long.Parse(Console.ReadLine());
            Console.WriteLine(Rekursiya(s));
        }
    }
}

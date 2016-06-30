using System;

namespace Problem194
{
    internal class Program
    {
        private static string Kicik(int n)
        {
            string cavab = "";
            for (int i = 9; i > 1; i--)
            {
                while (n%i == 0)
                {
                    cavab = i + cavab;
                    n = n/i;
                }
            }
            return n == 1 ? cavab : "-1";
        }

        private static string Boyuk(int n)
        {
            string cavab = "";
            for (int i = 2; i < 10; i++)
            {
                while (n%i == 0)
                {
                    cavab = i + cavab;
                    n = n/i;
                }
            }
            return n == 1 ? cavab : "-1";
        }

        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine(Kicik(n) + " " + Boyuk(n));
        }
    }
}

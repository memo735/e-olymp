using System;

namespace Problem273
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            long a = long.Parse(massiv[0]);
            long b = long.Parse(massiv[1]);
            long m = long.Parse(massiv[2]);

            long cavab = 1;
            for (int i = 0; i < b; i++)
            {
                cavab = cavab*a;
                cavab = cavab%m;
            }
            Console.WriteLine(cavab);
        }
    }
}

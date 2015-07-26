using System;

namespace Problem571
{
    internal class Program
    {
        private static long EBOB(long x, long y)
        {
            while (x*y != 0)
            {
                if (x < y) y = y%x;
                else x = x%y;
            }
            return x + y;
        }

        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            long ebob = long.Parse(massiv[0]);
            for (int i = 1; i < n; i++)
            {
                ebob = EBOB(ebob, long.Parse(massiv[i]));
            }
            Console.WriteLine(ebob);
        }
    }
}

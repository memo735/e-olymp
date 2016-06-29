using System;

namespace Problem137
{
    internal class Program
    {
        private static int EBOB(int x, int y)
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
            int cavab = int.Parse(massiv[0]);
            for (int i = 1; i < n; i++)
            {
                cavab = EBOB(cavab, int.Parse(massiv[i]));
            }
            Console.WriteLine(cavab);
        }
    }
}

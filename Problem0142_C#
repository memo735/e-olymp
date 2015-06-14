using System;

namespace Problem142
{
    internal class Program
    {
        private static double Max(double a, double b)
        {
            return a > b ? a : b;
        }

        private static double Min(double a, double b)
        {
            return a < b ? a : b;
        }

        public static void Main(string[] args)
        {
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            double x1 = double.Parse(massiv[0]);
            double y1 = double.Parse(massiv[1]);
            double x2 = double.Parse(massiv[2]);
            double y2 = double.Parse(massiv[3]);
            double x3 = double.Parse(massiv[4]);
            double y3 = double.Parse(massiv[5]);

            if (x2 != x3)
            {
                double k = (y2 - y3)/(x2 - x3);
                double b = y2 - k*x2;
                if ((y1 == k*x1 + b) && (Min(x2, x3) <= x1) && (x1 <= Max(x2, x3)) && (Min(y2, y3) <= y1) && (y1 <= Max(y2, y3)))
                {
                    Console.WriteLine("1");
                }
                else Console.WriteLine("0");
            }
            else
            {
                if ((x1 == x2) && (Min(y2, y3) <= y1) && (y1 <= Max(y2, y3)))
                {
                    Console.WriteLine("1");
                }
                else Console.WriteLine("0");
            }
        }
    }
}

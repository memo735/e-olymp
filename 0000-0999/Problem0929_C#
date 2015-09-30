using System;

namespace Problem929
{
    internal class Program
    {
        private static string Yoxla(double a, double b, double c, double d)
        {
            if ((a == b) && (c == d)) return "YES";
            if ((a == c) && (b == d)) return "YES";
            if ((a == d) && (b == c)) return "YES";
            return "NO";
        }

        public static void Main(string[] args)
        {
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            double a = double.Parse(massiv[0]);
            double b = double.Parse(massiv[1]);
            double c = double.Parse(massiv[2]);
            double d = double.Parse(massiv[3]);
            Console.WriteLine(Yoxla(a, b, c, d));
        }
    }
}

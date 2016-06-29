using System;

namespace Problem43
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            long k = long.Parse(massiv[0]);
            long m = long.Parse(massiv[1]);
            long n = long.Parse(massiv[2]);
            long d = long.Parse(massiv[3]);
            var suret = d*k*m*n;
            var mexrec = k*m*n - k*m - k*n - m*n;
            if (suret%mexrec == 0) Console.WriteLine(suret/mexrec);
            else Console.WriteLine("-1");
        }
    }
}

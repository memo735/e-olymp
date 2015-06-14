using System;

namespace Problem125
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            int h1 = int.Parse(massiv[0]);
            int m1 = int.Parse(massiv[1]);
            int s1 = int.Parse(massiv[2]);

            setir = Console.ReadLine();
            massiv = setir.Split(' ');
            int h2 = int.Parse(massiv[0]);
            int m2 = int.Parse(massiv[1]);
            int s2 = int.Parse(massiv[2]);

            int a = 3600*h1 + 60*m1 + s1;
            int b = 3600*h2 + 60*m2 + s2;
            int h3 = (b - a)/3600;
            int m3 = (b - a - 3600*h3)/60;
            int s3 = b - a - 3600*h3 - 60*m3;
            Console.WriteLine("{0} {1} {2}", h3, m3, s3);
        }
    }
}

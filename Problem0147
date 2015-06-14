using System;

namespace Problem147
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            int d1 = int.Parse(massiv[0]);
            int m1 = int.Parse(massiv[1]);
            int y1 = int.Parse(massiv[2]);

            setir = Console.ReadLine();
            massiv = setir.Split(' ');
            int d2 = int.Parse(massiv[0]);
            int m2 = int.Parse(massiv[1]);
            int y2 = int.Parse(massiv[2]);

            var dt1 = new DateTime(y1, m1, d1);
            var dt2 = new DateTime(y2, m2, d2);
            var ferq = dt2 - dt1;
            Console.WriteLine(1 + Math.Abs(ferq.TotalDays));
        }
    }
}

using System;

namespace Problem130
{
    internal class Program
    {
        private static double Mesafe(int x1, int y1, int x2, int y2)
        {
            return Math.Sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        }

        public static void Main(string[] args)
        {
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            int x1 = int.Parse(massiv[0]);
            int y1 = int.Parse(massiv[1]);
            int x2 = int.Parse(massiv[2]);
            int y2 = int.Parse(massiv[3]);
            int x3 = int.Parse(massiv[4]);
            int y3 = int.Parse(massiv[5]);
            int x4 = 0, y4 = 0;
            double z1 = Mesafe(x2, y2, x3, y3);
            double z2 = Mesafe(x3, y3, x1, y1);
            double z3 = Mesafe(x1, y1, x2, y2);
            if ((z1 > z2) && (z1 > z3))
            {
                x4 = x2 + x3 - x1;
                y4 = y2 + y3 - y1;
            }
            if ((z2 > z1) && (z2 > z3))
            {
                x4 = x1 + x3 - x2;
                y4 = y1 + y3 - y2;
            }
            if ((z3 > z1) && (z3 > z2))
            {
                x4 = x1 + x2 - x3;
                y4 = y1 + y2 - y3;
            }
            Console.WriteLine("{0} {1}", x4, y4);
        }
    }
}

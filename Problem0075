using System;

namespace Problem75
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            //a - baslanilan sikke, m - cemi sikke
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            int a = int.Parse(massiv[0]);
            int m = int.Parse(massiv[1]);
            int n = 1;
            while (m > 0)
            {
                m = m - a;
                n++;
                a++;
            }
            Console.WriteLine(n - 2);
        }
    }
}

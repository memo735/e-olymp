using System;

namespace Problem11
{
    internal class Program
    {

        public static void Main(string[] args)
        {
            var setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            int m = int.Parse(massiv[0]);
            int n = int.Parse(massiv[1]);
            int k = int.Parse(massiv[2]);
            string cap = (m/n) + ".";
            int qaliq = m%n;
            m = qaliq*10;
            for (int i = 1; i <= k; i++)
            {
                cap = cap + (m/n);
                qaliq = m%n;
                m = qaliq*10;
            }
            Console.WriteLine(cap);
        }
    }
}

using System;

namespace Problem249
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Console.ReadLine();
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            int max = massiv.Length;
            string cavab = "";
            for (int i = 0; i < max; i++)
            {
                long a = long.Parse(massiv[i]);
                long b = (long) Math.Sqrt(a);
                cavab = b*b == a ? cavab + "1 " : cavab + "0 ";
            }
            cavab = cavab.TrimEnd(' ');
            Console.WriteLine(cavab);
        }
    }
}

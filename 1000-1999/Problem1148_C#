using System;

namespace Problem1148
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string cavab = "";
            for (int i = 0; i < n; i++)
            {
                string setir = Console.ReadLine();
                var massiv = setir.Split(' ');
                int a = int.Parse(massiv[0]);
                int b = int.Parse(massiv[1]);
                if (b%a == 0) cavab = cavab + a + " " + b;
                else cavab = cavab + "-1";
                if (i < n - 1) cavab = cavab + "\n";
            }
            Console.WriteLine(cavab);
        }
    }
}

using System;

namespace Problem260
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            int len = massiv.Length;
            int[] a = new int[len];
            for (int i = 1; i < len; i++)
            {
                a[i] = int.Parse(massiv[i]);
            }
            Array.Sort(a);
            string cavab = "";
            for (int i = len - 1; i > 0; i--)
            {
                cavab = cavab + a[i] + " ";
            }
            cavab = cavab.TrimEnd(' ');
            Console.WriteLine(cavab);
        }
    }
}

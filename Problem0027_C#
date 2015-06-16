using System;

namespace Problem27
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int max = int.Parse(Console.ReadLine());
            string eded = Convert.ToString(max, 2);
            int dovr = eded.Length;
            for (int i = 1; i < dovr; i++)
            {
                eded = eded.Substring(1, dovr - 1) + eded[0];
                int cari = Convert.ToInt32(eded, 2);
                if (cari > max) max = cari;
            }
            Console.WriteLine(max);
        }
    }
}

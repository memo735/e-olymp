using System;

namespace Problem263
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[,] mas = new int[n, 3];
            int m = 12345;
            mas[0, 0] = 1;
            mas[0, 1] = 1;
            mas[0, 2] = 0;
            for (int i = 1; i < n; i++)
            {
                mas[i, 0] = (mas[i - 1, 0] + mas[i - 1, 1] + mas[i - 1, 2])%m;
                mas[i, 1] = mas[i - 1, 0];
                mas[i, 2] = mas[i - 1, 1];
            }
            Console.WriteLine((mas[n - 1, 0] + mas[n - 1, 1] + mas[n - 1, 2])%m);
        }
    }
}

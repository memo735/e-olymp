using System;

namespace Problem165
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int i = 0;
            while (n > 0)
            {
                i = (int) (Math.Log(n, 2));
                n = n - (int) Math.Pow(2, i);
            }
            Console.WriteLine(i + 1);
        }
    }
}

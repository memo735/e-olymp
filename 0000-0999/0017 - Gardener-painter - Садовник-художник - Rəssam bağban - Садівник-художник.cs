using System;

namespace Problem17
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            long n = long.Parse(Console.ReadLine());
            Console.WriteLine(3*(long) Math.Pow(2, n - 1));
        }
    }
}

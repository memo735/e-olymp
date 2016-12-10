using System;

namespace Problem2218
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int say = 0;
            for (int i = 1; i <= n; i++)
            {
                if (Console.ReadLine() == "1") say++;
            }
            if (say > n/2.0) Console.WriteLine(n - say);
            else Console.WriteLine(say);
        }
    }
}

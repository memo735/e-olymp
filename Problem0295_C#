using System;

namespace Problem295
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int r = int.Parse(Console.ReadLine());
            int say = 0;
            for (int x = -r; x <= r; x++)
            {
                for (int y = -r; y <= r; y++)
                {
                    if (x*x + y*y <= r*r) say++;
                }
            }
            Console.WriteLine(say);
        }
    }
}

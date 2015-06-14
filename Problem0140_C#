using System;

namespace Problem140
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int aldi = 2;
            int borc = 2;
            int yedi = 2;
            for (int i = 2; i <= n; i++)
            {
                aldi = aldi*2;
                int qaytardi = (borc + aldi)/2;
                borc = borc + aldi - qaytardi;
                yedi = aldi - qaytardi;
            }
            Console.WriteLine("{0} {1}", yedi, borc);
        }
    }
}

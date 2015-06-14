using System;

namespace Problem109
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int sehife = 0;
            int p = 9;
            int i = 1;
            while (true)
            {
                if (n <= i*p)
                {
                    if (n%i != 0)
                    {
                        Console.WriteLine("0");
                        return;
                    }
                    sehife = sehife + n/i;
                    Console.WriteLine(sehife);
                    return;
                }
                n = n - p*i;
                sehife = sehife + p;
                p = p*10;
                i++;
            }
        }
    }
}

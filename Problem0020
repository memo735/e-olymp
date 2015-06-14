using System;

namespace Problem20
{
    internal class Program
    {
        private static int ReqemCemi(int x)
        {
            int cem = 0;
            while (x > 0)
            {
                cem = cem + x%10;
                x = x/10;
            }
            return cem;
        }

        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int say = 0;
            while (n > 0)
            {
                n = n - ReqemCemi(n);
                say++;
            }
            Console.WriteLine(say);
        }
    }
}

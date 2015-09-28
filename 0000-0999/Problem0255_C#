using System;

namespace Problem255
{
    internal class Program
    {
        private static long ReqemCemi(long a)
        {
            long cem = 0;
            while (a > 0)
            {
                cem = cem + a%10;
                a = a/10;
            }
            return cem;
        }

        public static void Main(string[] args)
        {
            int eded = int.Parse(Console.ReadLine());
            Console.WriteLine(ReqemCemi(ReqemCemi(ReqemCemi(eded))));
        }
    }
}

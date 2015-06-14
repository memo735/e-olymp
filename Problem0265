using System;

namespace Problem265
{
    internal class Program
    {
        private static string Cemle(string x, string y)
        {
            if (x.Length > y.Length)
            {
                int ss = x.Length - y.Length; //ss - maximum sifir sayi
                for (int i = 0; i < ss; i++)
                {
                    y = "0" + y;
                }
            }
            if (x.Length < y.Length)
            {
                int ss = y.Length - x.Length;
                for (int i = 0; i < ss; i++)
                {
                    x = "0" + x;
                }
            }
            int yadda = 0;
            string z = "";
            int max = x.Length - 1;
            for (int i = max; i >= 0; i = i - 1)
            {
                var cavab = int.Parse(x[i].ToString()) + int.Parse(y[i].ToString()) + yadda;
                yadda = cavab/10;
                cavab = cavab%10;
                z = cavab + z;
            }
            z = yadda + z;
            z = z.TrimStart('0');
            return z;
        }

        public static void Main(string[] args)
        {
            var a = Console.ReadLine();
            var b = Console.ReadLine();
            Console.WriteLine(Cemle(a, b));
        }
    }
}

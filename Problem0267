using System;

namespace Problem267
{
    internal class Program
    {
        private static string Ferq(string x, string y)
        {
            int compare = Muqayise(x, y);
            if (compare == -1) return "-" + Ferq(y, x);
            if (x.Length > y.Length)
            {
                int ss = x.Length - y.Length; //ss - maximum sifir sayi
                for (int i = 0; i < ss; i++)
                {
                    y = "0" + y;
                }
            }
            if (x.Length > y.Length)
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
                var cavab = byte.Parse(x[i].ToString()) - byte.Parse(y[i].ToString()) + yadda;
                if (cavab < 0)
                {
                    cavab = cavab + 10;
                    yadda = -1;
                }
                else yadda = 0;
                z = cavab + z;
            }
            z = z.TrimStart('0');
            if (z == "") z = "0";
            return z;
        }

        private static int Muqayise(string a, string b)
        {
            if (a.Length < b.Length) return -1;
            if (a.Length > b.Length) return 1;
            if (a.Length != b.Length) return 0;
            int uzunluq = a.Length;
            for (int i = 0; i < uzunluq; i++)
            {
                if (a[i] > b[i]) return 1;
                if (a[i] < b[i]) return -1;
            }
            return 0;
        }

        public static void Main(string[] args)
        {
            string a = Console.ReadLine();
            string b = Console.ReadLine();
            Console.WriteLine(Ferq(a, b));
        }
    }
}

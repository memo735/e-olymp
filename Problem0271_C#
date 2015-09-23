using System;
using System.Text;

namespace Problem271
{
    internal class Program
    {

        public static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var sb = new StringBuilder("1");
            Faktorial(ref sb, n);
            Console.WriteLine(sb.ToString());
        }

        private static void Vur(ref StringBuilder sb, int n)
        {
            var qaliq = 0;
            for (int i = sb.Length - 1; i >= 0; i--)
            {
                var cari = sb[i] - '0';
                var hesablanan = cari*n + qaliq;
                sb[i] = (char) (hesablanan%10 + '0');
                qaliq = hesablanan/10;
            }
            if (qaliq != 0) sb.Insert(0, qaliq.ToString());
        }

        private static void Faktorial(ref StringBuilder sb, int n)
        {
            for (int i = 2; i <= n; i++) Vur(ref sb, i);
        }
    }
}

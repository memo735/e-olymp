using System;

namespace Problem138
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int cem = 0;
            int[] eskinazlar = {500, 200, 100, 50, 20, 10};
            foreach (var c in eskinazlar)
            {
                int cnt = n/c;
                n = n - cnt*c;
                cem = cem + cnt;
            }
            //Console.WriteLine(n==0 ? cem: -1);
            if (n == 0) Console.WriteLine(cem);
            else Console.WriteLine("-1");
        }
    }
}

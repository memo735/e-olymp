using System;

namespace Problem46
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            var n = long.Parse(Console.ReadLine());
            // Fibonecci ededleri prinsipinden istifade edecem,
            // cunki, a<b+c sherti odenmemelidi...
            var a = new long[48];
            a[0] = 0;
            a[1] = 1;
            a[2] = 1;
            for (int i = 3; i < 48; i++)
            {
                a[i] = a[i - 1] + a[i - 2];
            }
            long cem = 0;
            var j = 1;
            while (cem <= n)
            {
                cem = cem + a[j];
                j++;
            }
            Console.WriteLine(j - 2);
        }
    }
}

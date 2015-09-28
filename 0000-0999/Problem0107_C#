using System;

namespace Problem107
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int qiymet = (n/100)*100;
            if (n%100 > 65)
            {
                qiymet = qiymet + 100;
                Console.WriteLine(qiymet);
                return;
            }
            qiymet = qiymet + ((n%100)/20)*30;
            if (n%20 > 15) qiymet = qiymet + 30;
            else qiymet = qiymet + (n%20)*2;
            Console.WriteLine(qiymet);
        }
    }
}

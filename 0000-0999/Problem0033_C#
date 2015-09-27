using System;

namespace Problem33
{
    internal class Program
    {
        private static bool Sade(int n)
        {
            if ((n == 0) || (n == 1)) return false;
            if ((n == 2) || (n == 3)) return true;
            if (n%2 == 0) return false;
            int kok = (int) Math.Sqrt(n) + 1;
            for (int i = 3; i < kok; i = i + 2)
            {
                if (n%i == 0) return false;
            }
            return true;
        }

        public static void Main(string[] args)
        {
            var setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            int a = int.Parse(massiv[0]);
            int b = int.Parse(massiv[1]);
            int say = 0;
            if (a > b)
            {
                say = a;
                a = b;
                b = say;
                say = 0;
            }
            for (int i = a; i <= b; i++)
            {
                if (!i.ToString().Contains("13"))
                {
                    if (Sade(i)) say++;
                }
            }
            Console.WriteLine(say);
        }
    }
}

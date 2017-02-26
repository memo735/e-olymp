using System;

namespace Problem1034
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            var mas = str.Split('/');
            int p1 = int.Parse(mas[0]);
            int q1 = int.Parse(mas[1]);
            str = Console.ReadLine();
            mas = str.Split('/');
            int b = int.Parse(mas[1]);
            str = Console.ReadLine();
            mas = str.Split('/');
            int p2 = int.Parse(mas[0]);
            int q2 = int.Parse(mas[1]);
            double sol = 1.0 * p1 * b / q1;
            double sag = 1.0 * p2 * b / q2;
            for (int i = (int) sol + 1; i < sag; i++)
            {
                if (sol < i && i < sag)
                {
                    Console.WriteLine("{0}/{1}", i, b);
                    return;
                }
            }
            Console.WriteLine("-1");
        }
    }
}

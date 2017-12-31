using System;
using System.Numerics;

namespace Problem7125
{
    internal class Program
    {
        //Вычисление функции Эйлера φ(n).
        static long euler(long n)
        {
            long result = n;
            for (int i = 2; i <= Math.Sqrt(n); i++)
            {
                if (n % i == 0) result -= result / i;
                while (n % i == 0) n /= i;
            }

            if (n > 1) result -= result / n;
            return result;
        }

        public static void Main()
        {
            BigInteger res = BigInteger.Zero;
            //Установим переменную k равной количеству цветов.
            BigInteger k = 2;
            int i, sq, n = int.Parse(Console.ReadLine());
            int up = sq = (int) Math.Sqrt(n);
            if (sq * sq == n) up--;

            //Перебираем делители i числа n от 1 до.Если i – делитель n, то n / i также будет делителем n.
            for (i = 1; i <= up; i++)
                if (n % i == 0)
                {
                    res = BigInteger.Add(res, BigInteger.Multiply(BigInteger.Pow(k, n / i), euler(i)));
                    res = BigInteger.Add(res, BigInteger.Multiply(BigInteger.Pow(k, i), euler(n / i)));
                }

            //Отдельно обработаем случай, если n является полным квадратом.
            if (sq * sq == n)
                res = BigInteger.Add(res, BigInteger.Multiply(BigInteger.Pow(k, i), euler(i)));

            res = BigInteger.Divide(res, n);
            Console.WriteLine(res);
        }
    }
}

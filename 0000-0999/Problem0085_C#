using System;

namespace Problem85
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            int n = int.Parse(massiv[0]);
            int m = int.Parse(massiv[1]);
            int k = int.Parse(massiv[2]);
            int[,] a = new int[n, n];
            int i = 0;
            int j = -1;
            int say = 1;
            int istiqamet = 1;
            int kv = n*n;
            while (say <= kv)
            {
                if (istiqamet == 1)
                {
                    j++;
                    while ((j < n) && (a[i, j] == 0))
                    {
                        a[i, j++] = say++;
                    }
                    j--;
                    istiqamet = 2;
                }
                if (istiqamet == 2)
                {
                    i++;
                    while ((i < n) && (a[i, j] == 0))
                    {
                        a[i++, j] = say++;
                    }
                    i--;
                    istiqamet = 3;
                }
                if (istiqamet == 3)
                {
                    j--;
                    while ((j >= 0) && (a[i, j] == 0))
                    {
                        a[i, j--] = say++;
                    }
                    j++;
                    istiqamet = 4;
                }
                if (istiqamet == 4)
                {
                    i--;
                    while ((i >= 0) && (a[i, j] == 0))
                    {
                        a[i--, j] = say++;
                    }
                    i++;
                    istiqamet = 1;

                }
            }
            Console.WriteLine(a[m - 1, k - 1]);
        }
    }
}

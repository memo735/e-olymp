using System;

namespace Problem128
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int eded = int.Parse(Console.ReadLine());
            int say = 0;
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    for (int k = 0; k < 10; k++)
                    {
                        if (i + j + k == eded)
                        {
                            for (int l = 0; l < 10; l++)
                            {
                                for (int m = 0; m < 10; m++)
                                {
                                    for (int n = 0; n < 10; n++)
                                    {
                                        if (l + m + n == eded) say++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            Console.WriteLine(say);
        }
    }
}

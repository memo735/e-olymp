using System;

namespace Problem177
{
    internal class Program
    {
        private static string Yoxla(string str)
        {
            var m = str.Split(' ');
            int tekrar;
            int maxTekrar = 0;

            if ((m[0] == m[1]) && (m[0] == m[2]) && (m[0] == m[3]) && (m[0] == m[4])) return "poker";
            for (int i = 0; i < 5; i++)
            {
                tekrar = 0;
                for (int j = 0; j < 5; j++)
                {
                    if (m[i] == m[j]) tekrar++;
                }
                if (tekrar > maxTekrar) maxTekrar = tekrar;
            }

            if (maxTekrar == 4) return "quads";

            int k = 0;
            string[] tekrarOlmayan = new string[2];
            if (maxTekrar == 3)
            {
                for (int i = 0; i < 5; i++)
                {
                    tekrar = 0;
                    for (int j = 0; j < 5; j++)
                    {
                        if (m[i] == m[j]) tekrar++;
                    }
                    if (tekrar != 3)
                    {
                        tekrarOlmayan[k] = m[i];
                        k++;
                    }
                }
                return tekrarOlmayan[0] == tekrarOlmayan[1] ? "full house" : "set";
            }

            int[] pair = new int[5];
            if (maxTekrar == 2)
            {
                for (int i = 0; i < 5; i++)
                {
                    tekrar = 0;
                    for (int j = 0; j < 5; j++)
                    {
                        if (m[i] == m[j]) tekrar++;
                        pair[i] = tekrar;
                    }
                }
                int ferqli = 0;
                for (int i = 0; i < 5; i++)
                {
                    if (pair[i] != 2) ferqli++;
                }
                return ferqli == 1 ? "two pair" : "pair";
            }

            return "no pair";
        }

        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string cavab = "";
            for (int i = 0; i < n; i++)
            {
                string str = Console.ReadLine();
                cavab = cavab + Yoxla(str) + "\n";
            }
            cavab = cavab.TrimEnd('\n');
            Console.WriteLine(cavab);
        }
    }
}

using System;

namespace Problem235
{
    internal class Program
    {
        private static int EBOB(int x, int y)
        {
            while (x*y != 0)
            {
                if (x < y) y = y%x;
                else x = x%y;
            }
            return x + y;
        }

        private static string Cavab(string x, string y)
        {
            int sifirSayi = x.Length;
            int doqquzSayi = y.Length;
            int suret = int.Parse("0" + x + y) - int.Parse("0" + x);
            string mxrc = "";
            for (int i = 1; i <= doqquzSayi; i++)
            {
                mxrc = mxrc + "9";
            }
            for (int i = 1; i <= sifirSayi; i++)
            {
                mxrc = mxrc + "0";
            }
            int mexrec = int.Parse(mxrc);
            int ebob = EBOB(suret, mexrec);
            suret = suret/ebob;
            mexrec = mexrec/ebob;
            if (mexrec == 1) return suret + "";
            return suret + "/" + mexrec;
        }

        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string cavab = "";
            for (int i = 0; i < n; i++)
            {
                string setir = Console.ReadLine();
                int j = 2;
                string qarisiq = "";
                while (setir[j] != '(')
                {
                    qarisiq = qarisiq + setir[j];
                    j++;
                }
                j++;
                string dovr = "";
                while (setir[j] != ')')
                {
                    dovr = dovr + setir[j];
                    j++;
                }
                cavab = cavab + Cavab(qarisiq, dovr) + "\n";
            }
            cavab = cavab.TrimEnd('\n');
            Console.WriteLine(cavab);
        }
    }
}

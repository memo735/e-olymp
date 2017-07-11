using System;

namespace Problem7809
{
    internal class Program
    {
        static int sifir = 0, bir = 0, iki = 0, uc = 0, dord = 0,
            bes = 0, alti = 0, yeddi = 0, sekkiz = 0, doqquz = 0;

        static void Hesabla(char x)
        {
            if (x == '0') sifir++;
            if (x == '1') bir++;
            if (x == '2') iki++;
            if (x == '3') uc++;
            if (x == '4') dord++;
            if (x == '5') bes++;
            if (x == '6') alti++;
            if (x == '7') yeddi++;
            if (x == '8') sekkiz++;
            if (x == '9') doqquz++;
        }

        public static void Main(string[] args)
        {
            string cavab = "", str = Console.ReadLine();
            var mas = str.Split(' ');
            foreach (string t in mas) Hesabla(t[0]);
            Console.WriteLine(sifir / 2 + bir / 2 + iki / 2 + uc / 2 + dord / 2 +
                              bes / 2 + alti / 2 + yeddi / 2 + sekkiz / 2 + doqquz / 2);
        }
    }
}

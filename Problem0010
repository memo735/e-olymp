using System;

namespace Test
{
    class Problem10
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine()); //n - agac sayi
            double vedre = 0;
            var saygac = n;
            int k = 0; //k - suvarmaga basladigi gun
            while (vedre<=0.5)
            {
                vedre = vedre + 1.0/saygac;
                k++;
                saygac = saygac - 1;
            }
            Console.WriteLine(n-k+1);
        }
    }
}

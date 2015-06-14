using System;

namespace Problem76
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string setir = Console.ReadLine();
            var massiv = setir.Split(' ');
            byte a = byte.Parse(massiv[0]);
            byte b = byte.Parse(massiv[1]);
            byte x = byte.Parse(massiv[2]);
            byte y = byte.Parse(massiv[3]);
            byte z = byte.Parse(massiv[4]);
            if ((x < a) && (y < b))
            {
                Console.WriteLine("1");
                return;
            }
            if ((y < a) && (x < b))
            {
                Console.WriteLine("1");
                return;
            }
            if ((x < a) && (z < b))
            {
                Console.WriteLine("1");
                return;
            }
            if ((z < a) && (x < b))
            {
                Console.WriteLine("1");
                return;
            }
            if ((y < a) && (z < b))
            {
                Console.WriteLine("1");
                return;
            }
            if ((z < a) && (y < b))
            {
                Console.WriteLine("1");
                return;
            }
            Console.WriteLine("0");
        }
    }
}

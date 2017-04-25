using System;

namespace Problem7311
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string a = Console.ReadLine();
            while (a.Contains("()"))
            {
                a = a.Replace("()", "");
            }
            Console.WriteLine(a.Length);
        }
    }
}

using System;

namespace Problem930
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string nomre = Console.ReadLine();
            string s = "";
            int say = 0;
            for (char i = '0'; i <= '9'; i++)
            {
                if (!nomre.Contains(i.ToString()))
                {
                    say = say + 1;
                    s = s + i + " ";
                }
            }
            s = s.TrimEnd(' ');
            if (say == 0)
            {
                Console.WriteLine("0");
                return;
            }
            Console.WriteLine(say);
            Console.WriteLine(s);
        }
    }
}

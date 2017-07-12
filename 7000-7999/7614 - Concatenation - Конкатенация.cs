using System;

namespace Problem7614
{
    internal class Program
    {
        private static int[] Hesabla(string a)
        {
            int[] result = new int[26];
            foreach (char t in a) result[t - 'a']++;
            return result;
        }

        public static void Main(string[] args)
        {
            string a = Console.ReadLine(), b = Console.ReadLine();
            int[] say1 = Hesabla(a), say2 = Hesabla(b);
            say1[a[0] - 'a']--;
            say2[b[b.Length - 1] - 'a']--;
            long ans = a.Length * (long) b.Length;
            for (int i = 0; i < say1.Length; i++) ans -= say1[i] * (long) say2[i];
            Console.WriteLine(ans);
        }
    }
}

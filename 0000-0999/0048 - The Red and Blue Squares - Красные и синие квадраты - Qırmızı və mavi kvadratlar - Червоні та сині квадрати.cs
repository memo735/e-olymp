using System;

namespace Problem48
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[,] area = new int[220, 220];
            int minx = 220;
            int maxx = 0;
            int miny = 220;
            int maxy = 0;
            for (int i = 0; i < n; i++)
            {
                string[] s = Console.ReadLine().Split(' ');
                int y = int.Parse(s[0]) + 110;
                int x = int.Parse(s[1]) + 110;
                area[x, y] = 1;
                if (y < minx) minx = y;
                if (x < miny) miny = x;
                if (y > maxx) maxx = y;
                if (x > maxy) maxy = x;
            }
            int perimeter = 0;
            int add = 0;
            for (int i = miny; i <= maxy; i++)
            {
                for (int j = minx; j <= maxx; j++)
                {
                    if (area[i, j] == 0) add++;
                    else
                    {
                        if (area[i + 1, j] == 0) perimeter++;
                        if (area[i - 1, j] == 0) perimeter++;
                        if (area[i, j + 1] == 0) perimeter++;
                        if (area[i, j - 1] == 0) perimeter++;
                    }
                }
            }
            int w = maxx - minx + 1;
            int h = maxy - miny + 1;
            int nh = 2*(w + h);

            while (nh < perimeter)
            {
                nh = nh + 2;
                if (w > h)
                {
                    add = add + w;
                    h++;
                }
                else
                {
                    add = add + h;
                    w++;
                }
            }
            Console.WriteLine(add);
        }
    }
}

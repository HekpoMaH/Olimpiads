using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace NinjaTestGenerator
{
    class Program
    {
        static int[] tests = new int[] { 5, 10, 50, 100, 200, 500, 666, 999, 1050, 1100, 1200, 1250, 1300, 1350, 1400, 1450, 1499, 1500, 1500, 1500 };
        static string fileFormat = "ninja.{0:00}.in";
        static Random rand = new Random();
        static void Main()
        {
            for (int testNumber = 1; testNumber <= tests.Length; testNumber++)
            {
                int testN = tests[testNumber - 1];
                using (StreamWriter sw = new StreamWriter(string.Format(fileFormat, testNumber)))
                {
                    sw.WriteLine(testN);
                    for (int row = 1; row <= testN; row++)
                    {
                        StringBuilder sb = new StringBuilder();
                        for (int col = 1; col <= testN; col++)
                        {
                            if (row == 1 && col == 1)
                            {
                                sb.Append("0 ");
                            }
                            else if (testNumber == 19)
                            {
                                sb.Append("1 ");
                            }
                            else if (testNumber == 20 || testNumber == 7 || testNumber == 11)
                            {
                                sb.Append("0 ");
                            }
                            else
                            {
                                sb.AppendFormat("{0} ", rand.Next(0, 2).ToString());
                            }
                        }
                        sw.WriteLine(sb.ToString().Trim());
                    }
                }
                Console.WriteLine("Test {0} ready!", testNumber);
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace NinjaTestGenerator
{
    class Program
    {
        static int[] tests = new int[] { 2, 5, 7, 8, 9, 10, 11, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14 };
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
                            else if (testNumber == 19 || testNumber == 13)
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

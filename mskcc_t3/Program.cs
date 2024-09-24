using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MSKCC_T3
{
    internal class Program
    {
        public static bool IsBalanced(string S)
        {
            bool bResult = true;
            for (int i = 0; i < S.Length; i++)
            {
                if ((Char.IsUpper(S[i]) && S.Contains(Char.ToLower(S[i]))) ||
                    (Char.IsLower(S[i]) && S.Contains(Char.ToUpper(S[i]))))
                {
                    continue;
                }
                else
                {
                    bResult = false;
                    break;
                }
            }
            return bResult;
        }
        public static string getSub(string input, int start, int end)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = start; i < end; i++)
                sb.Append(input[i]);
            return sb.ToString();
        }
        public static int solution(string S)
        {
            int min = -1;
            for (int i = 0; i < S.Length; i++)
            {
                for (int j = i + 1; j < S.Length + 1; j++)
                {
                    string sTemp = getSub(S, i, j);
                    if (IsBalanced(sTemp)){
                        if(min == -1)
                            min = sTemp.Length;
                        else
                            min = Math.Min(min, sTemp.Length);
                    }
                }
            }
            return min;
        }
        static void Main(string[] args)
        {
            Console.WriteLine(solution("azABaabza"));
            Console.WriteLine(solution("TacoCat"));
            Console.WriteLine(solution("AcZCbaBz"));
            Console.WriteLine(solution("abcdefghijl"));
        }
    }
}

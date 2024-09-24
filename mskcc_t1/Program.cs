using System;
using System.Collections.Generic;

namespace MSKCC_T1
{
    internal class Program
    {
        public static int solution(int[] A)
        {
            int ans = A[0];
            for (int i = 1; i < A.Length; i++)
            {
                if (A[i] < ans)
                {
                    ans = A[i];
                }
            }
            return ans;
        }
        static void Main(string[] args)
        {
            int[] A = { -1, 1, -2, 2 };
            Console.WriteLine(solution(A));
        }
    }
}

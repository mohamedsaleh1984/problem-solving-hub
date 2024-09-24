using System;
using System.Linq;

namespace MSKCC_T2
{
    internal class Program
    {
        public static bool IsAllBeez(string s)
        {
            char[] chars = s.ToCharArray();
            return chars.All(x => x == 'B');
        }
        public static bool IsAllAaaz(string s)
        {
            char[] chars = s.ToCharArray();
            return chars.All(x => x == 'A');
        }
        public static int Solution(string S)
        {
            char[] original = S.ToCharArray();
            char[] chars = S.ToCharArray();
            Array.Sort(chars);
            int counter = 0;
            for (int i = 0; i < chars.Length; i++)
            {
                if (original[i] != chars[i])
                    counter++;
            }
            return counter;

        }
        public static int SolutionX(string S)
        {
            if (IsAllAaaz(S))
                return -1;

            if (IsAllBeez(S))
                return -1;
            
            int operations = 0;
            int leftPtr = 0;
            int rightPtr = S.Length - 1;
            
            while (leftPtr <= rightPtr)
            {
                if (leftPtr == rightPtr)
                    break;

                char leftChar = S[leftPtr];
                char rightChar = S[rightPtr];
                
                while(leftChar == 'A')
                {
                    leftPtr++;
                    leftChar = S[leftPtr];
                }

                while (rightChar == 'B')
                {
                    rightPtr--;
                    rightChar = S[rightPtr];
                }

                if (leftChar == 'B')
                {
                    operations++;
                    leftPtr++;
                }
                if (rightChar == 'A')
                {
                    operations++;
                    rightPtr--;
                }
                    
                
            }
            return operations;
        }

       static void Main(string[] args)
        {
            string s = "BAAABAB";
            Console.WriteLine(SolutionX(s));
            s = "BBABAA";
            Console.WriteLine(SolutionX(s));
            s = "AABBBBB";
            Console.WriteLine(SolutionX(s));
        }
    }
}
//    public static int solution2(string S)
//{
//    int leftPtr = 0;
//    int rightPtr = S.Length-1;
//    int operations = 0;
//    while (leftPtr < rightPtr)
//    {
//        char leftChar = S[leftPtr];
//        char rightChar = S[rightPtr];

//        while (leftChar == 'A')
//        {
//            leftPtr++;
//            leftChar = S[leftPtr];
//        }
//        while (rightChar == 'B')
//        {
//            rightPtr--;
//            rightChar = S[rightPtr];
//        }

//        if (leftChar == 'B')
//        {
//            operations++;
//            leftPtr++;
//        }

//        if (rightChar == 'A')
//        {
//            operations++;
//            rightPtr--;
//        }
//    }
//    return operations;
//}

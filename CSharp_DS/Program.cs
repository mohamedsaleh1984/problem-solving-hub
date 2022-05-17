using System;
using System.Collections.Generic;

namespace CSharp_DS
{
    internal class Program
    {
        public static int solutionMissingInteger(int[] A)
        {
            int solution = 1;
            HashSet<int> hashSet = new HashSet<int>();

            for (int i = 0; i < A.Length; ++i)
            {
                if (A[i] < 1) continue;
                if (hashSet.Add(A[i]))
                {
                    //this int was not handled before
                    while (hashSet.Contains(solution))
                    {
                        solution++;
                    }
                }
            }

            return solution;
        }
        public static int solution(int[] A)
        {
            Array.Sort(A);
            int min = 1;
            for (int i = 0; i < A.Length; i++)
            {
                if (A[i] == min)
                {
                    min++;
                }
            }

            return min;
        }
        static void Main(string[] args)
        {
            int[] A = { 1, 3, 6, 4, 1, 2 };
            Console.WriteLine(solutionMissingInteger(A));
            //Dictionary<string, int> dic = new Dictionary<string, int>();
            //dic.Add("Name", 3131);
            //dic.ContainsKey("name");
            //dic.Remove("name");

            //Stack<int> stack = new Stack<int>();
            //Queue<int> queue = new Queue<int>();    
            //queue.Enqueue(1);
            //queue.Dequeue();

            //List<int> list = new List<int>();
            //list.ForEach(x => {
            //    Console.WriteLine(x);
            //});

            //LinkedList<int> l = new LinkedList<int>();  

            //HashSet<int> set = new HashSet<int>();

        }
    }
}

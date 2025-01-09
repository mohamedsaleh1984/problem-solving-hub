using System;
using System.Collections.Generic;
using System.IO;
using System.Threading;
using System.Linq;

namespace StrayToDoJobs
{

    internal class Program
    {
        private static string location = "D:\\Problem-Solving-Hub";
        static void Main(string[] args)
        {
            List<string> extensions = new List<string>() { "cpp", "h", "txt", "cs" };
            List<string> files = getAllFiles(location, extensions);

            ////Console.WriteLine("With Threads...");
            //long start = DateTime.Now.Ticks;
            ////files = findFilesWithToDoTagThreads(files);
            ////foreach (var file in files)
            ////    Console.WriteLine(file);
            ////Console.WriteLine("Time Consumed with Threads " + Convert.ToString(DateTime.Now.Ticks - start));

            //Console.WriteLine("\n");

            //Console.WriteLine("Without Threads...");
            //start = DateTime.Now.Ticks;
            files = findFilesWithToDoTag(files);
            foreach (var file in files)
                Console.WriteLine(file);
          //  Console.WriteLine("Time Consumed with Threads " + Convert.ToString(DateTime.Now.Ticks - start));
            Console.ReadLine();
        }



        private static List<string> getAllFiles(string directory, List<string> ext)
        {
            List<string> files = Directory.GetFiles(directory, "", SearchOption.AllDirectories).ToList();
            files = filterFiles(files, ext);
            return files;
        }
        private static List<string> filterFiles(List<string> files, List<string> acceptedExtensions)
        {
            List<string> filesToReturn = new List<string>();
            foreach (var ext in acceptedExtensions)
            {
                filesToReturn.AddRange(files.Where(x => x.EndsWith(ext)).ToList());
            }
            return filesToReturn;
        }
        private static List<string> findFilesWithToDoTag(List<string> files)
        {
            List<string> filesList = new List<string>();
            foreach (var file in files)
            {
                if (hasToDo(file))
                    filesList.Add(file);
            }
            return filesList;
        }
        private static bool hasToDo(string filePath)
        {
            string[] lines = File.ReadAllLines(filePath);
            foreach (var line in lines)
            {
                var lowerCase = line.ToLower();
                if (lowerCase.Contains("todo:"))
                    return true;
            }
            return false;
        }
        private static List<string> findFilesWithToDoTagThreads(List<string> files)
        {
            List<Thread> threadsList = new List<Thread>();
            bool[] threadResult = new bool[files.Count];
            int index = 0;
            foreach (var item in files)
            {
                threadsList.Add(new Thread(() =>
                {
                    threadResult[index] = hasToDo(item);
                    index++;
                }));

            }

            foreach (var thread in threadsList)
            {
                thread.Start();
                thread.Join();
            }

            List<string> filesToReturn = new List<string>();
            index = 0;
            foreach (var item in threadResult)
            {
                if (item)
                {
                    filesToReturn.Add(files[index]);
                }
                index++;
            }



            return filesToReturn;
        }
    }
}
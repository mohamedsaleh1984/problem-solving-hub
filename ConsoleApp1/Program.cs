using System;
using System.Collections.Generic;

namespace Ch03_6_AnimalShelter_cs
{
    public abstract class Animal
    {
        public Animal(string n, int a, DateTime e)
        {
            name = n;
            age = a;
            entryDate = e;
        }
        public abstract void MakeSound();
        public DateTime entryDate { get; set; }
        public int age { get; set; }
        public string name { get; set; }

    }
    public class Dog : Animal
    {
        public Dog(string name, int age, DateTime ent) : base(name, age, ent)
        { }

        public override void MakeSound()
        {
            Console.WriteLine("Woof !!");
        }

        public override string ToString()
        {
            return "I\'m a Dog with Name " + name + ", age " + age + " entry Date::" + entryDate.ToShortDateString();
        }
    }
    public class Cat : Animal
    {
        public Cat(string name, int age, DateTime ent) : base(name, age, ent)
        { }
        public override void MakeSound()
        {
            Console.WriteLine("Meaw !!");
        }
        public override string ToString()
        {
            return "I\'m a Cat with Name " + name + ", age " + age + " entry Date::" + entryDate.ToShortDateString();
        }
    }
    public class AnimalShelter
    {
        private Queue<Cat> catQueue;
        private Queue<Dog> dogQueue;
        private bool turn;
        public AnimalShelter()
        {
            catQueue = new Queue<Cat>();
            dogQueue = new Queue<Dog>();
        }
        public Dog dequeueDog()
        {
            if (dogQueue.Count == 0)
            {
                Console.WriteLine("NO DOGS ...");
                return null;
            }
            Dog d = dogQueue.Dequeue();
            return d;
        }

        public Cat dequeueCat()
        {
            if (catQueue.Count == 0)
            {
                Console.WriteLine("NO CATS...");
                return null;
            }
            Cat c = catQueue.Dequeue();
            return c;
        }

        public Animal dequeueAny()
        {
            turn = !turn;

            if (turn)
            {
                if (!(dogQueue.Count == 0))
                {
                    return dequeueDog();
                }
                else
                {
                    if (!(catQueue.Count == 0))
                    {
                        return dequeueCat();
                    }
                    else
                    {
                        Console.WriteLine("NO ANIMALS AVALIABLE FOR ADOPTION.");
                    }
                }
            }
            else
            {
                if (!(catQueue.Count == 0))
                {
                    return dequeueCat();
                }
                else if (!(dogQueue.Count == 0))
                {
                    return dequeueDog();
                }
                else
                {
                    Console.WriteLine("NO ANIMALS AVALIABLE FOR ADOPTION.");
                }
            }

            return null;
        }

        public void enqueue(Animal an)
        {
            if (an is Cat)
            {
                Cat c = (Cat)an;
                catQueue.Enqueue(c);
            }
            else
            {
                Dog dog = (Dog)an;
                dogQueue.Enqueue(dog);
            }
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            AnimalShelter animalShelter = new AnimalShelter();
            animalShelter.enqueue(new Cat("Catty", 1, DateTime.Now));
            animalShelter.enqueue(new Cat("Zeta", 2, DateTime.Now));
            animalShelter.enqueue(new Dog("Nitty", 3, DateTime.Now));
            animalShelter.enqueue(new Dog("Rock", 5, DateTime.Now));
            animalShelter.enqueue(new Dog("Rx", 1, DateTime.Now));


        }
    }
}

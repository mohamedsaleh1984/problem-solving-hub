#include "../common.h"

class Animal {
public:
	Animal(int age) {
		entryDate = time(0);
		setAge(age);
	}
	void setAge(int age) {
		this->age = age;
	}
	int getAge() {
		return this->age;
	}
	time_t getTime() {
		return this->entryDate;
	}
	virtual  void MakeSound() {
		cout << "Animal Sound" << endl;
	}
	virtual string name() const { return "Animal"; }
	virtual ~Animal() {}
	friend ostream& operator<<(ostream& os, const Animal& d);
private:
	time_t entryDate;
	int age = 0;
};
ostream& operator<<(ostream& os, const Animal& d)
{
	return os;
}


class Dog : public Animal {
public:
	Dog(int age) :Animal(age) {
		myTime = time(0);
	}
	void MakeSound() {
		cout << "Woof" << endl;
	}
	virtual ~Dog() {
		//cout << "Dog destructor" << endl;
	}
	string name() const { return "Dog"; }
	friend ostream& operator<<(ostream& os, const Dog& d);
private:
	time_t myTime;
};

ostream& operator<<(ostream& os, const Dog& d)
{
	os << "In Derived -- DOG";
	//os << static_cast<const Animal&>(d);
	return os;
}

class Cat : public Animal {
public:
	Cat(int age) :Animal(age) {
		myTime = time(0);
	}
	void MakeSound() {
		cout << "Meao" << endl;
	}
	virtual ~Cat() {
		//cout << "Cat destructor" << endl;
	}
	string name() const { return "Cat"; }
	friend ostream& operator<<(ostream& os, const Cat& c);
private:
	time_t myTime;
};

ostream& operator<<(ostream& os, const Cat& c)
{
	os << "I am a Cat---Meaw, I arrived " <<  c.myTime;
	return os;
}

class NullAnimal : public Animal {
public:
};

class AnimalShelter {
private:
	queue<Cat> catQueue;
	queue<Dog> dogQueue;
	bool turn;
public:
	AnimalShelter() {
		turn = true;
	}

	void enqueue(Animal* an) {
		if (an->name() == "Cat") {
			Cat* pChild = (Cat*)&an;
			Cat c(pChild->getAge());
			catQueue.push(c);
		}
		else if (an->name() == "Dog") {
			Dog* pChild = (Dog*)&an;
			Dog d(pChild->getAge());
			dogQueue.push(d);
		}
	}

	Dog dequeueDog() {
		if (dogQueue.empty()) {
			cout << "NO DOGS ...";
			return NULL;
		}
		Dog d = dogQueue.front();
		dogQueue.pop();
		return d;
	}

	Cat dequeueCat() {
		if (catQueue.empty()) {
			cout << "NO CATS...";
			return NULL;
		}
		Cat c = catQueue.front();
		catQueue.pop();
		return c;
	}

	Animal dequeueAny() {
		turn = !turn;

		if (turn) {
			if (!dogQueue.empty()) {
				return dequeueDog();
			}
			else
			{
				if (!catQueue.empty()) {
					return dequeueCat();
				}
				else
				{
					cout << "NO ANIMALS AVALIABLE FOR ADOPTION.";
				}
			}
		}
		else {
			if (!catQueue.empty()) {
				return dequeueCat();
			}
			else if (!dogQueue.empty()) {
				return dequeueDog();
			}
			else
			{
				cout << "NO ANIMALS AVALIABLE FOR ADOPTION.";
			}	
		}
	}
};

int main()
{
	AnimalShelter _ani_shelter;
	_ani_shelter.enqueue(new Dog(3));
	_ani_shelter.enqueue(new Cat(1));
	_ani_shelter.enqueue(new Cat(2));
	_ani_shelter.enqueue(new Dog(3));
	_ani_shelter.enqueue(new Dog(4));
	_ani_shelter.enqueue(new Dog(8));
	
	cout << _ani_shelter.dequeueCat() << endl;
	cout << _ani_shelter.dequeueAny() << endl;
	cout << _ani_shelter.dequeueAny() << endl;
	cout << _ani_shelter.dequeueAny() << endl;
	return 0;
}

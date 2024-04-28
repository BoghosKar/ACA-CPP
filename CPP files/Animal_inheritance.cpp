/*Ստեղծել class Animal և նրանից ժառանգել ևս 5 class և վերասհամանել voice function-ը յուրաքանչյուր class-ի համար 
պհաել ժառանգ դասի բոլոր օբյեկտերը 1 ընդհանուր կոնտոյների մեջ և ցիկլով կանչել յուրաքանչյուևի voic-ը*/
#include <iostream>

class Animal
{
public:
    Animal()
    {
        std::cout << "Call Animal Constructor" << std::endl;
    }

    virtual void voice() const
    {
        std::cout << "Animal Sound";
    }

    virtual ~Animal()
    {
        std::cout << "Call Animal Destructor" << std::endl;
    }
};

class Dog : public Animal
{
public:
    Dog() 
    {
        std::cout << "Call Dog Constructor" << std::endl;
    }

    void voice() const override
    {
        std::cout << "Woof" << std::endl;
    }

    ~Dog() 
    {
        std::cout << "Call Dog Destructor" << std::endl;
    }
};

class Cat : public Animal
{
public:

    Cat() 
    {
        std::cout << "Call Cat Constructor" << std::endl;
    }

    void voice() const override
    {
        std::cout << "Meow" << std::endl;
    }
    
    ~Cat() 
    {
        std::cout << "Call Cat Destructor" << std::endl;
    }
};

class Cow : public Animal
{
public:

    Cow() 
    {
        std::cout << "Call Cow Constructor" << std::endl;
    }

    void voice() const override
    {
        std::cout << "Moo" << std::endl;
    }

    ~Cow() 
    {
        std::cout << "Call Cow Destructor" << std::endl;
    }
};

class Sheep : public Animal
{
public:

    Sheep() 
    {
        std::cout << "Call Sheep Constructor" << std::endl;
    }

    void voice() const override
    {
        std::cout << "Baaaa" << std::endl;
    }

    ~Sheep() 
    {
        std::cout << "Call Sheep Destructor" << std::endl;
    }
};

class Snake : public Animal
{
public:

    Snake() 
    {
        std::cout << "Call Snake Constructor" << std::endl;
    }

    void voice() const override
    {
        std::cout << "sssssss" << std::endl;
    }

    ~Snake() 
    {
        std::cout << "Call Snake Destructor" << std::endl;
    }

};

int main()
{
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    Animal* cow = new Cow();
    Animal* sheep = new Sheep();
    Animal* snake = new Snake();

    const int numAnimals = 5;
    Animal* animals[numAnimals] = {dog, cat, cow, sheep, snake};

    for (int i = 0; i < numAnimals; i++)
    {
        animals[i]->voice();
    }

    for (int i = 0; i < numAnimals; i++)
    {
        delete animals[i];
    }

    return 0;
}
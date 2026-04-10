#include <iostream>
#include <string>
#include <Windows.h>

class Animal {
protected:
    std::string name;
    std::string species;
    int age;
    double weight;

public:
    Animal(const std::string& n, const std::string& s, int a, double w)
        : name(n), species(s), age(a), weight(w) {
    }

    void eat() const {
        std::cout << name << " Кушает." << std::endl;
    }

    void sleep() const {
        std::cout << name << " Спит." << std::endl;
    }

    virtual void makeSound() const {
        std::cout << name << " Издает звук." << std::endl;
    }

    virtual void printInfo() const {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Вид: " << species << std::endl;
        std::cout << "Возраст: " << age << std::endl;
        std::cout << "Вес: " << weight << " кг" << std::endl;
    }

    virtual ~Animal() {}
};

class Dog : public Animal {
private:
    std::string breed;
    bool isTrained;
    int energyLevel;

public:
    Dog(const std::string& n, int a, double w,
        const std::string& b, bool t, int e)
        : Animal(n, "Собака", a, w),
        breed(b), isTrained(t), energyLevel(e) {
    }

    void bark() const {
        std::cout << name << " Лает." << std::endl;
    }

    void play() const {
        std::cout << name << " Играет." << std::endl;
    }

    void poop() const {
        std::cout << name << " Срёт." << std::endl;
    }

    void makeSound() const override {
        bark();
    }

    void printInfo() const override {
        Animal::printInfo();
        std::cout << "Порода: " << breed << std::endl;
        std::cout << "Дрессирован: " << (isTrained ? "Да" : "Нет") << std::endl;
        std::cout << "Энергия: " << energyLevel << std::endl;
    }
};

class Cat : public Animal {
private:
    std::string color;
    int lives;
    bool isLazy;

public:
    Cat(const std::string& n, int a, double w,
        const std::string& c, int l, bool lazy)
        : Animal(n, "Кошка", a, w),
        color(c), lives(l), isLazy(lazy) {
    }

    void meow() const {
        std::cout << name << " Мяукает." << std::endl;
    }

    void purr() const {
        std::cout << name << " Мурлычет." << std::endl;
    }

    void burp() const {
        std::cout << name << " Блюёт комками шерсти." << std::endl;
    }

    void makeSound() const override {
        meow();
    }

    void printInfo() const override {
        Animal::printInfo();
        std::cout << "Цвет: " << color << std::endl;
        std::cout << "Жизни: " << lives << std::endl;
        std::cout << "Ленивая: " << (isLazy ? "Да" : "Нет") << std::endl;
    }
};

class Bird : public Animal {
private:
    double wingSpan;
    bool canFly;
    std::string habitat;

public:
    Bird(const std::string& n, int a, double w,
        double ws, bool fly, const std::string& h)
        : Animal(n, "Птица", a, w),
        wingSpan(ws), canFly(fly), habitat(h) {
    }

    void fly() const {
        if (canFly)
            std::cout << name << " Летает." << std::endl;
        else
            std::cout << name << " Не умеет летать." << std::endl;
    }

    void sing() const {
        std::cout << name << " Поёт." << std::endl;
    }

    void buildNest() const {
        std::cout << name << " Вьет гнездо." << std::endl;
    }

    void makeSound() const override {
        sing();
    }

    void printInfo() const override {
        Animal::printInfo();
        std::cout << "Размах крыльев: " << wingSpan << std::endl;
        std::cout << "Может летать: " << (canFly ? "Да" : "Нет") << std::endl;
        std::cout << "Среда обитания: " << habitat << std::endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Dog dog("Шарик", 3, 9.0, "Овчарка", true, 8);
    Cat cat("Мурка", 5, 6.5, "Белая", 9, true);
    Bird bird("Кеша", 2, 1.2, 0.4, true, "Лес");

    dog.printInfo();
    dog.makeSound();

    std::cout << std::endl;

    cat.printInfo();
    cat.makeSound();

    std::cout << std::endl;

    bird.printInfo();
    bird.makeSound();

    return 0;
}
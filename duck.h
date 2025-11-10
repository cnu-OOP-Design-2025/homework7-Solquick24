#pragma once

#include <iostream>
using namespace std;

class FlyBehavior {
public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() {}
};


class FlyWithWings : public FlyBehavior {
public:
    void fly() override {
        cout << "I can Fly!" << endl;
    }
};

class FlyNoWay : public FlyBehavior {
public:
    void fly() override {
        cout << "I can't fly..." << endl;
    }
};

class QuackBehavior {
public:
    virtual void quack() = 0;
    virtual ~QuackBehavior() {}
};

class Quack : public QuackBehavior {
public:
    void quack() override {
        cout << "Quack!" << endl;
    }
};

class Squeak: public QuackBehavior {
public:
    void quack() override {
        cout << "Squeak!" << endl;
    }
};

class MuteQuack : public QuackBehavior {
public:
    void quack() override {
        cout << "<<Silent>>" << endl;
    }
};

// 오리 클래스
class Duck {
protected:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;

public:
    Duck(): flyBehavior(nullptr), quackBehavior(nullptr) {}
    Duck(FlyBehavior* fb, QuackBehavior* qb)
        : flyBehavior(fb), quackBehavior(qb) {}

    virtual void display() = 0;
    
    void performFly();
    void performQuack();
    void setFlyBehavior(FlyBehavior* fb);
    void setQuackBehavior(QuackBehavior* qb);

    virtual ~Duck() {
        delete flyBehavior;
        delete quackBehavior;
    }
};

class MallardDuck : public Duck {
public:
    MallardDuck(); 
    void display() override {
        cout << "I'm a Mallar Duck." << endl;
    }
};

class RedheadDuck: public Duck{
public:
    RedheadDuck();
    void display() override {
        cout << "I'm a Redhead Duck." << endl;
    }
};

class RubberDuck: public Duck{
public:
    RubberDuck(); 
    void display() override {
        cout << "I'm a Rubber Duck." << endl;
    }
};

class DecoyDuck: public Duck{
public:
    DecoyDuck();
    void display() override {
        cout << "I'm a Decoy Duck." << endl;
    }
};

class ModelDuck: public Duck{
public:
    ModelDuck(); 
    void display() override {
        cout << "I'm a Decoy Duck." << endl;
    }
};


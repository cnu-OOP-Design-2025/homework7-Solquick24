#include <iostream>
#include "duck.h"

using namespace std;

// 메인 함수
int main() {
    Duck* ducks[] = {
        new MallardDuck(),
        new RedheadDuck(),
        new RubberDuck(),
        new DecoyDuck()
    };

    cout << "----------------------" << endl;

    const int numDucks = sizeof(ducks) / sizeof(ducks[0]);

    for (int i = 0; i < numDucks ; ++i) {
        cout << "Duck #" << i + 1 << ":" << endl;
        ducks[i]->display();
        ducks[i]->performFly();
        ducks[i]->performQuack();
        cout << "----------------------" << endl;
    }

    // free allocated ducks
    for (int i = 0; i < numDucks; ++i) delete ducks[i];

    ModelDuck model;

    cout << "ModelDuck (version 1)" << endl;
    model.display();
    model.performFly();
    model.performQuack();

    cout << "----------------------" << endl;

    cout << "ModelDuck (version 2)" << endl;
    model.setQuackBehavior(new Squeak());
    model.display();
    model.performFly();
    model.performQuack();

    cout << "----------------------" << endl;

    cout << "ModelDuck (version 3)" << endl;
    model.setFlyBehavior(new FlyWithWings());
    model.display();
    model.performFly();
    model.performQuack();

    cout << "----------------------" << endl;

    return 0;
}
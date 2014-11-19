#include <Noxis/Noxis.hpp>
#include <iostream>


using namespace std;
using namespace Noxis;

int main() {
    auto scene = (new Node("scene"))
        ->attachChild(
                (new Node("background"))
                    ->attachChild(new Node("asteroid"))
                    ->attachChild(new Node("sun"))
                    ->attachChild(new Node("star")))
        ->attachChild(
                (new Node("foreground"))
                    ->attachChild(new Node("player"))
                    ->attachChild(new Node("enemy"))
                    ->attachChild(new Node("sun"))
                    ->attachChild(new Node("bullet")));

    cout << scene->find("sun") << endl;

    delete scene;
}

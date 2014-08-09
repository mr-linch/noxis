#include <Noxis/Noxis.hpp>
#include <iostream>

USING_NOXIS_NS;

class SimpleScene : public Scene {
    public:
        virtual void onUpdate() {
            // Logic here
        }
};

int main() {
    auto engine = Engine::getInstance();
    engine->run(new SimpleScene());
}

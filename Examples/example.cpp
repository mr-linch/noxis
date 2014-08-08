#include <Noxis/Noxis.hpp>
#include <iostream>

USING_NOXIS_NS;

class HelloScene : public Scene {
    public:
        virtual void onUpdate() override {
            std::cout << "Hello Scene Managment!" << std::endl;
        }
};

int main() {
    auto engine = Engine::getInstance();
    engine->run(new HelloScene());
}

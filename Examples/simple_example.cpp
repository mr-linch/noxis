#include <Noxis/Noxis.hpp>

#include <iostream>

USING_NOXIS_NS;

class SimpleScene : public Scene {
    public:
        virtual void onStart() {
        }

        virtual void onUpdate() {
            // Logic here
        }
};

int main() {
    auto engine = Engine::getInstance();

    auto manager = Engine::getInstance()->getResourceManager();
    manager->load("images/backgroud.png", "bg");
    manager->load("images/foreground.png", "fg");
    
    manager->get("bg");

    return engine->run(new SimpleScene());
}

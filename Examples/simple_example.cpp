#include <Noxis/Noxis.hpp>

#include <iostream>

USING_NOXIS_NS;

class SimpleScene : public Scene {
        Texture *logo;
        Engine *engine = Engine::getInstance();
    public:
        virtual void onStart() {
            auto manager = engine->getResourceManager(); 
            logo = manager->load<Texture>("logo.png");
        }

        virtual void onUpdate() {
            // this is not right way. only for test!
            logo->draw();
        }
};

int main() {
    auto engine = Engine::getInstance();
    return engine->run(new SimpleScene());
}

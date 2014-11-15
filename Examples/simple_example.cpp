#include <Noxis/Noxis.hpp>

USING_NOXIS_NS;

class SimpleScene : public Scene {
    public:
        virtual void onUpdate() {
            // Logic here
        }
};

int main() {
    auto engine = Engine::getInstance();
    return engine->run(new SimpleScene());
}

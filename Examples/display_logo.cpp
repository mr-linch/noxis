#include <Noxis/Noxis.hpp>

USING_NOXIS_NS;

int main() {
    auto engine = Engine::getInstance();

    // Initialize all subsystem
    engine->initialize("Noxis");
    
    // Get renderer
    auto renderer = engine->getRenderer();

    // Create scene
    auto scene = new Scene();
    
    // Create sprite
    auto logo = new Sprite("logo.png", scene);

    // Set position of sprite
    logo->setPosition((renderer->getViewportSize() - logo->getSize()) / 2);
    
    // Run main loop
    return engine->run(scene);
}

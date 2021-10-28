#ifndef SPRITERENDERER_H_
#define SPRITERENDERER_H_

#include "Component.hpp"
#include "Color.hpp"
#include <string>
#include <memory>

namespace spic {

    /**
     * @brief A component representing a sprite (small image)
     */
    class Sprite : public Component {
    public:
        Sprite();
        Sprite(std::shared_ptr<GameObject> gameObject) : color{Color::green()} {
            std::shared_ptr<Component> body = gameObject->GetComponent<RigidBody>();
            Component* bodyC = body.get();
            RigidBody* r = (RigidBody*)bodyC;
            x = r->getBody()->GetPosition().x;
            y = r->getBody()->GetPosition().y;
            
        }

        int x;
        int y;
        int w;
        int h;
        std::string shape;
    private:
        std::string sprite;
        Color color;
        bool flipX;
        bool flipY;
        int sortingLayer;
        int orderInLayer;
    };

}

#endif // SPRITERENDERER_H_

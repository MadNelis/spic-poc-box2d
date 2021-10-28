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
            setType("Sprite");
            std::shared_ptr<Component> body = gameObject->GetComponent<RigidBody>();
            Component* bodyC = body.get();
            RigidBody* r = (RigidBody*) bodyC;
            x = r->getBody()->GetPosition().x;
            y = r->getBody()->GetPosition().y;

            if (r->getShape() == "Circle") {
                float radius = r->getBody()->GetFixtureList()[0].GetShape()->m_radius;
                w = (int) radius * 2;
                h = (int) radius * 2;
            } else if (r->getShape() == "Polygon") {
                b2Vec2* bodyVertice = &(((b2PolygonShape*) r->getBody()->GetFixtureList()[0].GetShape())->m_vertices[0]);
                float shapeWidth = std::abs(bodyVertice->x * 2);
                float shapeHeight = std::abs(bodyVertice->y * 2);

                w = shapeWidth;
                h = shapeHeight;
            }

            shape = r->getShape();
        }

        SDL_Rect* getSdlSprite() {
            SDL_Rect* sprite = new SDL_Rect();
            sprite->x = this->x;
            sprite->y = this->y;
            sprite->w = this->w;
            sprite->h = this->h;

            return sprite;
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

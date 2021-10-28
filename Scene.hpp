#ifndef SCENE_H_
#define SCENE_H_

#include <box2d/box2d.h>
#include <SDL.h>
#include "GameObject.hpp"
#include "RigidBody.hpp"

namespace spic {
    class RigidBody;

    class PhysicsWorld {
    public:
        b2World* b2world;

        PhysicsWorld() : b2world{new b2World{b2Vec2{0.0f, 0.0f}}} {
            SetContinuousPhysics(true);
        }

        void SetContinuousPhysics(bool val) {
            b2world->SetContinuousPhysics(val);
        }

        b2Body* createBody(const b2BodyDef* bodyDef) {
            return b2world->CreateBody(bodyDef);
        }

        void step(float timeStep, const int velocityIter, const int positionsIter) {
            b2world->Step(timeStep, velocityIter, positionsIter);
        }
    };

    /**
     * @brief Class representing a scene which can be rendered by the Camera.
     */
    class Scene {
    public:
        /**
         * @brief This function is called by a Camera to render the scene on the engine.
         */
        void RenderScene(SDL_Renderer* renderTarget);

        Scene();

        PhysicsWorld* world;

        std::vector<std::shared_ptr<GameObject>> contents;

        void addBody(RigidBody& body);

        /**
         * @brief This property contains all the Game Object that are contained in this scene.
         */
//            GameObject[] contents;


        void addBody(const std::shared_ptr<RigidBody> body);

        void addGameObject(const std::shared_ptr<GameObject> gameObject);


    };
}

#endif // SCENE_H_
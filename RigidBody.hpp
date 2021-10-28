#ifndef RIGIDBODY_H_
#define RIGIDBODY_H_

#include <box2d/box2d.h>
#include "Component.hpp"
#include "Point.hpp"
#include "Scene.hpp"

namespace spic {
    class Scene;
    /**
     * @brief Enumeration for different rigid body types
     */
    enum class BodyType {
        staticBody,
        kinematicBody,
        dynamicBody
    };

    /**
     * @brief A component representing a rigid body.
     */
    class RigidBody : public Component {
    public:
        RigidBody(BodyType bt, Scene& scene);

        /**
         * @brief Apply force to this rigid body.
         * @param forceDirection A point, used as a vector to indicate direction
         *        and magnitude of the force to be applied.
         */
        void AddForce(const Point& forceDirection);

        b2Body* getBody();
        b2BodyDef* getBodyDef();
        b2MassData* getBodyMassData();
        b2FixtureDef* getBallFixtureDef();

        void setBodyType(BodyType bt);

        void setMass(double mass);

        void setGravityScale(double gs);

        void createBall();

        void createWall(float x, float y, float w, float h);

    private:
        Scene& scene;

        b2Body* body;
        b2BodyDef* bodyDef;
        b2MassData* bodyMassData;
        b2CircleShape* fixtureShape;
        b2FixtureDef* fixtureDef;

        double mass;
        double gravityScale;
        BodyType bodyType;
    };

}

#endif // RIGIDBODY_H_

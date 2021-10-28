#include "RigidBody.hpp"

void spic::RigidBody::AddForce(const spic::Point& forceDirection) {

}

b2BodyDef* spic::RigidBody::getBodyDef() {
    return bodyDef;
}

void spic::RigidBody::setBodyType(spic::BodyType bt) {
    bodyType = bt;
}

void spic::RigidBody::setMass(double mass) {

}

void spic::RigidBody::setGravityScale(double gs) {

}

spic::RigidBody::RigidBody(BodyType bt, Scene& scene) : bodyType{bt}, scene{scene} {
    setType("RigidBody");
}

b2MassData* spic::RigidBody::getBodyMassData() {
    return bodyMassData;
}

b2FixtureDef* spic::RigidBody::getBallFixtureDef() {
    return fixtureDef;
}

void spic::RigidBody::createBall() {
    bodyDef = new b2BodyDef();
    bodyDef->type = b2_dynamicBody;
    bodyDef->position.Set(4.0f, -30.0f);
    bodyDef->linearVelocity.Set(40.0f, 0.0f);

    bodyMassData = new b2MassData();
    bodyMassData->mass = 0.0f;

    fixtureShape = new b2CircleShape();
    fixtureShape->m_radius = 1.0f;

    fixtureDef = new b2FixtureDef();
    fixtureDef->shape = fixtureShape;
    fixtureDef->density = 1.0f;
    fixtureDef->restitution = 1.0f;
    fixtureDef->friction = 0.0f;

    body = scene.world->createBody(bodyDef);

    body->SetBullet(true);
    body->SetMassData(bodyMassData);
    body->SetLinearDamping(0.0f);
    body->CreateFixture(fixtureDef);
}

void spic::RigidBody::createWall(float x, float y, float w, float h) {
    b2BodyDef* wallRightBodyDef = new b2BodyDef();
    wallRightBodyDef->type = b2_staticBody;
    wallRightBodyDef->position.Set(x, y);

    body = scene.world->createBody(wallRightBodyDef);

    b2PolygonShape* wallRightFixtureShape = new b2PolygonShape();
    wallRightFixtureShape->SetAsBox(w, h);

    b2FixtureDef* wallRightFixtureDef = new b2FixtureDef();
    wallRightFixtureDef->shape = wallRightFixtureShape;
    wallRightFixtureDef->density = 1.0f;

    body->CreateFixture(wallRightFixtureDef);
}

b2Body* spic::RigidBody::getBody() {
    return body;
}

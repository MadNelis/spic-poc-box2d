#include "Scene.hpp"
#include "Sprite.hpp"

spic::Scene::Scene() : world{new PhysicsWorld} {}

void spic::Scene::RenderScene(SDL_Renderer* renderTarget) {
    SDL_SetRenderDrawColor(
            renderTarget,
            0,
            0,
            0,
            255
    );
    SDL_RenderClear(renderTarget);

    SDL_SetRenderDrawColor(
            renderTarget,
            64,
            192,
            64,
            255
    );

    for (std::shared_ptr<GameObject> gameObject: contents) {
        std::shared_ptr<Component> sprite = gameObject->GetComponent<Sprite>();
        Component* bodyC = sprite.get();
        Sprite* s = (Sprite*) bodyC;

        SDL_RenderFillRect(renderTarget, s->getSdlSprite(gameObject));
    }

    SDL_RenderPresent(renderTarget);
}

void spic::Scene::addBody(const std::shared_ptr<RigidBody> body) {}

void spic::Scene::addGameObject(const std::shared_ptr<GameObject> gameObject) {
    contents.push_back(gameObject);
}

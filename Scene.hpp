#ifndef SCENE_H_
#define SCENE_H_

#include <box2d/b2_world.h>
#include "GameObject.hpp"

namespace spic {

    /**
     * @brief Class representing a scene which can be rendered by the Camera.
     */
    class Scene {
    public:
        /**
         * @brief This function is called by a Camera to render the scene on the engine.
         */
        void RenderScene();

        Scene();

        b2World* bw;

        /**
         * @brief This property contains all the Game Object that are contained in this scene.
         */
//            GameObject[] contents;
    };

}

#endif // SCENE_H_
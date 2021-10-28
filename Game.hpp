//
// Created by Nelis on 26-10-2021.
//

#ifndef SPIC_POC_BOX2D_GAME_HPP
#define SPIC_POC_BOX2D_GAME_HPP

#include <memory>

using namespace std;

class Game {
private:
public:
    constexpr static const float WORLD_WIDTH = 80.0f;
    constexpr static const float WORLD_HEIGHT = 60.0f;
    constexpr static const float SCREEN_WIDTH = 1280;
    constexpr static const float SCREEN_HEIGHT = 720;

    constexpr static const float PIXELS_PER_METER_X = SCREEN_WIDTH / WORLD_WIDTH;
    constexpr static const float PIXELS_PER_METER_Y = SCREEN_HEIGHT / WORLD_HEIGHT;

    Game();
    void run();
};


#endif //SPIC_POC_BOX2D_GAME_HPP

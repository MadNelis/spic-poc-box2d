cmake_minimum_required(VERSION 3.20)
project(spic_poc_box2d)

set(CMAKE_CXX_STANDARD 20)

set(BOX2D_INCLUDE_DIR  ${PROJECT_SOURCE_DIR}/box2d-master/include)

include_directories(${PROJECT_SOURCE_DIR}/SDL2-2.0.16/include)
link_directories(${PROJECT_SOURCE_DIR}/SDL2-2.0.16/lib/x64)

include_directories(${PROJECT_SOURCE_DIR}/box2d-2.4.1/include)
link_directories(${PROJECT_SOURCE_DIR}/box2d-2.4.1/build/bin/Debug)

add_executable(spic_poc_box2d main.cpp
        Animator.hpp
        AudioSource.hpp
        BehaviourScript.hpp
        BoxCollider.hpp
        Button.hpp
        Camera.hpp
        CircleCollider.hpp
        Collider.hpp
        Color.hpp
        Color.cpp
        Component.hpp
        Debug.hpp
        GameObject.hpp
        IKeyListener.hpp
        IMouseListener.hpp
        Input.hpp
        Point.hpp
        RigidBody.hpp
        Scene.hpp
        Sprite.hpp
        Text.hpp
        Time.hpp
        Time.cpp
        Transform.hpp
        UIObject.hpp
        Scene.cpp Game.cpp Game.hpp RigidBody.cpp GameObject.cpp)

target_link_libraries(spic_poc_box2d sdl2main sdl2)
target_link_libraries(spic_poc_box2d box2d)

// Game.h
#pragma once

#include <windows.h>
#include <gl/gl.h>

class Game {
public:
    virtual void initialize() = 0;
    virtual void play() = 0;
    virtual void end() = 0;
    virtual ~Game() {}
};


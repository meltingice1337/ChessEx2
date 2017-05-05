//
//  Game.h
//  ChessEx2
//
//  Created by Darius Costolas on 5/3/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <SDL2/SDL.h>
#include <memory>
#include "Graphics.h"

enum GameState
{
    GS_RUNNING = 0,
    GS_PAUSED  = 1,
    GS_QUIT    = 2
};

class Game
{
public:
    Game(const std::string& title, uint32_t width, uint32_t height,
         uint32_t framesPerSecond = 60);
    virtual ~Game();
    
    std::shared_ptr<Graphics> graphics;
    
    bool Run();
    void Exit();
    
    virtual void OnCleanup();
    virtual void OnInit();
    virtual void OnKeyDown(SDL_KeyboardEvent& event);
    virtual void OnKeyUp(SDL_KeyboardEvent& event);
    virtual void OnMouseButtonDown(SDL_MouseButtonEvent& event);
    virtual void OnMouseButtonUp(SDL_MouseButtonEvent& event);
    virtual void OnMouseMotion(SDL_MouseMotionEvent &event);
    virtual void OnResize(uint32_t width, uint32_t height);
    virtual void OnExit();
    virtual void OnUpdate();
    virtual void OnRender(std::shared_ptr<Graphics> graphics);
    
private:
    Game(const Game& rhs);
    Game& operator=(const Game& rhs);
    
    void Render();
    void Update();
    bool Init();
    void HandleEvent(SDL_Event& event);
    void Cleanup();
    
protected:
    GameState m_state;
    std::string m_title;
    uint32_t m_width;
    uint32_t m_height;
    uint32_t m_framesPerSecond;
    uint32_t m_timePerFrame;
    
    //
    // SDL
    //
    SDL_Window* m_window;
    SDL_GLContext m_glContext;
};

#endif //__GAME_H_

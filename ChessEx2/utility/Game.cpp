//
//  Game.h
//  ChessEx2
//
//  Created by Darius Costolas on 5/3/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#include <iostream>
#include "Game.h"

Game::Game(const std::string &title, uint32_t width, uint32_t height,
           uint32_t framesPerSecond)
: m_state(GS_RUNNING),
m_title(title),
m_width(width),
m_height(height),
m_framesPerSecond(framesPerSecond),
m_timePerFrame(1000 / framesPerSecond), // milliseconds
m_window(nullptr)
{
    
}

Game::~Game()
{
    
}

bool Game::Init()
{
    //
    // INITIALIZE SDL
    //
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "ERROR: Initializing SDL." << '\n';
        return false;
    }
    
    //
    // GL CONTEXT ATTRIBUTES
    //
     SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
     SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
    //
    // CREATING WINDOW
    //
    m_window = SDL_CreateWindow(
                                m_title.c_str(),
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                m_width,
                                m_height,
                                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
                                );
    
    if(m_window == NULL)
    {
        std::cerr << "ERROR: Creating the SDL Window." << '\n';
        return false;
    }
    this->graphics = std::shared_ptr<Graphics>(new Graphics(*m_window));
    
    //
    // CREATING GL CONTEXT
    //
    // m_glContext = SDL_GL_CreateContext(m_window);
    // SDL_GL_MakeCurrent(m_window, m_glContext);
    // SDL_GL_SetSwapInterval(1);
    
    OnInit();
    
    return true;
}

void Game::OnInit()
{
    // override
}

void Game::Render()
{
    OnRender(this->graphics);
    
    // SDL_GL_SwapWindow(m_window);
}

void Game::Update()
{
    OnUpdate();
}

bool Game::Run()
{
    if(!Init())
    {
        std::cerr << "ERROR: Initializing the Game." << '\n';
        return false;
    }
    
    SDL_Event event;
    
    while(m_state == GS_RUNNING)
    {
        Uint32 start = SDL_GetTicks();
        
        HandleEvent(event);
        Update();
        Render();
        
        Uint32 elapsedTime = SDL_GetTicks() - start;
        if(m_timePerFrame > elapsedTime)
        {
            SDL_Delay(m_timePerFrame - elapsedTime);
        }
    }
    
    Cleanup();
    return true;
}

void Game::HandleEvent(SDL_Event &event)
{
    //
    // EVENTS
    //
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                Exit();
                break;
            case SDL_KEYDOWN:
                OnKeyDown(event.key);
                break;
            case SDL_KEYUP:
                OnKeyUp(event.key);
                break;
            case SDL_MOUSEMOTION:
                OnMouseMotion(event.motion);
                break;
            case SDL_MOUSEBUTTONDOWN:
                OnMouseButtonDown(event.button);
                break;
            case SDL_MOUSEBUTTONUP:
                OnMouseButtonUp(event.button);
                break;
        }
    }
}


void Game::Cleanup()
{
    OnCleanup();
    
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Game::OnCleanup()
{
    // override
}

void Game::OnKeyDown(SDL_KeyboardEvent& event)
{
    // ovveride
}

void Game::OnKeyUp(SDL_KeyboardEvent& event)
{
    // override
}

void Game::OnResize(uint32_t width, uint32_t height)
{
    // override
}

void Game::Exit()
{
    OnExit();
    
    m_state = GS_QUIT;
}

void Game::OnExit()
{
    // override
}

void Game::OnUpdate()
{
    // override
}

void Game::OnRender(std::shared_ptr<Graphics> graphics)
{
    // override
}

void Game::OnMouseButtonDown(SDL_MouseButtonEvent& event)
{
    // ovveride
}


void Game::OnMouseButtonUp(SDL_MouseButtonEvent &event)
{
    // ovveride

}

void Game::OnMouseMotion(SDL_MouseMotionEvent& event)
{
    // ovveride
}

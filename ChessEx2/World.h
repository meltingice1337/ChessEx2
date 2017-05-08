//
//  World.h
//  ChessEx2
//
//  Created by Darius Costolas on 5/3/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#ifndef World_h
#define World_h

#include <memory>
#include <iostream>
#include "utility/Graphics.h"
#include "utility/SpriteManager.h"
#include "Board.h"

class World
{
public:
    ~World();
    
    void Initialize(uint32_t width, uint32_t height);
    void OnKeyDown(uint8_t key);
    void OnKeyUp(uint8_t key);
    void OnMouseMove(int x, int y);
    void OnMouseClick(int button, int state, int x, int y);
    void OnUpdate();
    void OnRender(std::shared_ptr<Graphics> graphics);
    
    float GetWidth() const;
    float GetHeight() const;
    float GetLeft() const;
    float GetRight() const;
    float GetBottom() const;
    float GetTop() const;
    
    static World& GetInstance()
    {
        static World instance;
        return instance;
    }
    
private:
    World()
    {
#ifdef _DEBUG
        std::cout << "Creating the World" << std::endl;
#endif
    };
    // non-copyable
    World(const World& rhs);
    World& operator=(const World& rhs);
    
    uint32_t m_width;
    uint32_t  m_height;
};

#endif //__WORLD_H_

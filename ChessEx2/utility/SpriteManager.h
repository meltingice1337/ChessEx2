//
//  SpriteManager.h
//  ChessEx2
//
//  Created by Darius Costolas on 5/8/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#ifndef SpriteManager_h
#define SpriteManager_h

#include "Sprite.h"
#include <map>

class SpriteManager
{
public:
    std::shared_ptr<Sprite> GetSprite(std::string spriteName);
    void AddSprite(std::string spriteName, std::shared_ptr<Sprite> sprite);
    static SpriteManager& GetInstance()
    {
        static SpriteManager instance;
        return instance;
    }
private:
    std::map <std::string, std::shared_ptr<Sprite>> sprites;

};

#endif /* SpriteManager_h */

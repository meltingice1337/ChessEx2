//
//  SpriteManager.cpp
//  ChessEx2
//
//  Created by Darius Costolas on 5/8/17.
//  Copyright © 2017 Darius Costolas. All rights reserved.
//

#include "SpriteManager.h"

void SpriteManager::AddSprite(std::string spriteName, std::shared_ptr<Sprite> sprite)
{
    GetInstance().sprites.insert(std::make_pair(spriteName, sprite));
}

std::shared_ptr<Sprite> SpriteManager::GetSprite(std::string spriteName)
{
    return std::shared_ptr<Sprite>(GetInstance().sprites.find(spriteName)->second);
}

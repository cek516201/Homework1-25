#include "Sun.h"

void Sun::draw()
{
  SDLGameObject::draw(SDL_FLIP_NONE, rotation);
}

void Sun::update()
{
  rotation += rotationVelocity;

  if(rotation >= 360) 
    rotation -= 360;
}
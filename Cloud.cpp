#include "Cloud.h"

void Cloud::draw()
{
  SDLGameObject::draw();
}

void Cloud::update()
{
  // SDL_GetTicks()는 밀리세컨드이므로 10프레임
  m_currentFrame = SDL_GetTicks() / 100 % 3;

  if(m_position.getX() <= 0 || m_position.getX() + 96 >= 640)
    m_velocity.setX(-m_velocity.getX());

  SDLGameObject::update();
}
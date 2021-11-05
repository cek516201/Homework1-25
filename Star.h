#ifndef _Star_H_
#define _Star_H_

#include "SDLGameObject.h"

class Star : public SDLGameObject
{
public:
  Star(const LoaderParams* pParams) : SDLGameObject(pParams)
  {
    m_velocity.setX(1.5);
    m_velocity.setY(1.5);
  }
  void draw();
  void update();
  void clean() {}
};

#endif
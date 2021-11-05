#ifndef _Cloud_H_
#define _Cloud_H_

#include "SDLGameObject.h"

class Cloud : public SDLGameObject
{
public:
  Cloud(const LoaderParams* pParams) : SDLGameObject(pParams)
  {
    m_velocity.setX(1.0);
  }
  void draw();
  void update();
  void clean() {}
};

#endif
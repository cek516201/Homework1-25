#ifndef _Background_H_
#define _Background_H_

#include "SDLGameObject.h"

class Background : public SDLGameObject
{
public:
  Background(const LoaderParams* pParams) : SDLGameObject(pParams) {}
  void draw();
  void update();
  void clean() {}
};

#endif
#ifndef _Sun_H_
#define _Sun_H_

#include "SDLGameObject.h"

class Sun : public SDLGameObject
{
public:
  Sun(const LoaderParams* pParams) : SDLGameObject(pParams) {}
  void draw();
  void update();
  void clean() {}

private:
  float rotation = 0.0;
  float rotationVelocity = 1.0;
};

#endif
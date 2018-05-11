#ifndef Room_H
#define Room_H

#include <GL/gl.h>
#include "SceneElement.h"
#include "Floor.h"
#include "Rwall.h"

typedef float vec3[3];

class Room : public SceneElement
{
public:
  Room(ShaderIF* sIF, const char* texImageSource_mat, const char* texImageSource_wood);
  virtual ~Room();
  void getMCBoundingBox(double* xyzLimits) const;
  void render();

private:
  const char* woodTexture;
  const char* matTexture;
  float xmin, xmax, ymin, ymax, zmin, zmax;
  double kd[3];
  Floor* arrayFloor[9];
  Rwall* arrayWall[7];

  void defineInitialGeometry();

};

#endif

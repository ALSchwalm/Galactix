#ifndef TERRAIN_H
#define TERRAIN_H

#include "Global.h"
#include "AsteroidField.h"
#include "Space.h"
#include <noise/noise.h>
#include <noiseutils.h>


namespace Terrain
{
    void seed_terrain();
    void calculate_terrain();

};

#endif // TERRAIN_H

#include "Terrain.h"


void Terrain::calculate_terrain()
{
    module::Perlin perlinModule;
    perlinModule.SetPersistence(0.25);
    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderPlane heightMapBuilder;
    heightMapBuilder.SetSourceModule(perlinModule);
    heightMapBuilder.SetDestNoiseMap(heightMap);

    heightMapBuilder.SetDestSize(FIELD_WIDTH, FIELD_HEIGHT);

    //make these values random
    int x = rand() % 10;
    int y = rand() % 10;

    heightMapBuilder.SetBounds(x, x+10, y, y+10);
    heightMapBuilder.Build();

    for (int i = 0; i < FIELD_WIDTH; i++)
    {
        for (int j = 0; j < FIELD_HEIGHT; j++)
        {
            Space * sp = new Space();
            field[i][j] = Cell(i, j, sp);

            if (heightMap.GetValue(i, j) > 0.6)
            {
                field[i][j].set_sp(new AsteroidField());
            }
        }
    }
}

#include "init.h"
#include "masks.h"

void init_rays() {
  for(int i = 0; i < 64; i++) {
    rays[NORTH][i] = ray_north(i);
    rays[NO_EAST][i] = ray_north_east(i);
    rays[EAST][i] = ray_east(i);
    rays[SO_EAST][i] = ray_south_east(i);
    rays[SOUTH][i] = ray_south(i);
    rays[SO_WEST][i] = ray_south_west(i);
    rays[WEST][i] = ray_west(i);
    rays[NO_WEST][i] = ray_north_west(i);
  }
}

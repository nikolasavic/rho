#include "init.h"
#include "masks.h"

int initialized = 0;

void init_rays(void) {
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

void init_king_moves(void) {
  for(int i = 0; i < 64; i++) {
    king_moves[i] = king_attack_mask(i);
  }
}

void init_knight_moves(void) {
  for(int i = 0; i < 64; i++) {
    knight_moves[i] = knight_attack_mask(i);
  }
}

void init_pawn_moves(void) {
  for(int side = 0; side < 2; side++) {
    for(int i = 0; i < 64; i++) {
      pawn_moves[side][i] = pawn_motion_mask(i, side);
    }
  }
}

void init_pawn_attacks(void) {
  for(int side = 0; side < 2; side++) {
    for(int i = 0; i < 64; i++) {
      pawn_attacks[side][i] = pawn_attack_mask(i, side);
    }
  }
}

void init_all(void) {
  init_rays();
  init_king_moves();
  init_knight_moves();
  init_pawn_moves();
  init_pawn_attacks();
  initialized = 1;
}

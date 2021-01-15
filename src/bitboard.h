#define set_bit(square, bitboard) (bitboard |= (1ULL << square))

#define get_bit(square, bitboard) ((bitboard & (1ULL << square)) ? 1 : 0)

#define pop_bit(square, bitboard) ((bitboard & (1ULL << square)) ? 1 : 0)

void print_bitboard(U64 bb);

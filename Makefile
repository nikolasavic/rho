all:
	gcc  -o build/rho src/rho.c src/bitboard.c src/masks.c

test_defs:
	mkdir -p build/test
	gcc test/test_defs.c src/defs.c unity/unity.c -o build/test/test_defs
	./build/test/test_defs

test_bitboard:
	mkdir -p build/test
	gcc test/test_bitboard.c src/bitboard.c unity/unity.c -o build/test/test_bitboard
	./build/test/test_bitboard

test_masks:
	mkdir -p build/test
	gcc test/test_masks.c src/bitboard.c src/masks.c unity/unity.c -o build/test/test_masks
	./build/test/test_masks

test_board:
	mkdir -p build/test
	gcc test/test_board.c src/board.c unity/unity.c -o build/test/test_board
	./build/test/test_board

test_parser:
	mkdir -p build/test
	gcc test/test_parser.c src/parser.c unity/unity.c -o build/test/test_parser
	./build/test/test_parser

clean:
	rm -rf build/*

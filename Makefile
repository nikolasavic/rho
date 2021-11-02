all:
	gcc  -o build/rho src/rho.c src/board.c src/bitboard.c src/masks.c src/init.c

test_bitboard:
	mkdir -p build/test
	gcc test/test_bitboard.c src/bitboard.c src/board.c unity/unity.c -o build/test/test_bitboard
	./build/test/test_bitboard

test_masks:
	mkdir -p build/test
	gcc test/test_masks.c src/bitboard.c src/board.c src/masks.c unity/unity.c -o build/test/test_masks
	./build/test/test_masks

test_board:
	mkdir -p build/test
	gcc test/test_board.c  src/board.c unity/unity.c -o build/test/test_board
	./build/test/test_board

test_parser:
	mkdir -p build/test
	gcc test/test_parser.c src/board.c src/parser.c unity/unity.c -o build/test/test_parser
	./build/test/test_parser

test_move:
	mkdir -p build/test
	gcc test/test_move.c src/move.c src/board.c unity/unity.c -o build/test/test_move
	./build/test/test_move

test_init:
	mkdir -p build/test
	gcc test/test_init.c src/init.c src/bitboard.c src/masks.c unity/unity.c -o build/test/test_move
	./build/test/test_move

clean:
	rm -rf build/*

all:
	gcc -o build/rho src/bitboard.c src/board.c src/init.c src/masks.c src/parser.c src/rho.c 

test_bitboard:
	mkdir -p build/test
	gcc src/bitboard.c src/board.c test/test_bitboard.c unity/unity.c -o build/test/test_bitboard
	./build/test/test_bitboard

test_masks:
	mkdir -p build/test
	gcc src/bitboard.c src/board.c src/init.c src/masks.c test/test_masks.c unity/unity.c -o build/test/test_masks
	./build/test/test_masks

test_board:
	mkdir -p build/test
	gcc src/board.c src/parser.c test/test_board.c unity/unity.c -o build/test/test_board
	./build/test/test_board

test_parser:
	mkdir -p build/test
	gcc src/board.c src/parser.c test/test_parser.c unity/unity.c -o build/test/test_parser
	./build/test/test_parser

test_move:
	mkdir -p build/test
	gcc src/board.c src/bitboard.c src/move.c test/test_move.c unity/unity.c -o build/test/test_move
	./build/test/test_move

test_init:
	mkdir -p build/test
	gcc src/bitboard.c src/init.c src/masks.c test/test_init.c unity/unity.c -o build/test/test_move
	./build/test/test_move

test_move_list:
	mkdir -p build/test
	gcc src/bitboard.c src/board.c src/init.c src/masks.c src/move.c src/move_list.c src/parser.c test/test_move_list.c unity/unity.c -o build/test/test_move_list
	./build/test/test_move_list

test_move_gen:
	mkdir -p build/test
	gcc src/bitboard.c src/board.c src/init.c src/masks.c src/move.c src/move_gen.c src/move_list.c src/parser.c test/helpers.c test/test_move_gen.c unity/unity.c -o build/test/test_move_gen
	./build/test/test_move_gen

test_board_analytics:
	mkdir -p build/test
	gcc src/bitboard.c src/board.c src/board_analytics.c src/init.c src/masks.c src/parser.c test/test_board_analytics.c unity/unity.c -o build/test/test_board_analytics
	./build/test/test_board_analytics

clean:
	rm -rf build/*

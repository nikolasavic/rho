all:
	gcc  -o build/rho src/rho.c src/bitboard.c

test_init:
	mkdir -p build/test
	gcc test/test_init.c src/init.c unity/unity.c -o build/test/test_init
	./build/test/test_init

test_bitboard:
	mkdir -p build/test
	gcc test/test_bitboard.c src/bitboard.c unity/unity.c -o build/test/test_bitboard
	./build/test/test_bitboard

test_masks:
	mkdir -p build/test
	gcc test/test_masks.c src/bitboard.c src/masks.c unity/unity.c -o build/test/test_masks
	./build/test/test_masks

clean:
	rm -rf build/*

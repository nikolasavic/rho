all:
	gcc  -o build/rho src/rho.c src/bitboard.c

test_bitboard:
	mkdir -p build/test
	gcc test/test_bitboard.c src/bitboard.c unity/unity.c -o build/test/test_bitboard
	./build/test/test_bitboard

clean:
	rm -rf build/*

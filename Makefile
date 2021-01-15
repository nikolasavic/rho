all:
	gcc  -o build/rho src/rho.c src/bitboard.c

clean:
	rm -f build/*

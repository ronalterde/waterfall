RAW_FILE="out.bin"
BLOCK_SIZE=1001

.PHONY: run_waterfall
run_waterfall: waterfall commands
	-rm ${RAW_FILE}
	gdb --batch -x commands $<
	./plot.py ${RAW_FILE} ${BLOCK_SIZE}

.PHONY: all
all: test waterfall

.PHONY: clean
clean:
	rm -f waterfall
	
waterfall: waterfall.c
	$(CC) -std=c11 -g -DBLOCK_SIZE=${BLOCK_SIZE} $< -o $@

trigger:
	gcc main.c pbPlots.c supportLib.c -lm -o output && ./output
clean:
	rm output
	rm final.png
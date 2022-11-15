trigger:
	gcc main.c LIB/pbPlots.c LIB/supportLib.c -lm -o OUTPUT/output && ./OUTPUT/output
clean:
	rm output
	rm final.png

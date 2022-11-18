trigger:
	gcc main.c LIB/pbPlots.c LIB/supportLib.c -lm -o OUTPUT/output && ./OUTPUT/output
clean:
	rm OUTPUT/output
	rm OUTPUT/output.txt
	rm OUTPUT/final.png

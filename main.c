#include "pbPlots.h"
#include "supportLib.h"
#include <math.h>
#include <stdio.h>


int main(){
	FILE* fp;
	fp = fopen("output.txt", "w"); // here comes the file you want to write to
	fprintf(fp, " ");
	fclose(fp);
	fp = fopen("output.txt", "a");
	

	//
	// FUNCTION CONFIGURATION
	//
	
	int list_index = 0;

    	double x[9999];	// will contain all the x values
    	double y[9999];	// will contain all the y values

   	double range_final = 10; // final x value               
	double xv = 0; // initial x value:
	double resolution = 0.01; // resolution (smaller, more precise), default 0.01               

    	for(; xv < range_final; xv += resolution)	// function calculation
	{
		x[list_index] = xv; // Getting the x value for a certain index
		y[list_index] = pow(xv, 2); // here comes your function (same index as x's)
	
		// writing to the text file

		fprintf(fp, "x: %lf | y: %lf\n", x[list_index], y[list_index]);    	
		
		list_index++; // updating index value
    	}

	fprintf(fp, "\n<%d> results \n", list_index); // showing up how many results it got
	fclose(fp); // close the text file

	//
	// END OF FUNCTION CONFIGURATION
	//


	//
	// IMAGE PROCESSING:
	//

	// pbPlots:

    	// Line:
    	ScatterPlotSeries *line = GetDefaultScatterPlotSeriesSettings();

    	// Line details and settings:
    	line->xs = x;
	line->ys = y;
    	line->xsLength = list_index;
    	line->ysLength = list_index;
    	line->linearInterpolation = true;

    	// Background:
    	ScatterPlotSettings *background = GetDefaultScatterPlotSettings();

    	// Background settings and details
    	background->autoPadding = true;
    	background->yAxisAuto = true;
    	background->autoBoundaries = true;
    	background->showGrid =  true;
    	background->xAxisBottom = true;

	// SIZE IN PIXELS
    	background->height = 900;
    	background->width = 1600;	
    	// SIZE IN PIXELS

	background->title = L"MarcoGebra";
    	background->titleLength = wcslen(background->title);
	
	// Relacting the Line with the Background
	ScatterPlotSeries *s [] = {line};
	background->scatterPlotSeries = s;
	background->scatterPlotSeriesLength = 1;

    
    	// Exporting:
    
    	// Creating a image in the ram
    	RGBABitmapImageReference *ram_image = CreateRGBABitmapImageReference();
    
    	// Uploading all previous settings to the ram's image
    	DrawScatterPlotFromSettings(ram_image, background, ((void *)0));
    	size_t length;
		double *ram_png = ConvertToPNG(&length, ram_image->image);
		WriteToFile(ram_png, length, "final.png");
    	DeleteImage(ram_image->image);

	//
	// END OF IMAGE PROCESSING
	//

	return 0;
}

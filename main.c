#include "pbPlots.h"
#include "supportLib.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){
	FILE* fp;
	fp = fopen("jorge.txt", "w");
	fprintf(fp, " ");
	fclose(fp);
	fp = fopen("jorge.txt", "a");
	
	// setting X and Y values.
    double x[9999];
    double y[9999];

    // looping to function
   	double range_final = 40;                  // FINAL
	double variable_initial_index = -40;    // INITIAL
	double resolution = 0.01;                // ACCURACY (less, more accurate)
    	int list_index = 0;


    double xf;
    double final;
    
    // f(x)=b*a^(x+c) + d 


    double modulum(double numba){
        if(numba < 0){
            numba = numba * -1;
        }
        return numba;
    }

    //	function calculation
    fprintf(fp, "MarcoGebra | ACCURACY: %lf\n\n ", resolution);
    for(; variable_initial_index < range_final; variable_initial_index = variable_initial_index + resolution){
	x[list_index] = variable_initial_index;
	y[list_index] = pow(variable_initial_index, 2);
	fprintf(fp, "x: %lf | y: %lf\n", x[list_index], y[list_index]);
    	list_index++;
    }

    fprintf(fp, "\n<%d> results \n", list_index);
	
	fclose(fp);
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
    background->height = 800;
    background->width = 1200;
    background->title = L"MarcoGebra >> Geogebra.";
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

    return 0;
}

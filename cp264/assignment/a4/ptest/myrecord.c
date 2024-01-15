#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mysort.h"
#include "myrecord.h"
#include "mysort.c"
#define MAX_LINE 100


char letter_grade(float s){
    
   char g[] = {'S', 'A', 'B', 'C', 'D', 'F'};
    float b[] = {100, 90, 80, 70, 60, 50, 0};
    int l =0, r = sizeof(b)/sizeof(float)-1;
    
    int found = 0;
    while(!found){
        int center = (r+l)/2;
        if(s < b[center]){
            l = center;
        } else {
            r = center;
        }

        if(l == r-1){
            found = 1;
        }
    }
    if (r == l) return g[l-1];

    else return g[l];
}
   


STATS process_data(RECORD *dataset, int n) { 
    STATS results;
	if (n == 0) {
		results.mean = 0.0;
		results.count = 0;
		results.median = 0.0;
		results.stddev = 0.0;
	} else {
		float result = 0.0;
		float gradeArray[n], dvArray[n];
		int x;
		int np = (n % 2);
		for (x = 0; x < n; x++) {
			result = result + dataset[x].score;
			gradeArray[x] = dataset[x].score;
		}
		results.mean = (result / n);
		results.count = n;
		quick_sort(gradeArray, 0, (n - 1));
		if (np == 1) {
			int midIndex = ((n - 1) / 2);
			results.median = gradeArray[midIndex];
		} else if (n > 2) {
			float temp = gradeArray[(n / 2)] + gradeArray[(n / 2) - 1];
			results.median = temp / 2;
		} else if (n == 2) {
			results.median = (gradeArray[0] + gradeArray[1]) / 2;
		}
		result = 0.0;
		for (x = 0; x < n; x++) {
			dvArray[x] = gradeArray[x] - results.mean;
			dvArray[x] = (dvArray[x] * dvArray[x]);
			result = result + dvArray[x];
		}
		result = (result / n);
		results.stddev = sqrt(result);
	}
	return results;
}  




int import_data(char *infilename, RECORD *records) {
	FILE *fp = fopen(infilename, "r");
	char delimiter[] = ",\n\r";
	char line[100];
	int y = 0;
	char *token = NULL;
	
    while (fgets(line, sizeof(line), fp) != NULL) {
		token = (char*) strtok(line, delimiter);
		strcpy(records[y].name, token);
		token = (char*) strtok(NULL, delimiter);
		records[y].score = atof(token);
		y++;
	}
	return y;
}


int report_data(char *outfilename, RECORD *records, STATS stats) {
    FILE *fp;
    int i;

    // Open the output file
    fp = fopen(outfilename, "w");
    if (fp == NULL) {
        return 1;
    }

    // Write the stats information
    fprintf(fp, "stats:value\n");
    fprintf(fp, "count: %.2f\n", stats.count);
    fprintf(fp, "mean: %.2f\n", stats.mean);
    fprintf(fp, "stddev: %.2f\n", stats.stddev);
    fprintf(fp, "median: %.2f\n", stats.median);

    // Write the record data
    for (i = 0; i < stats.count; i++) {
        fprintf(fp, "Record %d: %d\n", i + 1, records[i].score);
    }

    // Close the output file
    fclose(fp);

    return 0;
}
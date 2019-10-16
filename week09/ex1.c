#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    FILE* file = fopen("Lab 09 input.txt", "r");
    char* ptr;
    int PAGE_FRAME_NUM = strtol(argv[1], &ptr, 10);
    int page_frames[PAGE_FRAME_NUM];
    int page_counter[PAGE_FRAME_NUM];
    int i = 0;
    int hits = 0;
    int miss = 0;

    fscanf(file, "%d", &i);    
    for (int k=0; k<PAGE_FRAME_NUM; ++k) {
	int found = 0;
	for (int j=0; j<k; ++j) {
	    if (page_frames[j] == i) {
		page_counter[j] = (page_counter[j]>>1) + 128;
		found = 1;
		break;
	    }
	}

	if (found) {
	    hits += 1;	
	} else {
	    page_frames[k] = i;
	    page_counter[k] = 128;
	    miss += 1;
	}
	fscanf(file, "%d", &i);
    } 

    while (!feof (file)) {  
	int found = 0;
	for (int j=0; j<PAGE_FRAME_NUM; ++j) {
	    if (page_frames[j] == i) {
		page_counter[j] = (page_counter[j]>>1) + 128;
		found = 1;
		break;
	    }
	}

	if (found) {
	    hits += 1;	
	} else {
	    int min = 255;
	    int min_index = 0;

	    for (int j=0; j<PAGE_FRAME_NUM; ++j) {
	   	if (page_frames[j] < min) {
		    min = page_frames[j];
	    	    min_index = j;	    
		} 
	    }

	    page_frames[min_index] = i;
	    page_counter[min_index] = 128;
	    miss += 1;
	}

        fscanf(file, "%d", &i);      
    }

    float ratio = (float)hits/miss;
    printf("\n\nHit/Miss ratio: %.6f", ratio); 
    fclose (file);        
    return 0;
}

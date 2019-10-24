#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
    struct dirent* dp;
    DIR* dirp;
    long inonums[10];

    dirp = opendir("./tmp");
    if (dirp==NULL) {
	printf("No such directory");
	return 1;
    }

    int i = 0;
    while ((dp = readdir(dirp)) != NULL) {
	int found = 0;
	for (int j=0; j < 10; ++j) {
	    if (dp->d_ino == inonums[j]) {
	   	break; 
	    } else {
		found = 1;
		inonums[i] = dp->d_ino;
	    }
	}

	if (found) {
	    i++;   	
	}
    }

    for (int j = 0; j < i; ++j) {
    	dirp = opendir("./tmp");
	printf("\nFILES WITH INODE NUMBER [%ld]: \n", inonums[j]);
	while ((dp = readdir(dirp)) != NULL) {
	    if (dp->d_ino == inonums[j]) {
		printf("File name: %s [%ld]\n", dp->d_name, dp->d_ino);
	    }
	}
    }

    (void)closedir(dirp);
    return 0;
}

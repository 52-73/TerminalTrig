#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>


const char *brightness = "`.-':_,^=;><+!rc*/z?sLTv)J7(|Fi{C}fI31tlu[neoZ5Yxjya]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@";

int factorial(int x) {
    if (x<0) {
        return -1;
    }
    else if (x==0) {
        return 1;
    }
    return x * factorial(x-1);
}

double f(int x) {
    return (30 * sin(0.1 * x));
}


// print trig function in horizontal space
void print_fx(int width, int height) {
    
    int brightness_index;
    double brightx = (double)width;
    double brighty = (double)height;

    for (int y=height; y>=height * -1; y--) {
        for (int x=width * -1; x<=width; x++) {

            brightness_index = (int)( ((((x * -1)+brightx) / (brightx * 2) * (y+brighty) / (brighty * 2)) 
            / 1.5) * strlen(brightness));

            if (y <= f(x)) {
                printf("%c", brightness[brightness_index]);
            }
            // else if (y > 10 * cos(0.1 * x) && y < (10 * cos(0.1 * x)) + 1) {
            //     printf(" ");
            // } // -> print the outline of the function
            else {
                printf("%c", brightness[(strlen(brightness)-1-brightness_index)]);
            }
        }
        printf("\n");
    }
}


// print trig function in vertical space
void print_fy(int width, int height) {
    
    int brightness_index;
    double brightx = (double)width;
    double brighty = (double)height;
    int variance = 4;

    for (int y=height; y>=height * -1; y--) {
        for (int x=width * -1; x<=width; x++) {

            brightness_index = (int)( ((((x * -1)+brightx) / (brightx * 2) * (y+brighty) / (brighty * 2)) 
            / 1.5) * strlen(brightness));

            int r = rand() % variance;

            if (x <= 0.01 * y * f(y)) {
                printf("%c", brightness[(brightness_index + variance) - r]);
            }
            // else if (x > 0.01 * y * f(y) && x < ( 0.01 * y * f(y)) + 1) {
            //     printf(" ");
            // } // -> print the outline of the function
            else {
                printf("%c", brightness[(strlen(brightness)-1-brightness_index) - r]);
            }
        }
        usleep(30000);
        printf("\n");
    }
}

int main(void) {
    // print_fx(70, 20); // optimal ~70x20
    int x;
    int y;

    printf("Width: ");
    scanf("%d", &x);
    printf("Height: ");
    scanf("%d", &y);

    print_fy(x, y);

    return 0;
}
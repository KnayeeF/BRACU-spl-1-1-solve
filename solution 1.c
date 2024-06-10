#include <stdio.h>
#include <string.h>
#include <math.h>

double dist_calc(double x1, double x0, double y1, double y0, double z1, double z0)
{
    double res = (pow((x1-x0), 2) + pow((y1 - y0), 2) + pow((z1 - z0), 2));
    return res;
}

int min_val(double array[]){
    double maxVal = 100;
    int index = -1;
    for(int i=0; i<5; i++){
        if(array[i] < maxVal && array[i] != 0){
            maxVal = array[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    char planet[6][10] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter"};
    char inp[10];

    double x[7] = {0.39, 0.72, 1.00, 1.52, -5.20};
    double y[7] = {0.24, 0.00, 0.00, 0.99, 2.86};
    double z[7] = {-0.10, 0.44, -0.02, 0.21, 0.42};

    printf("Enter a planet name: ");
    gets(inp);
    for(int i=0; i<5; i++){
        int cmp = strcmp(planet[i], inp);

        if(cmp == 0){
            double distances[6];
            for(int j=0; j<5; j++){
                double x0 = x[i];
                double y0 = y[i];
                double z0 = z[i];
                double x1 = x[j];
                double y1 = y[j];
                double z1 = z[j];

                double result = dist_calc(x1, x0, y1, y0, z1, z0);
                distances[j] = result;
            }
            int min_dist = min_val(distances);

            printf("Closest Planet: %s\n", planet[min_dist]);
            printf("Distance: %lf", distances[min_dist]);
            break;
        }

        else if(i == 4){
            printf("Invalid value");
        }
    }
    return 0;
}

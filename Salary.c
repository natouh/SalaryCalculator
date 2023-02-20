// Nathan Hababou
//This program calculates the salary given the following parameters on the command line  to compute.
// command line: ./salary -h -b hourlyrate

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // intialize integers used to calculate the salary of the period

    int i;
    double hourly; 
    double hours;
    double  bonus; 
    double salary;
    int percent = 0;

    // Using Getopt to parse the command line 
    //the switch sets each case to a parameter on the command line
    while ((i = getopt(argc, argv, "ph:b:"))!= -1) {
        switch (i) {
        case 'h':
            hours = atof(optarg);
            break;
        case 'b':
        
            bonus = atof(optarg);
            break;
        case 'p':
            percent = 1 + atof(argv[i++]) / 100;
            break;
        default: 
            fprintf(stderr, "Usage: %.s [-p] -h hours [-b bonus] hourlyrate \n", argv[0]);
       
        
        
        }
    }
    // if statement that runs until the input hours are greater than 80 
    if ( hours <= 80) {
    //optind is used to represent the index value of the following argument 
    // Check that required options were provided
    while (argc <= optind) {
        fprintf(stderr, "Usage: %.s [-p] -h hours [-b bonus] hourlyrate \n", argv[0]);
        
    }
 hourly = atof(argv[optind]);

    // Calculate salary
    // increase the salary by 10%
    salary = hourly * hours;
    while (percent) {
        salary = salary * 1.10; 
    }
    //for( int j =0; bonus <= bonus  * 0.50; j++) {
    salary = bonus + salary; 
   //}
    }
    else {
        printf("Too many hours inputed\n");
        exit(0);
    }
    printf("The Salary for this period is  %.2f \n", salary);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int die_size, num_count;
int numbers[10000];
int roll_count = 10;
double mean, variance, deviation, rolling_sum, variance_sum, standard_deviation,
    standard_error;

//build the protypes
void roll_the_dice();
void calculate_the_mean();
void calcluate_the_variance();
void calculate_the_standard_deviation();

int main()
{
    printf_s("Let's roll some dice! Please enter how many sides of the die you want to roll.\n");

    //ask to enter a number between 2 and 100, if they enter a number outside of that range, ask again.
    do {
        printf_s("Please enter a number between 2 and 100\n");
        scanf_s("%i", &die_size);
        while (getchar() != '\n');
    } while (die_size < 2 || die_size > 100);
    printf_s("You entered %i\n", die_size);
    roll_the_dice();
    printf("\e[1;1H\e[2J");
    calculate_the_mean();
    calcluate_the_variance();
    calculate_the_standard_deviation();
}

void roll_the_dice() {

    srand(time(0));  //this seeds the random value
    rolling_sum = 0;
    for (int i = 0; i < 10000; i++) {
        numbers[i] = rand() % die_size + 1;
        printf("%i\n", numbers[i]);
        rolling_sum += numbers[i];
    }
    printf_s("The rolling sum is %lf\n", rolling_sum);
}

void calculate_the_mean() {
    mean = (rolling_sum / 10000);
    printf_s("The mean is %lf\n", mean);
}

void calcluate_the_variance() {
    variance_sum = 0;
    for (int i = 0;i < 10000; i++) {
        double var = (numbers[i] - mean);
        variance_sum += ((var * var));
    }
    variance = (variance_sum / 9999);
    printf_s("The variance is %lf\n", variance);
}

void calculate_the_standard_deviation() {
    standard_deviation = sqrt(variance);
    standard_error = standard_deviation / sqrt(10000);

    printf_s("The standard deviation is %lf\n", standard_deviation);
    printf_s("The standard error is %lf\n", standard_error);
}

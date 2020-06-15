#include "mbed.h"

#include "bbcar.h"


Ticker servo_ticker;

PwmOut pin8(D8), pin9(D9);


BBCar car(pin8, pin9, servo_ticker);


int main() {

    // please contruct you own calibration table with each servo

    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};

    double speed_table0[] = {-16.986, -16.747, -15.551, -12.281, -6.141, 0.000, 5.184, 11.245, 14.993, 16.428, 16.987};  //D8.left

    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};

    double speed_table1[] = {-16.348, -15.950, -14.913, -12.122, -6.141, 0.000, 4.865, 10.846, 14.514, 15.870, 16.588};  //D9.right


    // first and fourth argument : length of table

    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);


    while (1) {

        car.goStraightCalib(5);

        wait(5);

        car.stop();

        wait(5);

    }

}
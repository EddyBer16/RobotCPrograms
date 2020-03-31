/*
    CODED BY ANGEL BERLANGA
    EMAIL: angel.tigre@hotmail.com
    GITHUB: https://github.com/EddyBer16
    REPOSITORY OF THESE PRACTICES: https://github.com/EddyBer16/RobotCPrograms
*/

#pragma config(Sensor, S1,     Sonar,          sensorEV3_Ultrasonic)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void checkMotorletterAndAssignPotence(char motorletter, int potence) {
    switch (motorletter)
    {
    case 'A':
        motor[motorA] = potence;
        break;
    
    case 'B':
        motor[motorB] = potence;
        break;

    case 'C':
        motor[motorC] = potence;
        break;

    default:
        break;
    }
}

/*
    Function for adjust the potence of a motor
    Passing as arguments the letter of the motor and the potence for that motor
*/
void adjustMotorPotence(char motorletter, int potence) {
    checkMotorletterAndAssignPotence(motorletter, potence);
}

void returnMotorToZero(char motorletter) {
    checkMotorletterAndAssignPotence(motorletter, 0);
}

/*
    Function for do a stop in the code using seconds
    This also supports decimal values
*/
void waitSeconds(float n) {
    wait1Msec(n * 1000);
}

void moveToFront() {
    adjustMotorPotence('A', 100);
    adjustMotorPotence('C', 100);
}

void moveToBack() {
    adjustMotorPotence('A', -100);
    adjustMotorPotence('C', -100);
}

void moveUntil10Cm() {
    while(SensorValue[S1] >= 10) {
        moveToFront();
    }
    returnMotorToZero('A');
    returnMotorToZero('C');
}

void doABeepAndReturn() {
    playSound(soundBeepBeep);
    waitSeconds(0.35);
    moveToBack();
    waitSeconds(1); // Here could be (1) and (1.0), both work well
    returnMotorToZero('A');
    returnMotorToZero('C');
}

task main() {
    moveUntil10Cm();
    doABeepAndReturn();
}
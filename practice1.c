/*
    CODED BY ANGEL BERLANGA
    EMAIL: angel.tigre@hotmail.com
    GITHUB: https://github.com/EddyBer16
    REPOSITORY OF THESE PRACTICES: https://github.com/EddyBer16/RobotCPrograms
*/

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

void moveFrontTwoSeconds() {
    adjustMotorPotence('A', 100);
    adjustMotorPotence('C', 100);
    waitSeconds(2); // Here could be (2) or (2.0), both work well
    returnMotorToZero('A');
    returnMotorToZero('C');
}

task main() {
    moveFrontTwoSeconds();
}
//create object of AppMotor class from header file
extern DeviceDriverSet_Motor AppMotor;

//define methods of header file
//1)
void DeviceDriverSet_Motor::DeviceDriverSet_Motor_Init(void)
{
    pinMode(PIN_Motor_STBY, OUTPUT);
    pinMode(PIN_Motor_PWMA, OUTPUT);
    pinMode(PIN_Motor_PWMB, OUTPUT);
    pinMode(PIN_Motor_AIN_1, OUTPUT);
    pinMode(PIN_Motor_BIN_1, OUTPUT);
}

//2)
void DeviceDriverSet_Motor::DeviceDriverSet_Motor_control(
    boolean directionA, uint8_t speedA,
    boolean directionB, uint8_t speedB,
    boolean controlED)
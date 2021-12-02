#include "DeviceDriverSet_xxx0.cpp"

extern DeviceDriverSet_Motor AppMotor;

static void ApplicationFunctionSet_SmartRobotCarMotionControl(
    SmartRobotCarMotionControl direction, 
    uint8_t is_speed)

/*Motion direction control sequence*/
enum SmartRobotCarMotionControl
{
    Forward,        //1
    Backward,       //2
    Left,           //3
    Right,          //4
    LeftForward,    //5
    LeftBackward,   //6
    RightForward,   //7
    RightBackward,  //8
    stop_it         //9
};


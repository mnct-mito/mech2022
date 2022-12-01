#include <Zumo32U4.h>

#define MaxSpeed 400

Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
Zumo32U4Motors motors;

void setup()
{
    lcd.clear();
    lcd.print("Press A");
}

void loop()
{
    if (buttonA.getSingleDebouncedPress() == true)
    {
        // ブロック内の処理を4回繰り返す
        for(int loop=0; loop<4; loop++)
        {
            // 加速
            for(int speed = 0; speed < MaxSpeed; speed++)
            {
                motors.setSpeeds(speed, speed);
                delay(5);
            }
            // 減速
            for(int speed = MaxSpeed; speed >= 0; speed--)
            {
                motors.setSpeeds(speed, speed);
                delay(5);
            }
            // 右旋回　加速
            for(int speed = 0; speed < MaxSpeed; speed++)
            {
                motors.setSpeeds(speed, -speed);
                delay(2);
            }
            // 右旋回  減速
            for(int speed = MaxSpeed; speed >= 0; speed--)
            {
                motors.setSpeeds(speed, -speed);
                delay(2);
            }
        }
    }
}
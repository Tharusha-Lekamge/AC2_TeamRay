class Servo
{
private:
    int nextDir; // 1 for clockwise, 0 for anticlockwise
    int pin;

public:
    Servo(int pinNo);
    void init();
    bool rotate(int angle);
};
class Driver
{
private:
    int m1Pin;
    int m2Pin;
    int nextDir;
    int nextAng;
    int nextDist;

public:
    Driver(int m1Pin, int m2Pin);
    void init();
    void move();
    void updateNextMove(int nextDir,
                        int nextAng,
                        int nextDist);
};
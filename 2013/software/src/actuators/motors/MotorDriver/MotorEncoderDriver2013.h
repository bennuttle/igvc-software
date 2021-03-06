#ifndef MOTORENCODERDRIVER2013_H
#define MOTORENCODERDRIVER2013_H
#include <serial/ASIOSerialPort.h>
#include <actuators/motors/MotorDriver/MotorDriver.hpp>
#include <events/Event.hpp>
#include <boost/thread.hpp>

struct EncPose
{
    double x;
    double y;
    double theta;
};

class MotorEncoderDriver2013 : public MotorDriver
{
    public:
        MotorEncoderDriver2013();
        virtual ~MotorEncoderDriver2013();

        void setVelocities(double left, double right, int millis = 0);
        void setLeftVelocity(double vel, int millis = 0);
        void setRightVelocity(double vel, int millis = 0);
        double getLeftVelocity();
        double getRightVelocity();
        void stop();

        Event<EncPose> onNewPosition;

    protected:
    private:
        ASIOSerialPort _arduino;
        double _leftVel;
        double _rightVel;
        int _duration;
        double _maxVel;
        void writeVelocities();
        boost::thread _encThread;
        boost::mutex _portLock;
        void encThreadRun();
        EncPose _pose;
        bool _running;
};

#endif // MOTORENCODERDRIVER2013_H

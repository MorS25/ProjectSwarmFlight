#ifndef DRONE_H
#define DRONE_H

#include <QObject>
#include <QVector>
#include <QVector3D>

class Drone : public QObject
{
    Q_OBJECT
public:
    //-----------------------------------------------------------------------------------------------
    //Constructor and destructor
    explicit Drone(QObject *parent = 0);
    Drone(int aID, QVector3D aPos, int aSwarmSize);
    //virtual ~Drone();

protected:
    // empty

private:
    //-----------------------------------------------------------------------------------------------
    // Private Attributes

    //Basic Data of Drone
    int msID;
    int mQueen;          //if drone is leader, mQueen=1
    QVector3D mPos;      //position vector (latitude, longitude, elevation)
    QVector3D mDirect;   //direction of movement of the drone as a normed vector
    double mSpeed;       //speed of movement of the drone
    QVector3D mMove;     //mMove = mSpeed x mDirect


    //Grunddaten des Schwarms
    int mSwarmSize;                  //swarm member count
    int mLeaderID;                   //ID of the leader ("queen")
    QVector<QVector3D> mMatesPos;    //positions of all other members
    QVector3D mLPos;                 //position of the leader
    QVector3D mTPos;                 //position of the target, the swarm is headed at

    //-----------------------------------------------------------------------------------------------
    // Methods
    //Layers of Behavior
    bool swarming();            //basic behavior; avoiding collision or separation of swarm
    bool remoteControl();       //controlled behavior; imposed by queen
    bool autonomousControl();   //autonomous behavior; seeking target without spec. orders

    //movement of the drone
    void iMove();               //new position = old position + mMove

signals:
    //updating other swarm members on current position
    void mSignalNewPos(QVector3D signalPos, int signalID);


public slots:
    //getting new position of other swarm member
    void matePosInput(QVector3D aMatePos, int aMateID);

    //getting changes of the swarm data e.g. leader changes
    void changeSwarmDate(int aSwarmSize, int aLeaderID);

};

#endif // DRONE_H

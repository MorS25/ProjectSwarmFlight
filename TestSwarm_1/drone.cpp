#include "drone.h"

Drone::Drone(QObject *parent) :
    QObject(parent)
{
}

Drone::Drone(int aID, QVector3D aPos, int aSwarmSize)
{
    this->msID = aID;
    this->mPos = aPos;
    this->mSwarmSize = aSwarmSize;
    this->mMatesPos.resize(mSwarmSize);
}

void Drone::changeSwarmDate(int aSwarmSize, int aLeaderID)
{
    this->mSwarmSize = aSwarmSize;
    this->mLeaderID = aLeaderID;
}

void Drone::matePosInput(QVector3D aMatePos, int aMateID)
{
    //position of other drones is converted into relative position
    this->mMatesPos[aMateID] = aMatePos - this->mPos;
}

void Drone::iMove()
{
    //test correct swarming (collision/separation)
    if(swarming())
    {
        //check if the queen has given any orders
        if(remoteControl())
        {
            //if swarming is correct and no orders are given, seek target
            autonomousControl();
        }
    }

    this->mPos = this->mPos + this->mMove;
    emit mSignalNewPos(mPos,msID);
}


bool Drone::swarming()
{
    //collision test
        //first compare own elevation to others

        //if drones have the same elevation, check out latitude and longitude

    return 1;
}

bool Drone::remoteControl()
{
    //remote control by queen will be added in a further version
    return 1;
}

bool Drone::autonomousControl()
{
    //direction vector is parallel to line between leader and target
    this->mDirect = mMatesPos[this->mLeaderID] - this->mTPos;
    return 1;
}

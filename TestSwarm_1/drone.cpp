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
    int i=0;
    int swarmingStatus=0;
    float safetyDistance=0.7;
    float currentBadDistance=1.0;

    //collision test
    for(i=0;i<this->mSwarmSize;i++)
    {

        //when the distance < safetyDistance, the drones could collide
        //with rel. positions, the length of the position = distance to object
        if(this->mMatesPos[i].length()<safetyDistance)
        {
            if(this->mMatesPos[i].length()<currentBadDistance)
            {
                //change current smallest distance
                currentBadDistance = this->mMatesPos[i].length();

                this->mDirect = this->mMatesPos[i].normalized() * -1;
            }

            swarmingStatus = 0;
        }
        else
        {
            swarmingStatus = 1;
        }

    }
    return swarmingStatus;
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

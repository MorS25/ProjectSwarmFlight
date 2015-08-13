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

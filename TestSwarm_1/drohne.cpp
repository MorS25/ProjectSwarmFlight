#include "drohne.h"

drohne::drohne(QObject *parent) :
    QObject(parent)
{
}

drohne::drohne(int newID, QVector3D newPos, int newSwarmSize)
{
    this->ID = newID;
    this->myPos = newPos;
    this->matesPos.resize(newSwarmSize);
}

QVector3D drohne::myMove()
{
    QVector3D theMove;
    theMove = this->myDirect * this->mySpeed;
    return theMove;
}

void drohne::matePosInput(QVector3D matePos, int mateID)
{
    this->matesPos[mateID] = matePos - this->myPos;
}

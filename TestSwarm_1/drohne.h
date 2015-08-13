#ifndef DROHNE_H
#define DROHNE_H

#include <QObject>
#include <QVector>
#include <QVector3D>

class drohne : public QObject
{
    Q_OBJECT
public:
    explicit drohne(QObject *parent = 0);
    drohne(int ID, QVector3D newPos, int newSwarmSize);

signals:
    void myNewPos(QVector3D myPos, int ID);    //über dieses Signal werden die eigene Position und ID an andere Drohnen übergeben

public slots:
    void matePosInput(QVector3D matePos, int mateID);  //über diesen Slot geben übergeben andere Drohnen ihre Position an diese Drohne

private:
    //Grunddaten der Drohne
    int ID;
    QVector3D myPos;      //meine Position
    QVector3D myDirect;   //meine Richtung (normierter Vektor)
    double mySpeed;       //meine Geschwindigkeit
    QVector3D myMove();   //Bewegungsvektor der Drohne ergibt sich aus der Multiplikation von myDirect mit mySpeed


    //Grunddaten des Schwarms
    int swarmSize;              //Anzahl der Mitglieder im Schwarm
    QVector<QVector3D> matesPos;   //Positionen der anderen Mitglieder (relativ)
    QVector3D LPos;             //Leader Position
    QVector3D TPos;             //Position des Ziels (Target Position)

    //Bewegung der Drohne
    void iMove();               //Addiert die aktuelle Bewegung zur Position


};

#endif // DROHNE_H

#ifndef MARSGAME_H
#define MARSGAME_H
#include <QString>

class marsGame
{
public:
    marsGame();
    ~marsGame();
    QString getPhase();
    QString getInstruction();
    int GetTurn();
    void pressedNextInstruction(bool &isActionPhase,int &progressValue);



private:
    int currentPhase = 0;
    int instructionIndex = 0;
    int turn = 1;
    static const int phasesOfGame = 4;

    QString phases[4];
    QString phasesInstructions[4][2];

    QString firstPhaseInstructions[2];
    QString secondPhaseInstructions[2];
    QString fourthPhaseInstructions[2];
};

#endif // MARSGAME_H

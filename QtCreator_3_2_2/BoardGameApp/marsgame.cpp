#include "marsgame.h"

marsGame::marsGame()
{
    phases[0] = "Faza kolejnosci";
    phases[1] = "Faza badan";
    phases[2] = "Faza akcji";
    phases[3] = "Faza produkcji";

    phasesInstructions[0][0] = "Przekaz znacznik pierwszego gracza";
    phasesInstructions[0][1] = "Przesun znacznik pokolenia";

    phasesInstructions[1][0] = "Dobierz badania i wybierz ktore chcesz zachowac";
    phasesInstructions[1][1] = "Zaplac za wybrane badania";

    phasesInstructions[2][0] = "Wybierz akcje";
    phasesInstructions[2][1] = "Wybierz akcje";

    phasesInstructions[3][0] = "Przemien energie w cieplo i dobierz zasoby";
    phasesInstructions[3][1] = "Usun znaczniki uzytych kart";
}
void marsGame::pressedNextInstruction(bool &isActionPhase,int &progressValue){
    if(instructionIndex == 1){
        if(currentPhase == 3){
            currentPhase = 0;
            turn++;
        } else {
            currentPhase++;
        }
        instructionIndex = 0;
    } else {
        instructionIndex++;
    }
    if(currentPhase == 2){
        isActionPhase = true;
    } else {
        isActionPhase = false;
    }
    progressValue = currentPhase*2+instructionIndex;
}
int marsGame::GetTurn(){
    return turn;
}

QString marsGame::getInstruction(){
    return phasesInstructions[currentPhase][instructionIndex];
}

QString marsGame::getPhase(){
    return phases[currentPhase];
}
marsGame::~marsGame(){

}

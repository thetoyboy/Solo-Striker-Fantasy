/////////////////////////////////////////////////////////////////////////////////////
//                          GameScene                                              //
//the GameScene could be considered as a handler of the Game-objects'reference     //
//all the game Objects that could be placed in the scene are 'Actor' based Objects //
//                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////
#ifndef PFE_GAMESCENE_H_
#define PFE_GAMESCENE_H_
#include "Actor.h"
#include "Camera.h"
class GameScene {
public:
    GameScene();
    ~GameScene() ;
    int AddActor(Actor** actor);
    void FreeVector();
    Actor** getActors();
    int getNBActors();
 //   void AddPlayer(Player * player);
    void Destroy() ;
    void setCamera(Camera*);
    Camera* getCamera();
private:
    unsigned int        Size ;
    unsigned int        m_NBActors ;
    Actor**             v_Actors ;
    //Player*             m_Player ;
    Camera*             m_Camera ;
};
#endif // PFE_GAMESCENE_H_

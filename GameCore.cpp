#include "GameCore.h"
GameCore::GameCore ():m_Logic(NULL), m_Graphics(NULL), m_Scene(NULL), m_Window(NULL),
                    m_Running(false)
{};
GameCore::~GameCore(){
    this->Destroy();
};
int GameCore::Init(char * Name,int Width, int Height,bool FullScreen, char* icon){
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        return 0 ;
    }
    //create and Initilize the Window object
    m_Window=new WindowHandler();
    if(!m_Window)
        return 0 ;
    if(!m_Window->InitWindow(Name,Width,Height,FullScreen,icon)){
        return 0 ;}

    //Create and Init the GameScene
    m_Scene=new GameScene();
    if(!m_Scene)
        return 0 ;
    //Create and Init the Graphics engine
    m_Graphics=new GraphicsEngine();
    if(!m_Graphics)
        return 0 ;
    if(!m_Graphics->InitEngine(m_Window,m_Scene)){
        return 0 ;
    }
    //Create and Init the Game Logic
    m_Logic=new GameLogic();
    if(!m_Logic)
        return 0 ;
    if(!m_Logic->InitLogic(m_Scene)){
        return 0 ;
    }
    m_Logic->setExitVariable(&m_Running);
    return 1 ;
};
void GameCore::StartGame(){
    m_Running=true ;
    float Dt ;
    m_Timer.Reset();
    int i = 0 ;
    while(m_Running){
        i++;
        Dt=m_Timer.getDeltaTime();
        m_Logic->Update(Dt);
        if(i==2){
            i=0;
            m_Graphics->DrawScene();
        }
    }
};
void GameCore::Destroy(){
    SDL_Quit();
    m_Timer.Stop();
    if(m_Logic){
        m_Logic->Destroy();
        delete m_Logic ;
        m_Logic=NULL ;
    };
    if(m_Graphics){
        m_Graphics->Destroy();
        delete m_Graphics ;
        m_Graphics=NULL ;
    }
    if(m_Scene){
        m_Scene->Destroy();
        delete m_Scene ;
        m_Scene=NULL ;
    }
    if(m_Window){
        m_Window->Destroy();
        delete m_Window ;
        m_Window=NULL ;
    }
};

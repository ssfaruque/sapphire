#ifndef GAME_H
#define GAME_H

#include "sapphire/application.h"
#include "sapphire/sapphire.h"


class Game : public sap::Application
{
    private:
        bool m_running;
        sap::Sapphire* m_engine;

    public:
        Game();
        ~Game();

        bool init() override;
        void shutDown() override;
        void run() override;
        void onUpdate() override;

};



#endif  // GAME_H




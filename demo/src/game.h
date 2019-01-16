#ifndef GAME_H
#define GAME_H

#include "sapphire/application.h"

class Game : public sap::Application
{
    private:
        bool m_running;

    public:
        Game();
        ~Game();

        void run() override;
        void onUpdate() override;

};



#endif  // GAME_H
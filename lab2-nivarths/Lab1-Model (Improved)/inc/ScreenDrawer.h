#ifndef SCREENDRAWER_H
#define SCREENDRAWER_H

#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "ItemBin.h"

class ScreenDrawer
{
    private:
        GameMechs* gmRef;
        Player* playerRef;
        ItemBin* binRef;

    public:
        ScreenDrawer(GameMechs* gm, Player* player, ItemBin* binRef);
        ~ScreenDrawer();

        void Draw() const;
        void DrawEndGame() const;
        void DrawAverageComputationTime(double data) const;

};

#endif
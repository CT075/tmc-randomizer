#include "global.h"
#include "item.h"

struct ArchipelagoReceivedItem
{
    Item id;                     // The item to be received
    u16 itemIndex;               // The index of the item according to the AP server
    bool8 isFilled;              // Whether there is an item in this struct that has not been consumed
    bool8 isProgression;         // Whether a message is progression (for filtering messages)
};

extern void InitItemGetSequence(u32 type, u32 type2, u32 delay);

struct ArchipelagoReceivedItem *gArchipelagoReceivedItem = (struct ArchipelagoReceivedItem *) 0x02033400;

inline void ArchipelagoTryGiveItem() {
    if (gArchipelagoReceivedItem->isFilled) {
        // TODO: Kinstones
        InitItemGetSequence(gArchipelagoReceivedItem->itemIndex, 0, 0);
        gArchipelagoReceivedItem->isFilled = FALSE;
    }
}

extern void UpdateDoorTransition(void);
extern void CollisionMain(void);
extern void UpdateScroll();

// Hook in [archipelago.event] takes 6 words, wiping exactly 3 bl calls from
// [GameUpdate_Main], reproduced here.
void ArchipelagoTryGiveItem_Hook() {
    ArchipelagoTryGiveItem();
    UpdateDoorTransition();
    CollisionMain();
    UpdateScroll();
}

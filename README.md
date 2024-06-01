## Overview and Special Thanks
 - Neither this map mod or any future updates for it will be paywalled in any way.  It will not be removed from the Steam Workshop for any reason within my control.  It has been created by me for the community, always available, always for free, and you can hold me to that at risk of public shame and DayZ disbarment.  🫡
 - This version of the map is the minimum viable experience with full progression and endgame.  I will be providing core map updates at a slower pace moving forward so as to not force frequent wipes on any communities/server admins who adopt the map.
 - We welcome all feedback big or small in the discord, link below.  Special thanks to the OG members who have played for the last year and provided input and support, and to DayZ modder LIVINGxDEAD for creating Winter Anastara and the dynamic weather events for this mod.

## Anastara DayZ Map Mod Mission Files
config-profiles:  optional config files for Gebs Fish, SimpleSpawner and SpawnerBubaku

dayzOffline.anastara:  standard XMLs for mission (territories, types, etc.)

cle:  central loot economy files for DayZ tools economy editor

### Core server-side mods
@CJ187-SimpleSpawner: allows spawning of CJ_Armed_LandMineTrap for minefields (optional, do not include to disable minefields entirely)

@SpawnerBubaku:  allows underground zombie spawns

(CJ187 Armed Mines is packed into the Anastara map mod on Steam Workshop with licensing/permission and works out of the box, no need to install it separately)

### IMPORTANT FOR PERFORMANCE
Minefields can have significant performance impact depending on your server specs.  If you are experiencing higher than normal server FPS drops:
 - disable minefields entirely by removing SimpleSpawner as serverside mod
 - reduce lifetime of CJ_Armed_LandMineTrap in types.xml
 - progressively reduce the number of mines spawned and spawn locations in SimpleSpawner.json (as low as 200-300 is still viable)
 - to remove all armed mines currently in the world, rename @Anastara/CJ187_ArmedMines.pbo to @Anastara/CJ187_ArmedMines.old (or .backup or whatever) and restart server.  This removes all existing landmines, then rename @Anastara/CJ187_ArmedMines.pbo back to normal and restart server again.

### Required Mods
 - Anastara
 - Anastara Server Pack
 - CF
 - Dabs Framework (for dynamic weather events by LIVINGxDEAD)
 - Windstrides Clothing Pack

### Recommended Mods
These mods improve the experience but are not dependencies:
 - Gebs Fish
 - Waterfall
 - Fireplace+
 - Crocodile
 - ZenNotes
 - WindstridesClothingPack
 - RedFalcon Flight System Helis
 - RedFalcon Watercraft 
 - Basic Ear Plugs
 - No Force Weapon Raise

### Types
For convenience (hopefully), the types.xml in core-mission/db includes entries from all of the required and recommended mods listed above.  Search #mod in types.xml to view each section.  

### Special Thanks
The following community members were critical to the Anastara project:
 - bloodswarms
 - kotton
 - yourgirlvexxi
 - kkaasseeyy65
 - mikjailbottington
 - terpyclay
 - kingslayer turbo
 - lambos2n
 - yourfriendfaust
 - briantwin
 - lottie
 - spaggie
 - livingxdead
 - filthysausage
 - dirtyburglar

If I missed anyone, please don't be shy and let me know.  

### Contact
X: https://x.com/battlesquatch

Discord:  https://discord.gg/jWRTGMyhFR

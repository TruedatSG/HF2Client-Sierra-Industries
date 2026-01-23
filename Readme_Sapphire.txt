Project Sapphire 5.32 README by ALEXANDER


Project Sapphire aka. Project Ruby Dreams is the HF2Client.dll library for
the Hellfire II expansions by Sierra Industries.  Since I don't have the
source code for Diablo II 1.13d, I decided to make use of this project library
from BlizzHackers.

What to know:
Project Ruby is mainly a UI enhancement but it also contains 'Key Items' that
will unlock some of the game's features.  Xinput is now built into some versions
of Sapphire depending on the release allowing players to use an Xbox controller
to play complete with the rumble feature. (See the Launcher.exe for a list of
keys)

Getting started:
Type ?help for a list of commands.  If the project was built using DEBUGINPUT the
commands will use '?' instead of '/' so they can be used on TCP/IP or D2GS.

Status menu:
Pressing the 'G' key will open the status menu.  Select an option by hovering the
mouse over the object and selecting it with a left click or the 'A' button on the
Gamepad.  Pressing the 'B' button will easily close any open objects.  There is a
widget that will appear at the top of the screen if you have your key items enabled.

Guild ladder:
The guild ladder can store the info of up to 1,000 classic and expansion
characters.  Hardcore characters will be recorded in black font if they are slain.
Advance classes will also be displayed ladder if they are unlocked and active.
(Registration Papers key item enabled required to record data.)  You can also record
a guild note by typing /setnote <note>.

Experience meter:
The experience meter is unlocked via collecting key items.  It can break down level
progress into fractions of 1/500ths and 1/10ths on a large scale.  If you hover the
mouse over the experience bar, the experience gained at this level will be displayed
as well as the current TNL.

Player info:
Make sure to create a Save\Exodus\ directory as this is where the extended data is
stored for each character.  Player info includes, Date/Time, Travel, Monsters, Classes,
Potions, Equipment, Shrines, KO's, Win/Losses, and more types of info are stored here.

Properties:
You can open this little side menu object to see what item properties you have active,
such as, Magic Find, Reduced Damage, Faster Cast, Faster Run/Walk, Etc.

Calculus:
You can unlock this feature by obtaining key items.  This menu object does simple math
that will help you calculate your progress and show you how many supplies you have and gold
etc, as well as states of skills and curses.

Magical map:
The map can also be enhanced by unlocking key items.  You can reveal areas and display monsters
on map as well as the most direct route to areas and quest objectives.  Some of these key items
are harder to acquire, be sure to read all the missions thoroughly as you may need to hunt
monsters to unlock some of these items.  (Note: There are no Meadow Fairies until Sands of Caly-
pso so don't go chasing fairies!)  Shrines are visible on map as well.

Missions:
These are the base missions I've included with the game, roughly 10 per expansion.  These include
scavenger hunts, easter eggs, info on how to unlock certain key items, and so on.  Note, that
I designed this system to easily add more missions.  Missions are stored in the Interface\Scripts\
folder and can easily be added if you would like to add your own scavenger hunt or lore to the
game.

Key Items:
Key items are obtained by completing an objective and moving within range of the NPC for that
designated expansion.  Usually you have to have the first key item from that expansion enabled
to acquire more key items with the exception of Classic.  To obtain your first key item.  Talk
to Kashya for 3 minutes and she will give you a Beta I.D. Card and Registration Papers which
will allow you to use the guild ladder.  Most key items are obtains by reaching a certain level
or by talking/standing near the NPC for a period of time.  The harder missions require you to
hunt a certain amount of monsters, but there are only a few missions like that as of now.  Note
that in newer releases, I have made it much easier to obtain key items than before.  Also note
that key items carry over from one character to the next, so you only need to obtain them once.
You can type /resetkeyitems to remove all key items or /operationcwal to unlock all key items
(Beta only).

Wins/Losses:
Wins are granted by killing an act boss or staying in the game 90 minutes without dying.
Staying in the game 20 minutes without dying will result in a draw.  Anything else will
result in a loss, including exiting the game while not in town (with Dream Recorder).

Ratings:
Players can rank up by improving their Win/Loss rating.  The highest rank is 10, with the
lowest being 1.  It will many games to reach rank 10, although, I have made it much easier
to rank up in recent updates.  You can lower your rank by losing too many games.

Other:
If you are having trouble picking up an item or opening a door because of the Aim Assist for
gamepads, you can now select 'Unsummon' as a left skill to click anything on the map.

Bugs/Errors:
Client will crash rarely with an error.  You can simply press 'Esc' or the 'B' button on the
Gamepad to clock the client to exit without using the task manager.

Note: For PvPGN users, if using Sapphire built with no KILLPROCESS, do not close the client
abruptly and wait 10-15 seconds inbetween games the allow for the data threads to clean-up!

Well, that's all for now folks!

Good luck.




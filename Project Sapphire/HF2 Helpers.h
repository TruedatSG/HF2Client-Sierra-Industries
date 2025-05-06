BOOL ValidCounterMonsters(LPUNITANY Unit);
BOOL MonsterCheckType(LPUNITANY Unit, exUnitAny* exUnit);
BOOL MonsterCheckResistance(LPUNITANY Unit);

BOOL CountGame();
VOID EventGetTime(INT Type);

BOOL PlayMenuSound(INT Number, INT Reset);
std::string SingleDigitToString(int iDigit);
void Hf2Log(char* Msg...);
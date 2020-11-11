#include <iostream>
#include <string>

#include "models/Input.h"

/*#include "models/Output.h"
#include "models/Card.h"
#include "models/Deck.h"
#include "models/Hand.h"
#include "models/Human.h"
#include "models/Dealer.h"
#include "models/Player.h"*/

using namespace std;

int main() {
    Input input;
    cout << input.inputFromVoice() << endl;
    cout << endl;
    cout << input.inputFromString() << endl;
    cout << endl;
}

#include "Table.h"

using namespace std;

Table::Table() {
	cardDeck.shuffle();
	win = 0;
	
}

Table::~Table() {}

void Table::doHit(Player player) {}

void Table::doStand(Player player) {}

void Table::doSplit(Player player) {}

int Table::checkWin() {return win;}

void Table::runGame() {}

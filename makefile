# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

final: go_fish.o player.o deck.o card.o
	g++ -o GoFish go_fish.o player.o deck.o card.o
driver: go_fish.cpp player.h deck.h card.h
	g++ -c go_fish.cpp
Player.o: player.cpp player.h deck.h card.h
	g++ -c player.cpp
Deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
Card.o: card.cpp card.h
	g++ -c card.cpp

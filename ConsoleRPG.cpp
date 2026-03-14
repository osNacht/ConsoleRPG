#include <iostream>

int Goblin(int& health, int& attack, int& potions, int& balance, double dmgMultiplier);
int Orc(int& health, int& attack, int& potions, int& balance, double dmgMultiplier);
int Dragon(int& health, int& attack, int& potions, int& balance, double dmgMultiplier);
int shop(int& balance, int& potions);

int main() {

    std::cout << "Enter the hero's name: ";
    std::string heroName;
    std::cin >> heroName;

    std::cout << "Choose a class >\n"
              << " 1 - Warrior\n #===== Stats =====#\n |--> Health: 150\n |--> Attack: 20\n |--> DMG Multiplier: 0.8x\n " << std::endl
              << " 2 - Mage\n #===== Stats =====#\n |--> Health: 100\n |--> Attack: 35\n |--> DMG Multiplier: 0.5x\n " << std::endl
              << " 3 - Archer\n #===== Stats =====#\n |--> Health: 120\n |--> Attack: 25\n |--> DMG Multiplier: 0.65x\n" << std::endl;
    int classChoice;
    std::cin >> classChoice;

    double dmgMultiplier = 0;
    int health, attack;
    switch (classChoice) {
        case 1:
            health = 150;
            attack = 20;
            dmgMultiplier = 0.8;
            break;
        case 2:
            health = 100;
            attack = 35;
            dmgMultiplier = 0.5;
            break;
        case 3:
            health = 120;
            attack = 25;
            dmgMultiplier = 0.65;
            break;
        default:
            std::cout << "Invalid class choice. Defaulting to Warrior." << std::endl;
            health = 150;
            attack = 20;
            dmgMultiplier = 0.8;
            break;
    }

    int potions = 2;
    int balance = 20;
    bool heroIsAlive = true;
    int locationChoice;

    do {
        std::cout << "Where do you want to go?\n "
                  << "1 - Forest (Goblin)\n "
                  << "2 - Cave (Orc)\n "
                  << "3 - Mountain (Dragon)\n "
                  << "4 - Shop\n "
                  << "0 - Exit" << std::endl;
        std::cin >> locationChoice;
        switch (locationChoice) {
            case 1:
                Goblin(health, attack, potions, balance, dmgMultiplier);
                break;
            case 2:
                Orc(health, attack, potions, balance, dmgMultiplier);
                break;
            case 3:
                Dragon(health, attack, potions, balance, dmgMultiplier);
                break;
            case 4:
                shop(balance, potions);
                break;
            case 0:
                std::cout << "You exit the game. Goodbye!" << std::endl;
                heroIsAlive = false;
                break;
            default:
                std::cout << "Invalid location choice. Defaulting to Shop." << std::endl;
                shop(balance, potions);
                break;
        }
    } while (heroIsAlive);

    return 0;
}

int Goblin(int& health, int& attack, int& potions, int& balance, double dmgMultiplier) {
    std::cout << "A wild Goblin appears! (health: 50, attack: 10)\n" << std::endl;

    bool goblinIsAlive = true;
    int goblinHealth = 50;
    int goblinAttack = 10;
    do {
        std::cout << "===== Goblin Fight =====\n Your Health: " << health << " | Goblin's Health: " << goblinHealth << "\n 1 - Attack\n 2 - Use potion (+30 hp) [has: "<< potions <<"]\n 3 - Escape" << std::endl;
        int action;
        std::cin >> action;
        switch (action) {
            case 1:
                goblinHealth -= attack;
                std::cout << "You attack the Goblin for " << attack << " damage!" << std::endl;
                if (goblinHealth > 0) {
                    std::cout << "Goblin's health: " << goblinHealth << std::endl;
                    std::cout << "The goblin attacked back!" << std::endl;
                    health -= static_cast<double>(goblinAttack) * dmgMultiplier;
                    std::cout << "Your health: " << health << std::endl;
                    if (health <= 0) {
                        std::cout << "You were defeated by the Goblin!" << std::endl;
                        return 0;
                    }
                }
                else if (goblinHealth <= 0) {
                    std::cout << "You defeated the Goblin!" << std::endl;
                    std::cout << "You found some gold on the Goblin!" << std::endl;
                    balance += 40;
                    std::cout << "Your balance: " << balance << std::endl;
                    goblinIsAlive = false;
                }
                break;
            case 2:
                if (potions > 0) {
                    health += 30;
                    potions--;
                    std::cout << "You use a potion and restore 30 health! (Health: " << health << ", Potions left: " << potions << ")" << std::endl;
                }
                else {
                    std::cout << "No potions left!" << std::endl;
                }
                break;
            case 3:
                std::cout << "You escape from the Goblin!" << std::endl;
                std::cout << "You lost money!" << std::endl;
                balance -= 10;
                std::cout << "Your balance: " << balance << std::endl;
                return 0;
            default:
                std::cout << "Invalid action. Please choose again." << std::endl;
        }
    } while (goblinIsAlive);

    return 0;
}

int Orc(int& health, int& attack, int& potions, int& balance, double dmgMultiplier) {
    std::cout << "A wild Orc appears! (health: 80, attack: 18)\n" << std::endl;

    bool orcIsAlive = true;
    int orcHealth = 80;
    int orcAttack = 18;
    do {
        std::cout << "===== Orc Fight =====\n Your Health: " << health << " | Orc's Health: " << orcHealth << "\n 1 - Attack\n 2 - Use potion (+30 hp) [has: "<< potions <<"]\n 3 - Escape" << std::endl;
        int action;
        std::cin >> action;
        switch (action) {
            case 1:
                orcHealth -= attack;
                std::cout << "You attack the Orc for " << attack << " damage!" << std::endl;
                if (orcHealth > 0) {
                    std::cout << "Orc's health: " << orcHealth << std::endl;
                    std::cout << "The Orc attacked back!" << std::endl;
                    health -= static_cast<double>(orcAttack) * dmgMultiplier;
                    std::cout << "Your health: " << health << std::endl;
                    if (health <= 0) {
                        std::cout << "You were defeated by the Orc!" << std::endl;
                        return 0;
                    }
                }
                else if (orcHealth <= 0) {
                    std::cout << "You defeated the Orc!" << std::endl;
                    std::cout << "You found some gold on the Orc!" << std::endl;
                    balance += 80;
                    std::cout << "Your balance: " << balance << std::endl;
                    orcIsAlive = false;
                }
                break;
            case 2:
                if (potions > 0) {
                    health += 30;
                    potions--;
                    std::cout << "You use a potion and restore 30 health! (Health: " << health << ", Potions left: " << potions << ")" << std::endl;
                }
                else {
                    std::cout << "No potions left!" << std::endl;
                }
                break;
            case 3:
                std::cout << "You escape from the Orc!" << std::endl;
                std::cout << "You lost money!" << std::endl;
                balance -= 20;
                std::cout << "Your balance: " << balance << std::endl;
                return 0;
            default:
                std::cout << "Invalid action. Please choose again." << std::endl;
        }
    } while (orcIsAlive);

    return 0;
}

int Dragon(int& health, int& attack, int& potions, int& balance, double dmgMultiplier) {
    std::cout << "A wild Dragon appears! (health: 150, attack: 30)\n" << std::endl;

    bool dragonIsAlive = true;
    int dragonHealth = 150;
    int dragonAttack = 30;
    do {
        std::cout << "===== Dragon Fight =====\n Your Health: " << health << " | Drgon's Health: " << dragonHealth << "\n 1 - Attack\n 2 - Use potion (+30 hp) [has: "<< potions <<"]\n 3 - Escape" << std::endl;
        int action;
        std::cin >> action;
        switch (action) {
            case 1:
                dragonHealth -= attack;
                std::cout << "You attack the Orc for " << attack << " damage!" << std::endl;
                if (dragonHealth > 0) {
                    std::cout << "Dragon's health: " << dragonHealth << std::endl;
                    std::cout << "The dragon attacked back!" << std::endl;
                    health -= static_cast<double>(dragonAttack) * dmgMultiplier;
                    std::cout << "Your health: " << health << std::endl;
                    if (health <= 0) {
                        std::cout << "You were defeated by the Dragon!" << std::endl;
                        return 0;
                    }
                }
                else if (dragonHealth <= 0) {
                    std::cout << "You defeated the Dragon!" << std::endl;
                    std::cout << "You found some gold on the Dragon!" << std::endl;
                    balance += 120;
                    std::cout << "Your balance: " << balance << std::endl;
                    dragonIsAlive = false;
                }
                break;
            case 2:
                if (potions > 0) {
                    health += 30;
                    potions--;
                    std::cout << "You use a potion and restore 30 health! (Health: " << health << ", Potions left: " << potions << ")" << std::endl;
                }
                else {
                    std::cout << "No potions left!" << std::endl;
                }
                break;
            case 3:
                std::cout << "You escape from the Dragon!" << std::endl;
                std::cout << "You lost money!" << std::endl;
                balance -= 20;
                std::cout << "Your balance: " << balance << std::endl;
                return 0;
            default:
                std::cout << "Invalid action. Please choose again." << std::endl;
        }
    } while (dragonIsAlive);

    return 0;
}

int shop(int& balance, int& potions) {
    std::cout << "===== Shop =====\nWelcome to the shop! \nYou can buy potions here. Your balance: " << balance << "\n 1 - Buy potion (20 gold)\n 2 - Exit shop" << std::endl;
    int shopChoice;
    std::cin >> shopChoice;
    switch (shopChoice) {
        case 1:
            if (balance >= 20) {
                balance -= 20;
                potions++;
                std::cout << "You bought a potion! Your balance: " << balance << ", Potions: " << potions << std::endl;
            }
            else {
                std::cout << "Not enough gold to buy a potion!" << std::endl;
            }
            break;
        case 2:
            std::cout << "You exit the shop." << std::endl;
            break;
    }
    return 0;
}

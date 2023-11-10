#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player {
public:
    int health;
    int damage;
    int defense;
    int level;

    Player() {
        health = 100;
        damage = 10;
        defense = 5;
        level = 1;
    }

    void showStats() {
        cout << "Level: " << level << " | Health: " << health << " | Damage: " << damage << " | Defense: " << defense << endl;
    }

    void levelUp() {
        level++;
        health += 20;
        damage += 5;
        defense += 2;
        cout << "Level up! Your stats have increased." << endl;
        showStats();
    }
};

class Enemy {
public:
    int health;
    int damage;
    int defense;

    Enemy(int playerLevel) {
        health = 30 + playerLevel * 10;
        damage = 5 + playerLevel * 2;
        defense = 2 + playerLevel;
    }

    bool isAlive() {
        return health > 0;
    }
};

class Game {
public:
    Player player;

    void start() {
        cout << "Welcome to the Text Adventure Game!" << endl;
        while (player.health > 0) {
            playTurn();
        }
        cout << "Game Over. You have been defeated." << endl;
    }

    void playTurn() {
        cout << "=====================================" << endl;
        player.showStats();
        cout << "1. Explore" << endl;
        cout << "2. Quit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            explore();
            break;
        case 2:
            player.health = 0; // Quit the game
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    void explore() {
        int randNum = rand() % 3; // 0, 1, or 2

        if (randNum == 0) {
            // Enemy encounter
            Enemy enemy(player.level);
            cout << "You encounter an enemy!" << endl;

            while (player.health > 0 && enemy.isAlive()) {
                performBattle(&enemy);
            }

            if (player.health > 0) {
                cout << "You defeated the enemy!" << endl;
                player.levelUp();
            }
            else {
                cout << "You were defeated by the enemy." << endl;
            }
        }
        else {
            // No enemy encounter, player finds an item
            cout << "You found a health potion! (+20 health)" << endl;
            player.health += 20;
        }
    }

    void performBattle(Enemy* enemy) {
        cout << "=====================================" << endl;
        cout << "Enemy Stats: Health " << enemy->health << " | Damage " << enemy->damage << " | Defense " << enemy->defense << endl;
        cout << "1. Attack" << endl;
        cout << "2. Defend" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            attackEnemy(enemy);
            break;
        case 2:
            defend();
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

        if (enemy->isAlive()) {
            // Enemy attacks back
            int enemyDamage = enemy->damage - player.defense;
            if (enemyDamage > 0) {
                player.health -= enemyDamage;
                cout << "The enemy attacks you for " << enemyDamage << " damage!" << endl;
            }
            else {
                cout << "The enemy's attack is blocked by your defense!" << endl;
            }
        }
    }

    void attackEnemy(Enemy* enemy) {
        int playerDamage = player.damage - enemy->defense;
        if (playerDamage > 0) {
            enemy->health -= playerDamage;
            cout << "You attack the enemy for " << playerDamage << " damage!" << endl;
        }
        else {
            cout << "The enemy's defense is too strong. Your attack has no effect." << endl;
        }
    }

    void defend() {
        // Increase player's defense for this turn
        player.defense += 2;
        cout << "You defend against the enemy's attack. Your defense is increased for this turn." << endl;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    Game game;
    game.start();

    return 0;
}
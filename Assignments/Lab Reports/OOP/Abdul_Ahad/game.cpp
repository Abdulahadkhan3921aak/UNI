#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>
#include <iomanip>

class enemy;
class player;

std::string playerAttack, EnemyAttack, playerDodge, EnemyDodge, playerMana, EnemyMana;
bool _playerAttack = false, _EnemyAttack = false, _playerDodge = false, _EnemyDodge = false, _playerMana = false, _EnemyMana = false;

void GameOver()
{
    std::cout << "Well played , You Died :(\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    exit(0);
}

class trait
{
protected:
    float health;
    float attack;
    int mana;
    float speed;
    int level;
    int XP;
    bool Dodge = false;
};

class weapon {
private:
    std::string name;
    float damage;

public:
    weapon(std::string n = "sword", float d = 10) : name(n), damage(d) {}

    std::string getName() const { return name; }

    float getDamage() const { return damage; }

    void setName(std::string n) { name = n; }

    void setDamage(float d) { damage = d; }

    void upgrade() {
        damage += 5;
        std::cout << "Weapon upgraded! Damage increased to " << damage << std::endl;
    }
};


class player : protected weapon, protected trait
{
private:
    float HEALTH;
    int MANA;
    int hitcounter = 0;

public:
    player()
    {
        health = 80;
        attack = 15 + this->getDamage();
        mana = 12;
        speed = 0.4;
        level = 1;
        XP = 0;
        MANA = mana;
        HEALTH = health;
    }

    void changeWeapon(int a)
    {
        attack += a;
    }

    void levelUP()
    {
        XP = 0;
        level++;
        speed++;
        attack += (30 * attack / 100);
        health += (60 * health / 100);
        mana += (40 * mana / 100);
        MANA = mana;
        HEALTH = health;
    }

    void AddXP(int xp)
    {
        XP += xp;
        if (XP >= 30)
        {
            levelUP();
            XP %= 30;
        }
    }

    void dodge()
    {
        Dodge = true;
    }

    bool Attack(float atk, int reqMana)
    {
        if (MANA < reqMana)
        {
            std::cout << "Mana is low\n";
            DontAttack();
            return false;
        }
        else
        {
            hitcounter++;
            if(hitcounter % 20 == 0){
                hitcounter = 0;
                this->attack -= this->getDamage();
                this->upgrade();
                this->attack += this->getDamage();
            }
            MANA -= reqMana;
            return true;
        }
    }

    int Damage(float _atk)
    {
        if (Dodge)
        {
            std::cout << "Player doged, Attack missed\n";
            Dodge = false;
            return HEALTH;
        }
        return (HEALTH -= (rand() % 100 <= 5) ? _atk * 1.5 : _atk);
    }

    void DontAttack()
    {
        if (MANA + 5 <= mana)
        {
            MANA += 5;
        }
        else if (MANA == mana)
        {
            std::cout << "Attack missed\nMana is Maxed\n";
        }
        else
        {
            MANA += (mana - MANA);
            std::cout << "Attack missed\n5 Mana restored\n";
        }
    }

    void AddHealth(float _h)
    {
        HEALTH += _h;
        if (HEALTH > health)
        {
            HEALTH = health;
        }
    }

    void AddMana(float _m)
    {
        MANA += _m;
        if (MANA > mana)
        {
            MANA = mana;
        }
    }

    float GetCurrentHealth()
    {
        return HEALTH;
    }
    float GetTotalHealth()
    {
        return health;
    }

    int GetCurrentMana()
    {
        return MANA;
    }
    int GetTotalMana()
    {
        return mana;
    }
    int GetLevel()
    {
        return level;
    }
    float GetAttack()
    {
        return attack;
    }
    int getXP()
    {
        return XP;
    }
    int GetTotalXP()
    {
        return 30;
    }
};

class enemy : protected weapon, protected trait
{

private:
    int MANA;
    float HEALTH;
    bool miss = false;

public:
    enemy(int playerLevel)
    {
        level = ((rand() % 10 > 5) ? playerLevel + rand() % 2 : playerLevel - rand() % 2) + 2;
        health = level * 70;
        attack = level * 1.2 + (rand() % level) / level;
        XP = (int)(health / level + health / attack) % 30 + level * 2;
        mana = level * 5 + 7;
        MANA = mana;
        HEALTH = health;
    }
    void dodge()
    {
        Dodge = true;
    }

    int Damage(float _atk)
    {
        if (Dodge)
        {
            playerDodge = "Enemy doged, Attack missed";
            Dodge = false;
            return HEALTH;
        }
        return (HEALTH -= (rand() % 100 <= 5) ? _atk * 1.1 : _atk);
    }

    void Attack(player &obj, float atk)
    {
        miss = (rand() % 20 == 0) ? true : false;
        if (miss)
        {
            EnemyAttack = "Attack missed";
            return;
        }
        EnemyAttack = "Attack Hit";
        if (obj.Damage(atk) <= 0)
        {
            GameOver();
        }
    }

    void DontAttack()
    {
        if (MANA + 5 <= mana)
        {
            MANA += 5;
            playerMana = "Attack missed\n5 Mana restored";
        }
        else if (MANA == mana)
        {
            playerMana = "Attack missed\nMana is Maxed";
        }
        else
        {
            MANA += (mana - MANA);
            playerMana = "Attack missed\nMana is Maxed";
        }
    }

    float GetCurrentHealth()
    {
        return HEALTH;
    }
    float GetTotalHealth()
    {
        return health;
    }

    int GetCurrentMana()
    {
        return MANA;
    }
    int GetTotalMana()
    {
        return mana;
    }
    int GetLevel()
    {
        return level;
    }
    float GetAttack()
    {
        return attack;
    }
    int getXP()
    {
        return XP;
    }
};

void Draw(player p, enemy e)
{
    int w = 28;
    system("cls");
    std::cout << "    \t\t    Player     \t\t\t\tEnemy\n\n\n";
    std::cout << "\t\tHealth : " << p.GetCurrentHealth() << " / " << p.GetTotalHealth();
    std::cout << std::setw(w) << "Health : " << e.GetCurrentHealth() << " / " << e.GetTotalHealth() << "\n";
    std::cout << "\t\tMana : " << p.GetCurrentMana() << " / " << p.GetTotalMana();
    std::cout << std::setw(w) << "Mana : " << e.GetCurrentMana() << " / " << e.GetTotalMana() << "\n";
    std::cout << "\t\tAttack : " << p.GetAttack();
    std::cout << std::setw(w + 5) << "Attack : " << e.GetAttack() << "\n";
    std::cout << "\t\tLevel : " << p.GetLevel();
    std::cout << std::setw(w + 6) << "Level : " << e.GetLevel() << "\n";
    std::cout << "\t\tXP : " << p.getXP() << " / " << p.GetTotalXP();
    ;
    std::cout << "\n\n";
    std::cout << "\tPress \n\t    \'A\' To attack \n";
    std::cout << "\t    \'S\' to do nothing\n";
    std::cout << "\t    \'D\' to dodge\n";
    std::cout << "\n\n";
}

void getInput(char &c)
{
    c = getche();
    std::cout << "\n";
}

void PlayerAction(char c, player &p, enemy &e)
{

    switch (c)
    {
    case 'a':
        if (p.Attack(p.GetAttack(), 4))
        {
            if (e.Damage(p.GetAttack()) <= 0)
            {
                p.AddXP(e.getXP());
            }
        }
        break;

    case 's':
        p.DontAttack();
        break;

    case 'd':
        p.dodge();
        break;

    case 'A':
        if (p.Attack(p.GetAttack(), 4))
        {
            if (e.Damage(p.GetAttack()) <= 0)
            {
                p.AddXP(e.getXP());
            }
        }
        break;

    case 'S':
        p.DontAttack();
        break;

    case 'D':
        p.dodge();
        break;

    default:
        std::cout << "Wrong input\n ReEnter : ";
        getInput(c);
    }
}

void EnemyAction(player &p, enemy &e)
{
    char c;
    int r = rand() % 20;
    if (r > 8)
    {
        c = 'a';
    }
    else if (r > 3)
    {
        c = 's';
    }
    else
    {
        c = 'd';
    }
    switch (c)
    {
    case 'a':
        e.Attack(p, e.GetAttack());
        break;

    case 's':
        e.DontAttack();
        break;

    case 'd':
        e.dodge();
        break;
    }
}
void DisplayInfo()
{
    std::cout << "\n";
    std::cout << playerAttack << EnemyAttack << "\n";
    std::cout << playerDodge << EnemyDodge << "\n";
    std::cout << playerMana << EnemyMana << "\n";
    std::cout << "\n";
}

int main()
{

    srand(time(0));
    player P;
    enemy E(P.GetLevel());
    bool gameOver = false;
    char o;

    while (!gameOver)
    {
        Draw(P, E);
        getInput(o);
        DisplayInfo();
        playerAttack = "\t\t\t\t\t\t";
        EnemyAttack = "\t\t\t\t\t\t";
        playerDodge = "\t\t\t\t\t\t";
        EnemyDodge = "\t\t\t\t\t\t";
        playerMana = "\t\t\t\t\t\t";
        EnemyMana = "\t\t\t\t\t\t";
        EnemyAction(P, E);
        PlayerAction(o, P, E);
        if (E.GetCurrentHealth() <= 0)
        {
            std::cout << "Enemy Defeated, Spawning new Enemy\n";
            P.AddHealth(E.GetTotalHealth());
            P.AddMana(E.GetTotalMana());
            E = enemy(P.GetLevel());
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    }
    return 0;
}
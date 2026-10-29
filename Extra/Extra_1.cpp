#include <iostream>
#include <string>

class Character {

public:
	Character(int lifeArg, std::string nameArg)
		: life(lifeArg), name(nameArg) {}

	virtual void attack() {
		std::cout << "The character uses a basic attack.\n";
	}

	virtual void receiveDamage(int damage) {
		life -= damage;
		if (life < 0) life = 0;
	}

	virtual int getLife() {
		return life;
	}

	virtual std::string getName() {
		return name;
	}

	protected:
		std::string name;
		int life;

};

class Warrior : public Character {

public:
	Warrior(int lifeArg, std::string nameArg, int armorArg)
		: Character(lifeArg, nameArg), armor(armorArg) {}

	void attack() {
		std::cout << "The character swings it's long sword!\n";
	}

	void receiveDamage(int damage) {
		int reducedDamage = damage - armor;
		if (reducedDamage < 0) reducedDamage = 0;
		life -= reducedDamage;
	}

private:
	int armor;

};

class Mage : public Character {

public:
	Mage(int lifeArg, std::string nameArg, int manaArg)
		: Character(lifeArg, nameArg), mana(manaArg) {}

	void attack() {
		if (mana > 0) {
			std::cout << "The character casts a powerful spell!\n";
			mana--;
		}
		else std::cout << "The character doesn't have enough mana, so it makes a weak physical attack.\n";
	}

private:
	int mana;
};

int main() {
	Warrior char1(10, "warrior", 2);
	Mage char2(10, "mage", 6);

	char1.attack();
	char2.receiveDamage(2);
	std::cout << char2.getName() << ", life: " << char2.getLife() << "\n";
	char2.attack();
	char1.receiveDamage(4);
	std::cout << char1.getName() << ", life: " << char1.getLife() << "\n";
}
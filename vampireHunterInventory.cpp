#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

//Forward Declarations
void dieRoll(int* p_firstDie);
void name(string* p_userName);
void YOrN(string* p_YesOrNo, string* p_invalid);
void YOrNEntranceToKingsBridge(string* p_YesOrNo, string* p_invalid, int* p_cross, int* p_woodenStake, string* p_itemManipulated, int*p_story,string* p_chosenCharacter);
void inventory(string* p_inventorySlot1, string* p_inventorySlot2, string* p_inventorySlot3, string* p_itemManipulated);
void useInventory(string* p_inventorySlot1, string* p_inventorySlot2, string* p_inventorySlot3, string* p_itemManipulated);
void chooseACharacter(string* p_lionel, string* p_luther, string* p_nemiel, string* p_oliviya, string* p_chosenCharacter, int* p_firstDie);
void battleTheVampire(int* p_cross, int* p_woodenStake, int* p_story, string* p_itemManipulated);


//Main Program
int main()
{
	//Variables
	int story = 2;
	int character = 0;
	int firstDie = 0;
	int inventorySlotIsFull = 0;
		//Characters
	string lionel = "Lionel Johnson ";
	string luther = "Azrael Luther ";
	string nemiel = "Nemiel Uzziel ";
	string oliviya = "Oliviya Nemean ";
	string userName;
		//Inventory
	string itemManipulated;
	string inventorySlot1 = "Empty";
	string inventorySlot2 = "Empty";
	string inventorySlot3 = "Empty";
		//Items
	int cross = 0;
	int woodenStake = 0;
		//Common strings
	string YesOrNo;
	string invalid = "Invalid entry please try again.\n";
	string chosenCharacter;


	//Pointers
	int* p_story = &story;
	string* p_YesOrNo = &YesOrNo;
	string* p_invalid = &invalid;
	string* p_chosenCharacter = &chosenCharacter;
	int* p_firstDie = &firstDie;
	string* p_itemManipulated = &itemManipulated;
	int* p_inventorySlotIsFull = &inventorySlotIsFull;
		//Pointers-Items
	int* p_cross = &cross;
	int* p_woodenStake = &woodenStake;
		//pointers-Inventory slots
	string* p_inventorySlot1 = &inventorySlot1;
	string* p_inventorySlot2 = &inventorySlot2;
	string* p_inventorySlot3 = &inventorySlot3;

		//pointers-Characters
	string* p_lionel = &lionel;
	string* p_luther = &luther;
	string* p_nemiel = &nemiel;
	string* p_oliviya = &oliviya;
	string* p_userName = &userName;


	//Story strings
	string EntranceToKingsBridge = ",you stand at the enterance to Kings bridge. Little more than a borken iron gate.\nThe night is dark and fog fills the air as the full moon illuminates from above.\nIn the town square you see an indistinct person. Will you approach?\n";

	//***Main Game***
		//Intro
	cout << "\n\n\t\t\t***Inventory systems with pointers***\n\n\n";
	cout << "In this game you play as an investigator who has just been assigned to look into some grisly murders in the small town of King Bridge.\n";
	cout << "Your choices will influence what items you find.\nGood luck\n";
//Get username
	name(p_userName);
	//Story starts
	if (story > 0)
	{
		while (story == 2)
		{
			cout << userName << EntranceToKingsBridge;
			YOrN(p_YesOrNo, p_invalid);
			dieRoll(p_firstDie);
			chooseACharacter(p_lionel, p_luther, p_nemiel, p_oliviya, p_chosenCharacter, p_firstDie);
			YOrNEntranceToKingsBridge(p_YesOrNo, p_invalid, p_cross, p_woodenStake, p_itemManipulated, p_story, p_chosenCharacter);
			inventory(p_inventorySlot1, p_inventorySlot2, p_inventorySlot3, p_itemManipulated);

		}
		while (story == 3)
		{
			battleTheVampire(p_cross, p_woodenStake, p_story, p_itemManipulated);
			useInventory(p_inventorySlot1, p_inventorySlot2, p_inventorySlot3, p_itemManipulated);
			story = 0;
		}
	}
	
	return 0;
}


//Roll dice function
	//passing in the information at the memory adress of firstdie.
void dieRoll(int* p_firstDie)
{
	int ran;
	//derefrencing the pointer to change the actual value-this idea repeats throughout code.
	*p_firstDie = 0;
	srand(time(NULL));
	ran = rand() % 4 + 1;
	*p_firstDie = ran;
	//cout << "You rolled a " << ran << "." << endl;

}
//Choose a character at random
	//passing in the information at the memory adress'.
void chooseACharacter(string* p_lionel, string* p_luther, string* p_nemiel, string* p_oliviya, string* p_chosenCharacter, int* p_firstDie)
{
	//derefrencing the pointers to change the actual value then setting the variable chosenCharacter equal to the name of the chosen character 
	if (*p_firstDie == 1) 
	{
		*p_chosenCharacter = *p_lionel;
	}
	else if (*p_firstDie == 2)
	{
		*p_chosenCharacter = *p_luther;
	}
	else if (*p_firstDie == 3)
	{
		*p_chosenCharacter = *p_nemiel;
	}
	else
	{
		*p_chosenCharacter = *p_oliviya;
	}
}
//Get username
void name(string* p_userName)
{
	cout << "Please enter your name.\n";
	cin >> *p_userName;
}
//Get yes or no
void YOrN(string* p_YesOrNo, string* p_invalid)
{
	//loop that repeats until user enters 'y' or 'n'
	int end = 0;
	while (end == 0)
	{
		cout << "Enter \'Y\' for yes or \'N\' for no.\n";
		cin >> *p_YesOrNo;


		if (*p_YesOrNo == "y" || *p_YesOrNo == "Y")
		{
			cout << "You chose yes\n";
			//++end;
		}
		else if (*p_YesOrNo == "n" || *p_YesOrNo == "Y")
		{
			cout << "You chose no\n";
			//++end;
		}
		else
		{
			cout << *p_invalid;
		}
	}
}
//Assign inventory item
void inventory(string* p_inventorySlot1, string* p_inventorySlot2, string* p_inventorySlot3, string* p_itemManipulated) 
{
	//Find an empty slot and change the name to the item being added
	if (*p_inventorySlot1 == "Empty") 
	{
		*p_inventorySlot1 = *p_itemManipulated;
	}
	else if (*p_inventorySlot2 == "Empty")
	{
		*p_inventorySlot2 = *p_itemManipulated;
	}
	else if (*p_inventorySlot3 == "Empty")
	{
		*p_inventorySlot3 = *p_itemManipulated;
	}
	else
	{
		cout << "Your inventory is full. Use or drop an item before picking up " << *p_itemManipulated << ".\n";
	}
}
//use inventory item
void useInventory(string* p_inventorySlot1, string* p_inventorySlot2, string* p_inventorySlot3, string* p_itemManipulated)
{
	//look for item being used-if found change slot to empty
	if (*p_inventorySlot1 == *p_itemManipulated)
	{
		*p_inventorySlot1 = "Empty";
		cout << "slot1 removed\n";
	}
	else if (*p_inventorySlot2 == *p_itemManipulated)
	{
		*p_inventorySlot2 = "Empty";
		cout << "slot2 removed\n";
	}
	else if (*p_inventorySlot3 == *p_itemManipulated)
	{
		*p_inventorySlot3 = "Empty";
		cout << "slot3 removed\n";
	}
	else
	{
		cout << "You lack the required item\n";
	}
}
//Entrance to kingsBridge: yes appoarch / no wander streets looking for address you were given
void YOrNEntranceToKingsBridge(string* p_YesOrNo, string* p_invalid, int* p_cross, int* p_woodenStake, string* p_itemManipulated, int* p_story,string* p_chosenCharacter)
{
	cout << "entrance\n";
	if (*p_YesOrNo == "y" || *p_YesOrNo == "Y")
	{
		cout << *p_chosenCharacter<<"gives you a cross\n";
		++*p_cross;
		*p_itemManipulated = "A Large ornate cross";
		*p_story = 3;
		
	}
	else
	{
		cout << "wandering the streets you find a wooden stake\n";
		++*p_woodenStake;
		*p_itemManipulated = "A simple wooden steak";
		*p_story = 3;
	}
}
//Battle a vampire based on which weapon you found
void battleTheVampire(int* p_cross, int* p_woodenStake, int* p_story, string* p_itemManipulated)
{
	if (*p_cross == 1)
	{
		cout << "You hold the cross out before you. The vampire hisses and flees.\n";
		cout << "The energy in the cross fades and the relic crumbles in your grasp\n";
		*p_itemManipulated = "A Large ornate cross";
	}
	else if (*p_woodenStake == 1)
	{
		cout << "You lunge at the vampire, plunging the stake deep into it's chest. The vampire crumbles into dust.\n";
		cout << "Your stake is gane with the vampire\n";
		*p_itemManipulated = "A simple wooden steak";
	}
	else
	{
		cout << "The vampire strikes and drinks your blood.\n";
		*p_story = 1;
	}
}
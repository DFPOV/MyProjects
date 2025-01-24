from room import Room
from item import Item
from character import Character
from character import Enemy
import time
import webbrowser

# info of rooms
container = Room("Container")
white_parish = Room("White Parish")
cliff_village = Room("Cliff Village")
witchs_forest = Room("Witch's Forest")
catacomb = Room("Catacomb")
dungeon = Room("Dungeon")
ruined_castle = Room("Ruined Castle")
forbidden_zone = Room("Forbidden Zone")
abyss = Room("Abyss")
frontier = Room("Frontier")

#link rooms
container.link_room(white_parish,"east")
white_parish.link_room(container,"west")
white_parish.link_room(cliff_village,"north")
white_parish.link_room(witchs_forest,"south")
cliff_village.link_room(white_parish,"south")
cliff_village.link_room(ruined_castle,"east")
cliff_village.link_room(catacomb,"south")
witchs_forest.link_room(white_parish,"west")
witchs_forest.link_room(dungeon,"east")
catacomb.link_room(cliff_village,"north")
ruined_castle.link_room(cliff_village,"west")
dungeon.link_room(witchs_forest,"west")
dungeon.link_room(frontier,"east")
dungeon.link_room(forbidden_zone,"south")
forbidden_zone.link_room(dungeon,"north")
forbidden_zone.link_room(abyss,"south")
abyss.link_room(forbidden_zone,"north")
frontier.link_room(dungeon,"wast")

#set room description
container.set_room_description("You wake up from this container and find that the world around you has been contaminated by the rain of death.")
white_parish.set_room_description("People who witnessed the purifying miracle of the white witch began to believe in the white witch. \nThese people were called the White Church, and the White Parish was born.")
cliff_village.set_room_description("The largest village of the Borderlands, it is also the birthplace of the Spring White Witch. \nThere were no survivors after the rain of death.")
witchs_forest.set_room_description("The Association of Magicians was founded by magic genius Elaine so that she could help her best friend the Spring White Witch. \nNow drowned by the rain of death.")
catacomb.set_room_description("The White Church use this Ancient people's grave as the place they trains the guards of White Witch. \nOnly the top warriors can directly escort the White Witch. \nCatalyzed by the rain of death, it has become a gathering place for a large number of filth.")
ruined_castle.set_room_description("Once the capital of the Borderlands, it was the birthplace of the Wind White Witch. \nUnder the influence of the rain of death, this place is now rusty.")
dungeon.set_room_description("The stronghold of the Dark Side. \nSoldiers who have devoted their lives to their country cannot withstand the erosion of the rain of death, and they cannot rest in peace after a busy life.")
forbidden_zone.set_room_description("The genius magician Faten was assigned by the king to this place to study filth. \nHis assistant and lover Miriel became filth by inhaling too much filth in the forbbiden zone. \nThe birth of the elixir came from the treatment of Miriel.")
frontier.set_room_description("Not eroded by the rain of death, leave the Borderlands and there's no more threat of filth")

#create items
umbral_knight = Item("Umbral Knight")
umbral_knight.set_item_description("A black-garbed knight awakened from a deep slumber. \nThough naught but a Blighted Spirit, they still retain some semblance of who they once were. \nUmbral Knight needs to know enemies weakness in order to defeat them.")
umbral_knight.set_situation()
umbral_knight.set_type('Weapon')

ancient_souls = Item("Ancient Souls")
ancient_souls.set_item_description("A weapon forged by ancient ancestors.\n The spirit on it will guide Lily through her journey.\nYou don't have to know enemies weakness in order to kill them.")
ancient_souls.set_type('Weapon')

headdress = Item("Colorful feather headdress")
headdress.set_item_description("Siegrid's sister Silva sent a gift to her beloved sister, \nbut Siegrid never brought it once because of jealousy caused by a strong sense of responsibility.")
headdress.set_type("Remain")

giant_ring = Item("The giant's ring")
giant_ring.set_item_description("The old warrier refused to be purify because he did not want to increase the burden on the white witch, \nthe ring is used to restrain the filth.")

letter = Item("Letter from Siegrid")
letter.set_item_description("Siegrid's letter to Silva, referring to a headdress sent by his sister and lying to her that he liked it.")

item_list = []
item_list.append(umbral_knight)
item_list.append(ancient_souls)
item_list.append(headdress)
item_list.append(giant_ring)
item_list.append(letter)

#create characters
#feedback: True means wants to fight
Siegrid = Enemy("Siegrid, the Gurdian", "\nThe gurdian of Lily, she is jealous of her sister Silva because she was not chosen to be the White Witch's guard")
Siegrid.set_conversation("CURSH, CURSH, CURSH, CURSH, CURSH")
Siegrid.set_weakness("wings without bones")
Siegrid.set_feedback(True)
Siegrid.set_link_item(headdress)

Gerrod = Enemy("Gerrod, the Elder Warrior", "\nThe cliff Village's greatest warrior, who used to fought together with Spring White Witch.\nDrank the elix of the undead, and volunteered to become the Knight of the Undead to protect the country, but was ostracized as a monster when he returned.")
Gerrod.set_conversation("Put me out of my misery, the new white witch.")
Gerrod.set_weakness("back")
Gerrod.set_feedback(True)
Gerrod.set_link_item(giant_ring)

Silva = Enemy("Silva, the Gurdian of Spring White Witch", "\nSiegrid's sister, \nin order not to let the beloved sister in danger, she volunteered to become the guardian of the white witch, \nthe biggest wish in the heart is to see the Siegrid again.")
Silva.set_conversation("Let me meet my sister in heaven.")
Silva.set_weakness("wings without feather")
Silva.set_feedback(True)
Silva.set_link_item(letter)

Honier = Enemy("Honier, Keeper Of The Abyss", "\nHonier, the leader of the Dark Side, guarding the nation from the shadows.")
Honier.set_conversation("I'm sorry to trouble you.")
Honier.set_weakness("legs")
Honier.set_feedback(True)
Honier.set_link_item(ancient_souls)

Lord_of_filth = Character("Lord of filth, the polluted Spring White Witch", "\nThe Spring White Witch, who purged the excess of filth in the battle against the King of Filth, \nfinally could not stand the filth. \nWhen she was studied in the forbidden zone's laboratory, filth took root and the rain of death fell.")
Lord_of_filth.set_conversation("At least you have to be safe, Lily, my last child...")
Lord_of_filth.set_weakness("a mother's love")
Lord_of_filth.set_feedback("I won't let you purify me, my child. You have plenty of time and opportunity. Go, I will finish myself.")
Lord_of_filth.set_link_item(None)

#set characters in rooms
white_parish.set_character(Siegrid)
cliff_village.set_character(Gerrod)
catacomb.set_character(Silva)
dungeon.set_character(Honier)
abyss.set_character(Lord_of_filth)

#setting at the begining 
current_room = container
current_equipment = umbral_knight
goal = False

#operation1: fight
def fight_process(self, current_room, equipment):
    will = input("Do you want to run away from " + self.name + "? (yes or no)\n")
    if (will == "no"):
        position = input("\nWhere do you want to hit?\n")
        result = self.fight(position, equipment)
        if (result == True):
            print("Goodnight " + self.name + ". The area is clear now.\n")
            time.sleep(1)
            current_room.kill_character()
            if (self.item is not None):
                print(self.item.name + " gained!")
                self.item.set_situation()
        else:
            print("You killed by " + self.name + ". Respawning.")
    else:
        print("\nYou escaped!")
        time.sleep(1)

#operation2: move
def move_process(self):
    self.play_room_info()
    command = input("> ")
    current_room = self.move(command)
    print("\nCurrent location: " + current_room.name)
    time.sleep(1)
    return current_room

#operation3: talk
def talk_process(self):
    print("\nYou try to talk to " + self.name + "\n")
    time.sleep(1)
    if (self.feedback is not True):
        print("\n" + self.name + ": " + self.feedback)
        time.sleep(1)
        return False
    else: 
        print("\n" + self.name + " just want to fight! Embrace the glory of battle!\n")
        time.sleep(1)
        return True

#operation4: check backpack and change weapon
def check_backpack(equiped):
    item_cheklist = []
    print("\nHere's you backpack\n")
    time.sleep(1)
    check = True
    current_equipment = equiped
    while check:
        item_cheklist = []
        i = 0
        for Item in item_list:
            if Item.gained is True:
                i += 1
                print(str(i) + ": " + Item.name)
                item_cheklist.append(Item)
        if (i == 0):
            print("Nothing here yet!")
        print()
        time.sleep(1)
        result = input("What do you want to do? Enter item index to check item or 'quit' to quit backpack.\n")

        try:
            result = int(result)
        except: 
            None
        if (type(result) == int):
            result -= 1
            if (item_cheklist[result] is not None):
                print("\nItem Name: " + item_cheklist[result].name + "\n")
                time.sleep(1)
                print("Description: " + item_cheklist[result].description + "\n")
                time.sleep(1)
                print("Type: " + item_cheklist[result].type + "\n")
                time.sleep(1)
                
                #equip section: you can't equip files
                if ((item_cheklist[result].get_type() is 'Weapon') and (equiped is not item_cheklist[result]) ):
                    order = input("Do you want to equip it? 'yes' or 'no'\n")
                    if (order == "yes"):
                        current_equipment = item_cheklist[result]
                        print("\n" + current_equipment.get_item_name() + " equiped. \n")
                    else:
                        print("Operation cancelled\n")
                else:
                    if (equiped == item_cheklist[result]):
                        print("You already equiped this item.\n")
                        time.sleep(1)
                    else:
                        print("You can't equip this item.\n")
                        time.sleep(1)
            input("\nPress Enter to continue.\n")
        elif(result == "quit"):
            check = False
        else:
            print("\nInvalid operation.\n")
            input("\nPress Enter to continue.\n")
        
    time.sleep(1)
    input("\nPress Enter to continue.\n")
    return current_equipment

print("You wake up in a strange container.\n")
time.sleep(1)

#game section
while (not goal):
    print()
    inhabitant = current_room.get_character()
    if inhabitant is not None:
        print("But somebody is standing inside the room...\n")
        time.sleep(1)
        input("Press Enter to continue...\n")
        inhabitant.describe_character()
        print("")
        result = input("What do you want to do? 'talk' or 'fight'?\n")
        print("")
        if (result == "fight"):
            fight_process(inhabitant, current_room, current_equipment)
        elif (result == "talk"):
            fight_or_not = talk_process(inhabitant)
            if (inhabitant == Lord_of_filth):
                    print("\nFinally, everyone's grave is finished.\n")
                    time.sleep(2)
                    print("In the end, the girl thanks you, in this collapsed world.\n")
                    time.sleep(2)
                    print("You accompanied her to go through this journey.\n")
                    time.sleep(2)
                    print("C end: Collapse world")
                    time.sleep(5)
                    webbrowser.open("https://www.youtube.com/watch?v=et7QuZPSC_U&t=3s")
                    quit(0)
            if (fight_or_not == True):
                fight_process(inhabitant, current_room, current_equipment)
        else: 
            print("What have you entered?\nNow " + inhabitant.name + " just want to fight with you!\n")
            fight_process(inhabitant, current_room, current_equipment)

    if (abyss.character == None):
        print("The purification was stopped by Lily.\n")
        time.sleep(2)
        print("'I can't let you face the filth along.' Lily said\n")
        time.sleep(2)
        print("'Being as one, we shall never be apart.'\n")
        time.sleep(2)
        print("In the end, Lily stayed with her mother, face the filth together.\n")
        time.sleep(1)
        print("B end: Being as one")
        quit(0)

    if (current_room == frontier):
        will = input("Do you want to cross the borderline? 'yes' or 'no'\n")
        if (will == "yes"):
            print("The filth is still in the abyss,\n")
            time.sleep(2)
            print("the problem has not been eradicated,\n")
            time.sleep(2)
            print("and one day the filth will spread to the whole continent.\n")
            time.sleep(2)
            print("A end: Abyss")
            quit(0)
        else:
            continue        
            
    print("")
    current_room = move_process(current_room)

    result = input("\nDo you want to check your backpack?'yes' or 'no'\n")
    if (result == "yes"):
        current_equipment = check_backpack(current_equipment)
    else:
        print("\nFine.")
        time.sleep(1)
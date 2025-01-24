import time
class Character:
    def __init__(self, char_name, char_description):
        self.name = char_name
        self.description = char_description
        self.conversation = None
        self.feedback = None
        self.item = None

    #getter for character
    def get_character(self):
        return self.name

    #setter for conversation
    def set_conversation(self, conversation):
        self.conversation = conversation

    #getter and setter for conversation's feedback
    def set_feedback(self, feedback):
        self.feedback = feedback

    def get_feedback(self):
        return self.set_feedback

    #getter and setter for weakness
    def get_weakness(self):
        return self.weakness

    def set_weakness(self, weakness):
        self.weakness = weakness

    #getter and setter for items on characters
    def set_link_item(self, item):
        self.item = item

    def get_link_item(self):
        return self.item
    
    #describe character
    def describe_character(self):
        print("Name: " + self.name)
        print("")
        time.sleep(1)
        print("Description: " + self.description)
        print("")
        time.sleep(1)
        print("Weakness: " + self.weakness)
        print("")
        time.sleep(1)
        print(self.name + ": " + self.conversation)
        time.sleep(1)        
    
    #component1 for operation
    def fight(self, position, equipment):
        print("")
        print(equipment.get_item_name() + " hits " + self.name + "'s " + str(position)  + " so hard.\n")    
        if (equipment.get_item_name() == "Ancient Souls"):
            print("The ancient souls guide the filth to rest. Rest in peace, " + self.name + "\n")
            return True
        elif (position == self.weakness):
            time.sleep(1)
            return True
        else:
            print("")
            time.sleep(1)         
            print(self.name + " crushed you!")
            return False

class Enemy(Character):
    def __init__(self, char_name, char_description):
        super().__init__(char_name, char_description)
        self.weakness = None
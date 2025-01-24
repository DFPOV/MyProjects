from item import Item

class Room:
    
    def __init__(self, room_name):
        self.name = room_name
        self.description = None
        self.linked_rooms = {}
        self.character = None

    #set description for room
    def set_room_description(self,description):
        self.description = description

    #describe room
    def describe_room(self): 
        print(self.description)

    #getter for room name
    def get_room_name(self):
        return self.name

    #getter and setter for character in the room
    def set_character(self, character):
        self.character = character
    
    def get_character(self):
        return self.character
    
    #room that linked
    def link_room(self, room_to_link, direction):
       self.linked_rooms[direction] = room_to_link

    #get room details
    def get_room_details(self):
        for direction in self.linked_rooms:
            room = self.linked_rooms[direction]
            print("The direction of " + room.get_room_name() + " is: " + direction)
    
    #delete character after dead
    def kill_character(self):
        self.character = None

    #describe the room
    def play_room_info(self):
        print("The " + self.name)
        print("------------------")
        self.describe_room()
        print()
        self.get_room_details()

    #component1 of operation
    def move(self, direction):
        if direction in self.linked_rooms:
            return self.linked_rooms[direction]
        else:
            print("You can't go that way")
            return self
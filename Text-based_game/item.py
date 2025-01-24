class Item:

    def __init__(self, item_name):
        self.name = item_name
        self.description = None
        self.gained = False
        self.type = None

    #getter and setter for item's description
    def set_item_description(self, description):
        self.description = description

    def get_item_description(self):
        return self.description

    #getter for item's name
    def get_item_name(self):
        return self.name
    
    #getter and setter for equipement's situation
    def set_situation(self):
        self.gained = True

    def get_situation(self):
        return self.gained
    
    #getter and setter for item
    def set_type(self, type):
        self.type = type

    def get_type(self):
        return self.type
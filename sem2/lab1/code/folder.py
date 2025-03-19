from file import *
from system_object import *
class Folder(SystemObject):
    states = ['not_archived', 'archived']
    
    def __init__(self, folder_name: str) -> None:
        self.name=folder_name
        self.machine = Machine(model=self, states=Folder.states, initial='not_archived',ignore_invalid_triggers=True)
        self.machine.add_transition(trigger='ZIP', source='not_archived', dest='archived', after='archiving')
        self.machine.add_transition(trigger='UNZIP', source='archived', dest='not_archived', after='unzipping')
        self.folders: list["Folder"]=list()
        self.files: list["File"]=list()
        self._memmory_consumption=0  
        
    def delete(self, object_name)->None:
        if object_name[-4]==".":
            del_object=self.file_search(object_name)
            self._memmory_consumption-=del_object._memmory_consumption
            self.files.remove(del_object)
        else:
            del_object=self.folder_search(object_name)
            self._memmory_consumption-=del_object._memmory_consumption            
            self.folder.remove(del_object)       
        
    def archiving(self):
        self._memmory_consumption=self._memmory_consumption/2
        
    def unzipping(self):
        self._memmory_consumption=self._memmory_consumption*2    
        
    def add(self, add_object)->None:
        if not (isinstance(add_object, File) or isinstance(add_object, Folder)):
            raise TypeError("В папку добавляется не файл и не папка")
        self.UNZIP()
        if isinstance(add_object, File):
            if not self.file_search(add_object.name):
                self.files.append(add_object)
                self._memmory_consumption+=add_object._memmory_consumption
            else:
                print("Такое имя уже есть")
        else:
            if not self.folder_search(add_object.name):
                self.folders.append(add_object)
                self._memmory_consumption+=add_object._memmory_consumption
            else:
                print("Такое имя уже есть")                
    def show(self):   
        print("Название папки:",self.name)
        SystemObject.show(self)    
        
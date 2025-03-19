from folder import *
class Disk(SystemObject):
    # Вынести отдельно проверку на оставшуюся память и включить в логику пользователя
    def __init__(self, name: str, memmory:int) -> None:
        if not (type(name)==str and type(memmory)==int):
            raise TypeError("В диск переданы не правильные аргуменьы")
        self.name=name
        self.folders: list["Folder"]=list()
        self.files: list["File"]=list()
        self.memmory=memmory
        
    def add(self, add_object)->None:
        if not (isinstance(add_object, File) or isinstance(add_object, Folder)):
            raise TypeError("В диск добавляется не файл и не папка")
        if isinstance(add_object, File):
            if not self.file_search(add_object.name):
                self.files.append(add_object)
                self.memmory-=add_object._memmory_consumption
        else:
            if not self.folder_search(add_object.name):
                self.folders.append(add_object)  
                self.memmory-=add_object._memmory_consumption
                
    def delete(self, object_name)->None:
        if object_name[-4]==".":
            del_object=self.file_search(object_name)
            self.memmory+=del_object._memmory_consumption
            self.files.remove(del_object)
        else:
            del_object=self.folder_search(object_name)
            self.memmory+=del_object._memmory_consumption            
            self.folders.remove(del_object)     
            
    def show(self):   
        print("Название диска:",self.name)
        print("Осталось памяти", self.memmory)
        SystemObject.show(self) 
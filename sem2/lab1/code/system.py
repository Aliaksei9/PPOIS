from disk import *
class System:
    def __init__(self, dict_disks: dict, pas:int):
        if not type(dict_disks)==dict:
            raise TypeError("В систему передан не словарь")
        self.disks:["Disk"]=list()
        for i in dict_disks:
            if not(type(i)==str and type(dict_disks[i]))==int:
                raise ValueError('В словаре использущимся при инициализации системы неправильные значения')
            self.disks.append(Disk(i, dict_disks[i]))
        self.password=pas
            
    def search_disk(self, disk_name: str)-> Disk:
        for disk in self.disks:
            if disk.name==disk_name:
                return disk
        return False

    def add_disk(self, name:str, memmory:int)->None:
        self.disks.append(Disk(name, memmory))
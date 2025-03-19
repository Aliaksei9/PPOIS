from system import *
import copy
class User:
    states = ['admin', 'user']
    
    def __init__(self, system: System) -> None:
        if not isinstance(system, System):
            raise TypeError("Пользователь не был иницииализирован в системе")
        self.machine = Machine(model=self, states=User.states, initial='user',ignore_invalid_triggers=True)
        self.machine.add_transition(trigger='sudo', source='user', dest='admin', conditions='sudo_password')
        self.system=system
        
    def sudo_password(self)->bool:
        if self.system.password:
            entered_password=int(input("Введите пароль"))
            return entered_password==self.system.password
        else:
            return True
    def unzipping(self, path=""):
        self.sudo()
        if self.state=="admin":
            if path=="":
                path=input("Введите абсолютный путь до Разархивируемой папки")    
            place_of_unzipping=self.path_parser(path)
            disk=self.disk_identifying(path)
            unzip_folder=place_of_unzipping.folder_search(path[path.rfind("\\")+1:])
            if unzip_folder:
                initially_occupying_memory=unzip_folder._memmory_consumption
                unzip_folder.UNZIP()
                disk.memmory-=unzip_folder._memmory_consumption-initially_occupying_memory 
            else:
                ValueError("Такой папки не существует")
    
    def disk_identifying(self, path:str)->Disk:
        slash_index = path.find("\\")
        disk_name=path[:slash_index]
        disk=self.system.search_disk(disk_name)
        if(disk==False):
            raise ValueError("Указанного диска не существует")    
        return disk
    
    #ВНИМАНИЕ. Парсер не обрабатывает последнюю часть пути, ибо нужда в её обработке зависит от того, используется ли парсер в добавлении файла/папки или в просмотре файла/папки
    def path_parser(self, path:str)->any:
        if not type(path)==str:
            raise TypeError
        slash_index = path.find("\\")
        object_name=path[:slash_index]
        last_object=self.system.search_disk(object_name)
        if(last_object==False):
            raise ValueError("Указанного диска не существует")
        path=path[slash_index+1:]
        number_slashes=path.count("\\")
        for i in range(0, number_slashes):
            slash_index = path.find("\\")
            object_name=path[:slash_index]
            path=path[slash_index+1:]
            if len(object_name)>3 and object_name[-4]=='.':
            # Тут пока удобней так, но если будут и другие форматы файлов то переписать на поиск . с конца строки
                raise TypeError("Файл не может быть переходной точкой в пути")
            else:
                last_object=last_object.folder_search(object_name)
            if last_object==False:
                raise ValueError("Неправильный путь")          
        return last_object
    
    def show(self, path=""):
        if path=="":
            path=input("Введите путь до объекта, который хотите просмотреть")
        auxiliary_object=self.path_parser(path)
        slash_index = path.rfind("\\")
        name=path[slash_index+1:]
        if name=="":
            raise ValueError("Пустое имя у просматриваемого объекта")        
        if len(name)>3 and name[-4]==".":
            file=auxiliary_object.file_search(name)
            op=int(input("Нажмите 1 чтобы открыть файл как jpg, 2 чтобы открыть как txt, 3 чтобы открыть как mp4 "))
            if op==1:
                file.view_picture()
            elif op==2:
                file.read_txt()
            elif op==3:
                file.watch_video()
            else:
                raise ValueError("Неправильно выбрана операция")
        else:
            folder=auxiliary_object.folder_search(name)
            folder.show()
    
    def create_object(self, path="")->None:
        self.sudo()
        if self.state=="admin":
            if path=="":
                path=input("Введите название(абсолютный путь) создаваемого объекта.")
            disk=self.disk_identifying(path)
            place_of_creation=self.path_parser(path)
            # Тоже работает только с моими форматами
            final_slash = path.rfind("\\")
            new_name=path[final_slash+1:]
            if new_name=="":
                raise ValueError("Пустое имя у создаваемого объекта")
            if new_name[len(new_name)-3:]=="txt":
                text=input("Введите текст")
                new_file=File(new_name[:-4], "txt", text)
                if isinstance(place_of_creation, Folder):
                    initially_occupying_memory=place_of_creation._memmory_consumption
                    place_of_creation.add(new_file)
                    disk.memmory-=place_of_creation._memmory_consumption-initially_occupying_memory
                else:
                    place_of_creation.add(new_file)
                    disk.memmory-=new_file._memmory_consumption
            elif new_name[len(new_name)-3:]=='jpg':
                quality=int(input("Введите качество картинки"))
                new_file=File(new_name[:-4], "jpg", quality)
                if isinstance(place_of_creation, Folder):
                    initially_occupying_memory=place_of_creation._memmory_consumption
                    place_of_creation.add(new_file)
                    disk.memmory-=place_of_creation._memmory_consumption-initially_occupying_memory
                else:
                    place_of_creation.add(new_file)              
            elif new_name[len(new_name)-3:]=='mp4':
                timing=int(input("Хронометраж"))
                new_file=File(new_name[:-4], "mp4", timing)
                if isinstance(place_of_creation, Folder):
                    initially_occupying_memory=place_of_creation._memmory_consumption
                    place_of_creation.add(new_file)
                    disk.memmory-=place_of_creation._memmory_consumption-initially_occupying_memory
                else:
                    place_of_creation.add(new_file) 
            else:
                place_of_creation.add(Folder(new_name))
            if disk.memmory<0:
                raise Exception("Закончилось место на диске")
        else:
            print("Недостаточно прав")
        
    def archiving(self, path=""):
        self.sudo()
        if self.state=="admin":
            if path=="":
                path=input("Введите абсолютный путь до архивируемой папки")   
            place_of_zipping=self.path_parser(path)
            disk=self.disk_identifying(path)
            zip_folder=place_of_zipping.folder_search(path[path.rfind("\\")+1:])
            if zip_folder:
                initially_occupying_memory=zip_folder._memmory_consumption
                zip_folder.ZIP()
                disk.memmory+=initially_occupying_memory-zip_folder._memmory_consumption 
            else:
                ValueError("Такой папки не существует")            
                
    def delete_object(self, path=""):
        self.sudo()
        if self.state=="admin":
            if path=="":
                path=input("Введите абсолютный путь до удаляемого объекта.")            
            place_of_delete=self.path_parser(path)
            disk=self.disk_identifying(path)
            # Тоже работает только с моими форматами
            del_name=path[path.rfind("\\")+1:]   
            if isinstance(place_of_delete, Folder):
                initially_occupying_memory=place_of_delete._memmory_consumption
                place_of_delete.delete(del_name)
                disk.memmory+=initially_occupying_memory-place_of_delete._memmory_consumption
            else:
                place_of_delete.delete(del_name)
        else:
            print("Недостаточно прав")
     
    def moving(self, path1="", path2=""):
        self.sudo()
        if self.state=="admin":           
            if not (path1 and path2):
                path1=input("Введите абсолютный путь до перемещаемого объекта.") 
                path2=input("Куда перемещать")  
            self.copying(path1, path2)
            self.delete_object(path1)
        else:
            print("Недостаточно прав")
            
    def copying(self, path1="", path2=""):
        self.sudo()
        if self.state == "admin":
            if path1 == "" and path2 == "":
                path1 = input("Введите абсолютный путь до копируемого объекта: ") 
                path2 = input("Введите путь, куда копировать: ") 
    
            disk = self.disk_identifying(path2)
            original_location = self.path_parser(path1)
            place_of_creation = self.path_parser(path2)
    
            original_object_name = path1[path1.rfind("\\") + 1:] 
            original_object = None  # Добавляем инициализацию переменной
    
            if original_object_name[-4:] == ".txt" or original_object_name[-4:] == ".mp4" or original_object_name[-4:] == ".jpg":
                original_object = original_location.file_search(original_object_name)
            else:
                original_object = original_location.folder_search(original_object_name)
    
            if not original_object:
                raise ValueError("Неправильный путь: объект не найден")
    
            copy_object = copy.deepcopy(original_object)
    
            if isinstance(original_object, File):  # Если копируем файл
                copy_object.name = path2[path2.rfind("\\") + 1:]   
                print(copy_object.name)
                if isinstance(place_of_creation, Folder):
                    initially_occupying_memory = place_of_creation._memmory_consumption
                    place_of_creation.add(copy_object)
                    disk.memmory -= place_of_creation._memmory_consumption - initially_occupying_memory
                else:
                    place_of_creation.add(copy_object)  # Исправлено (раньше было new_file)
            else:  # Если копируем папку
                copy_object.name = path2[path2.rfind("\\") + 1:]  
                if isinstance(place_of_creation, Folder):
                    disk.memmory -= copy_object._memmory_consumption
                place_of_creation.add(copy_object)
    
            if disk.memmory < 0:
                raise Exception("Закончилось место на диске")  
        else:
            print("Недостаточно прав")         
                    
        def view_disk(self, path=""):
            if path=="":
                path=input("Введите желаемый диск")
            disk=self.disk_identifying(path)
            disk.show()

            
            
            
            
            
                    
                    
                
        
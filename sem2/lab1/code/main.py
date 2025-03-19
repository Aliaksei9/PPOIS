from user import *
from save_unload import *
system=System({"C":100000},1234)
user=User(system)
def select_operation()->int:
    try:
        operation=int(input("""
            Выберите желаемую операци:
            1. Нажмите 1, чтобы добавить новый объект в систему
            2. Нажмите 2, чтобы удалить объект из системы
            3. Нажмите 3, чтобы копировать объект
            4. Нажмите 4, чтобы переместить объект
            5. Нажмите 5, чтобы архивировать папку
            6. Нажмите 6, чтоюы разархивировать папку
            7. Нажмите 7, чтобы просмотреть объект
            8. Нажмите 8, чтобы сохранить систему
            9. Нажмите 9, чтобы подключить к системе новый диск
            10. Нажмите 10, чтобы загрузить прошлую систему
            11. Нажмите 11, чтобы выйти из системы
        """))
        return operation
    except ValueError:
        raise ValueError("В операции должно быть численное значение")

def show_disks()->None:
    for disk in system.disks:
        disk.show()   
show_disks()
operation=0
while not operation==11:
    try:
        operation=select_operation()
        if operation==1:
            user.create_object()
        elif operation==2:
            user.delete_object()
        elif operation==3:
            user.copying()
        elif operation==4:
            user.moving()
        elif operation==5:
            user.archiving()
        elif operation==6:
            user.unzipping()
        elif operation==7:
            user.show()        
        elif operation==8:
            SaveUnload.save("main.pkl",system)
        elif operation==9:
            name=input("Введите имя нового диска")
            memmory=int(input("Введите память нового диска"))
            system.add_disk(name, memmory)        
        elif operation==10:
            system=SaveUnload.unload("main.pkl")
            user=User(system)
        elif operation == 11:
            pass
        else:
            raise ValueError("Неправильно выбрана операция")
    except Exception as error:
        print(error)   
    finally:
        show_disks()
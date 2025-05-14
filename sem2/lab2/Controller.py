from time import sleep

from Model import *
from View import *
class Controller:
    def __init__(self, model, view) -> None:
        self.model=model
        self.view=view
        self.view.set_callbacks(self.add, self.delete, self.find, self.correct_exit, self.new_xml, self.new_bz)
        self.view.update_table(self.model.teachers)
        
    def add(self, new_line: tuple[str, str, str, str, str, int])-> None:
        new_table_values, message_text=self.model.add(new_line)
        if not message_text:
            self.view.message("Успешно добавлена новая строка")
            self.view.update_table(new_table_values)
        else:
            self.view.message(message_text)

    def delete(self, del_conditions: list[str, str, str])-> None:
        new_table_values, deleted_lines=self.model.delete(del_conditions)
        result = '\n'.join(str(t) for t in deleted_lines)
        if deleted_lines:
            self.view.message(f"Успешно удалено {len(deleted_lines)} записей. Удалённые записи:\n{result}")
            self.view.update_table(new_table_values)
        else:
            self.view.message("Ничего не было удалено")
            
    def find(self, find_conditions: list[str, str, str])-> None:
        found_records=self.model.find(find_conditions)
        if(found_records):
            self.view.update_table(found_records, True)
        else:
            self.view.message("Ничего не было найдено")
            
    def correct_exit(self):
        self.model.correct_exit()
        self.view.wnd.destroy()
        
    def new_bz(self,path):
        txt=self.model.new_bz(path)
        if not txt:
            self.view.update_table(self.model.teachers)
        else:
            self.view.message(txt)
            sleep(2)
            self.view.wnd.destroy()
        
    def new_xml(self,path):
        txt=self.model.new_xml(path)
        if not txt:
            self.view.update_table(self.model.teachers)
        else:
            self.view.message(txt)
            sleep(5)
            self.view.wnd.destroy()
        
        
        
            
    
    
    
        
        
class SystemObject:
    def file_search(self, file_name:str):
        for file in self.files:
            if file.name==file_name:
                return file
        return False
    
    def folder_search(self, folder_name:str):
        for folder in self.folders:
            if folder.name==folder_name:
                return folder
        return False
    
    def show(self)->None:  
        print("Список файлов:")
        for file in self.files:
            print(file.name)
        print("Список вложенных папок:")
        for folder in self.folders:
            print(folder.name)
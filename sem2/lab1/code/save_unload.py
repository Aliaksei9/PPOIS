import pickle
from user import *
class SaveUnload:
    def save(file_name: str,save_object: any)->None:
        with open(file_name,"wb") as f:
            pickle.dump(save_object, f)
            
    def unload(file_name: str)-> any:
        with open(file_name, "rb") as f:
            return pickle.load(f)
        
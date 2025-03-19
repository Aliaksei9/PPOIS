from transitions import Machine
class File:
    states = ['jpg', 'txt', 'mp4']
    
    def __init__(self, file_name: str, format: str, format_info) -> None:
        if format=="jpg" and type(format_info)==int:
            initial_format='jpg'
            self.quality=format_info
            self._memmory_consumption=3*format_info
            self.name=file_name+".jpg"
        elif format=="mp4" and type(format_info)==int:
            initial_format='mp4'
            self.timing=format_info
            self._memmory_consumption=6*format_info
            self.name=file_name+".mp4"
        elif format=="txt" and type(format_info)==str:
            initial_format='txt'
            self.text=format_info
            self._memmory_consumption=len(format_info)
            self.name=file_name+".txt"
        else:
            raise ValueError('Неправильне данные при создании ')
        self.machine = Machine(model=self, states=File.states, initial=initial_format)
        self.machine.add_transition(trigger='change_to_jpg', source='*', dest='jpg', after='after_jpg_change')
        self.machine.add_transition(trigger='change_to_txt', source='*', dest='txt', after='after_txt_change')
        self.machine.add_transition(trigger='change_to_mp4', source='*', dest='mp4', after='after_mp4_change')      
           
    def after_jpg_change(self)-> None:
        if not hasattr(self, "quality"):
            self.quality=0
        self.name=self.name[:-3]+"jpg"
        
    def after_txt_change(self)-> None:
        if not hasattr(self, "text"):
            self.text=""
        self.name=self.name[:-3]+"txt"
        
    def after_mp4_change(self)-> None:
        if not hasattr(self, "timing"):
            self.timing=0
        self.name=self.name[:-3]+"mp4"
        
    def watch_video(self)-> None:
        self.change_to_mp4()
        if self.timing==0:
            print("Это не видео")
        else:
            print("Вы не работали", self.timing, "минут")
            
    def read_txt(self)-> None:
        self.change_to_txt()
        if self.text=="":
            print("Это не текстовый файл")
        else:
            print(self.text)
            
    def view_picture(self)-> None:
        self.change_to_jpg()
        if self.quality==0:
            print("Это не картинка")
        else:
            print("Вот это качество. Целых", self.quality, "пикселей. Всмысле их не надо было перемножать?")            
            
    
        
        
        
        
        
import sqlite3
from xml.dom import minidom
from TeacherHandler import *
class Model:
    def __init__(self):
        self.path="my_database.db"
        connection = sqlite3.connect(self.path)
        cursor = connection.cursor()
        self.xml=False
        
        # Создаем таблицу Users
        cursor.execute("""
        CREATE TABLE IF NOT EXISTS teachers (
            "Факультет" TEXT,
            "Название кафедры" TEXT,
            "ФИО преподавателя" TEXT,
            "Учёное звание" TEXT,
            "Учёная степень" TEXT,
            "Стаж работы" INTEGER
        )
        """)
        
        cursor.execute("SELECT * FROM teachers")
        self.teachers = cursor.fetchall()
        connection.close()


    def new_bz(self,path):
        if self.xml:
            self.xml_entry()
        else:
            self.bz_entry()
        self.xml = False
        self.path=path
        self.bz_reading()
        return self.check(self.teachers)

    def bz_reading(self):
        connection = sqlite3.connect(self.path)
        cursor = connection.cursor()
        cursor.execute("SELECT * FROM teachers")
        self.teachers = cursor.fetchall()
        connection.close()

    def check(self, values):
        for line in values:
            if (type(line[0])==str and type(line[1])==str and type(line[2])==str and  type(line[5])==int):
                if not ((line[3].startswith("Кандидат") or line[3].startswith("Доктор")) and line[3].endswith("наук")):
                    return "Возможными учёными степенями являются Кандидат наук и Доктор наук"
                if not (line[4] == "Доцент" or line[4] == "Профессор"):
                    return "Возможными учёными званиями являются Доцент и Профессор"
                if line[5]<0 or line[5]>100:
                    return "Слишком большой стаж. Ну или отрицательный"
                return ""
            else:
                return "Неправильные типы данных"

    def bz_entry(self):
        connection = sqlite3.connect(self.path)
        cursor = connection.cursor()

        # Очистка таблицы (удаление всех строк)
        cursor.execute("DELETE FROM teachers")

        # Вставка новых данных
        cursor.executemany("""
            INSERT INTO teachers (
                "Факультет",
                "Название кафедры",
                "ФИО преподавателя",
                "Учёное звание",
                "Учёная степень",
                "Стаж работы"
            ) VALUES (?, ?, ?, ?, ?, ?)
        """, self.teachers)

        # Сохраняем изменения
        connection.commit()

        # Закрываем соединение
        connection.close()

        
    def new_xml(self, path):
        if self.xml:
            self.xml_entry()
        else:
            self.bz_entry()
        self.xml=True
        self.path=path  
        self.xml_reading()
        return self.check(self.teachers)
    
    def xml_entry(self):
        # Создаём новый XML-документ
        doc = minidom.parse(self.path)
        root = doc.documentElement

        # Удаляем старые узлы
        while root.firstChild:
            root.removeChild(root.firstChild)

        # Теги в нужном порядке
        tags = ["Факультет", "Кафедра", "ФИО", "УчёнаяСтепень","УчёноеЗвание","Стаж"]
        
        # Добавляем преподавателей
        for t in self.teachers:
            prep_elem = doc.createElement("Преподаватель")
            for tag, value in zip(tags, t):
                tag_elem = doc.createElement(tag)
                tag_elem.appendChild(doc.createTextNode(str(value)))
                prep_elem.appendChild(tag_elem)
            root.appendChild(prep_elem)
        
        # Сохраняем в файл
        with open(self.path, "w", encoding="utf-8") as f:
            doc.writexml(f, encoding="utf-8", newl="\n", indent="  ")
                    
    def xml_reading(self):
        parser = xml.sax.make_parser()
        handler = TeacherHandler()
        parser.setContentHandler(handler)

        # Parse the XML file (ensure UTF-8 encoding if needed
        parser.parse(self.path)
        self.teachers=handler.teachers
    
    def add(self, new_line):
        txt=self.check([new_line])
        for t in self.teachers:
            if t[:5]==new_line[:5]:
                txt="Такой преподователь уже есть"
        if txt=="":
            self.teachers.append(new_line)
        return self.teachers, txt


    def delete(self, line):
        index=0
        deleted_lines=[]
        if line[0]=="ФИО преподавателя и/или наименование кафедры":
            if line[1]=="":
                for t in self.teachers:
                    if t[1]==line[2]:
                        deleted_lines.append(t)
                        del self.teachers[index]
                    index=index+1
            elif line[2]=="":
                for t in self.teachers:
                    if t[2]==line[1]:
                        deleted_lines.append(t)
                        del self.teachers[index]
                    index = index + 1
            else:
                for t in self.teachers:
                    if t[2] == line[1] and t[1]==line[2]:
                        deleted_lines.append(t)
                        del self.teachers[index]
                    index = index + 1
        elif line[0]=="Учёное звание и факультет":
            for t in self.teachers:
                if t[3] == line[1] and t[0] == line[2]:
                    deleted_lines.append(t)
                    del self.teachers[index]
                index = index + 1
        else:
            try:
                for t in self.teachers:
                    if t[5] > int(line[1]) and t[5] < int(line[2]):
                        deleted_lines.append(t)
                        del self.teachers[index]
                    index = index + 1
            except:
                pass
        return self.teachers, deleted_lines


    def find(self, line):
        found_teachers = []
        if line[0] == "ФИО преподавателя и/или наименование кафедры":
            if line[1] == "":
                for t in self.teachers:
                    if t[1] == line[2]:
                        found_teachers.append(t)
            elif line[2] == "":
                for t in self.teachers:
                    if t[2] == line[1]:
                        found_teachers.append(t)
            else:
                for t in self.teachers:
                    if t[2] == line[1] and t[1] == line[2]:
                        found_teachers.append(t)
        elif line[0] == "Учёное звание и факультет":
            for t in self.teachers:
                if t[3] == line[1] and t[0] == line[2]:
                    found_teachers.append(t)
        else:
            try:
                for t in self.teachers:
                    if t[5] > int(line[1]) and t[5] < int(line[2]):
                        found_teachers.append(t)
            except:
                pass
        return found_teachers

        
    def correct_exit(self):
        if self.xml:
            self.xml_entry()
        else:
            self.bz_entry()
        
        
    
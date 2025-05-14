from tkinter import *
from tkinter import filedialog
from tkinter import ttk
from tkinter.messagebox import *
from tkinter.ttk import Combobox

class ApplicationView:
    def __init__(self, table_values: list[(str,str,str,str,str,int)]="") -> None:
        self.table_val=table_values
        self.wnd=Tk()
        self.wnd.title("Таблица с данными")
        self.wnd.geometry("1920x700")
        self.wnd.resizable(False, False)
        self.set_vars()
        self.table_ref=self.table_creation(self.table_val, self.wnd)
        self.buttons_creation()
         
    def new_bz(self, file_path):
        self.bz_callback(file_path)
        
    def new_xml(self, file_path):
        self.xml_callback(file_path)
        
    def open_file(self):
        file_path = filedialog.askopenfilename(
            title="Выберите файл",
            filetypes=[("Все файлы", "*.*")]
        )
        
        if not file_path:
            return
    
        # Пробуем определить тип файла по содержимому
        with open(file_path, "rb") as f:
            header = f.read(16)
            if header.startswith(b"SQLite format 3\x00"):
                self.new_bz(file_path)
            elif b'<?xml' in header or b'<root' in header:
                self.new_xml(file_path)
            else:
                self.message("Файл или пустой или не является ни XML, ни SQLite.")  
    
    def table_creation(self, values: list[tuple[str, str, str, str, str,  int]], container, height=0, find=False) -> None:
        columns = ("Факультет", "Название кафедры", "ФИО преподователя", "Учёное звание", "Учёная степень", "Стаж")
        
        table_frame=Frame(container, bd=3, relief=GROOVE)
        table = ttk.Treeview(table_frame, columns=columns, show="headings")

        for col in columns:
            table.heading(col, text=col)
            table.column(col, anchor="center")
        
        table_frame.place(width=1920, height=500, y=height)
        
        table.pack(fill=BOTH, expand=True)
    
        # зона управления — кнопки снизу
        ctrl = Frame(table_frame)
        ctrl.pack(fill=X, pady=5)
        if not find:
            Button(ctrl, text="<< Первая", command=lambda: self.go_first(self.table_val, table)).pack(side=LEFT, padx=2)
            Button(ctrl, text="< Предыдущая",command=lambda: self.go_prev(self.table_val, table)).pack(side=LEFT, padx=2)
            Button(ctrl, text="Следующая >",command=lambda: self.go_next(self.table_val, table)).pack(side=LEFT, padx=2)
            Button(ctrl, text="Последняя >>",command=lambda: self.go_last(self.table_val, table)).pack(side=LEFT, padx=2)
        
            Label(ctrl, text="Записей на стр.:").pack(side=LEFT, padx=(20,2))
            self.per_page_var = IntVar(value=self.per_page)
            Entry(ctrl, textvariable=self.per_page_var, width=5).pack(side=LEFT)
            Button(ctrl, text="Обновить",command=lambda: self.change_per_page(self.table_val, table)).pack(side=LEFT, padx=10)

        else:
            Button(ctrl, text="<< Первая", command=lambda: self.go_first(self.find_result, table)).pack(side=LEFT, padx=2)

            Button(ctrl, text="< Предыдущая", command=lambda: self.go_prev(self.find_result, table)).pack(side=LEFT,
                                                                                                        padx=2)
            Button(ctrl, text="Следующая >", command=lambda: self.go_next(self.find_result, table)).pack(side=LEFT,
                                                                                                       padx=2)
            Button(ctrl, text="Последняя >>", command=lambda: self.go_last(self.find_result, table)).pack(side=LEFT,
                                                                                                        padx=2)


            Label(ctrl, text="Записей на стр.:").pack(side=LEFT, padx=(20, 2))
            self.per_page_var = IntVar(value=self.per_page)
            Entry(ctrl, textvariable=self.per_page_var, width=5).pack(side=LEFT)
            Button(ctrl, text="Обновить", command=lambda: self.change_per_page(self.find_result, table)).pack(side=LEFT,
                                                                                                            padx=10)
        
        self.page_info = Label(ctrl, text="")
        self.page_info.pack(side=RIGHT, padx=10)
        
        # отрисовка первой страницы
        self.update_view(values, table)
        return table
        
    def leaf_display(self):
        #Список словарей с информацией о каждом преподавателей
        teachers=list()
        for teacher in self.table_val:
            teachers.append({"Факультет":teacher[0],"Кафедра":teacher[1],"ФИО преподавателя":teacher[2],"Учёное звание":teacher[3],"Учёная степень":teacher[4],"Стаж работы":teacher[5]})
        node_ids = {
            'faculties': {},       # 'Название факультета' → id узла
            'departments': {},     # 'Название факультета' → { 'Название кафедры' → id узла }
        }        
        
        #Новое окошко
        self.leaf_window = Toplevel(self.wnd)
        self.leaf_window.title("Окно листового представления")
        self.leaf_window.geometry("900x400") 
        self.leaf_window.transient(self.wnd)
        self.leaf_window.grab_set()    
        
        self.leaf_tree = ttk.Treeview(self.leaf_window)
        self.leaf_tree.pack(fill='both', expand=True)    
        
        #Построение дерева: факультет → кафедра → преподаватель
        
        for t in teachers:
            fac = t['Факультет']
            dept = t['Кафедра']
        
            #Создаём узел факультета, если ещё нет
            if fac not in node_ids['faculties']:
                fid = self.leaf_tree.insert('', 'end', text=fac, open=False)
                node_ids['faculties'][fac] = fid
                node_ids['departments'][fac] = {}
            else:
                fid = node_ids['faculties'][fac]
        
            # 6.2 Создаём узел кафедры внутри факультета
            if dept not in node_ids['departments'][fac]:
                did = self.leaf_tree.insert(fid, 'end', text=dept, open=False)
                node_ids['departments'][fac][dept] = did
            else:
                did = node_ids['departments'][fac][dept]
        
            # 6.3 Добавляем лист (ФИО) внутри кафедры и сохраняем его инфо
            iid = self.leaf_tree.insert(did, 'end', text=t['ФИО преподавателя'], open=False)
            text_teacher = (
                f"Учёная степень: {t['Учёная степень']};  "
                f"Учёное звание: {t['Учёное звание']};  "
                f"Стаж работы: {t['Стаж работы']}; "
            )
            self.leaf_tree.insert(iid, 'end', text=text_teacher, open=False)
         
        
        Button(self.leaf_window, text="Выйти", width=15, height=2, command=self.leaf_window.destroy).pack(side=BOTTOM, fill='both', expand=True)              
        
        self.wnd.wait_window(self.leaf_window)  
    
    def change_per_page(self,values, table):
        new_val = int(self.per_page_var.get())
        if new_val>0 and new_val<24:
            self.per_page = new_val
            self.current_page = 1
            self.update_view(values, table)    
        else:
            self.message("Страниц не может быть меньше 0 и больше 23")                
    
    def get_total_pages(self, values):
        return max(1, (len(values) + self.per_page - 1) // self.per_page)
    
    def update_view(self, values, table):
        table.delete(*table.get_children())
        start = (self.current_page - 1) * self.per_page
        end = start + self.per_page
        for rec in values[start:end]:
            table.insert("", "end", values=rec)

        total_pages = self.get_total_pages(values)
        info_text = f"Страница {self.current_page} из {total_pages} | " \
            f"Записей на странице: {self.per_page} | " \
                    f"Всего записей: {len(values)}"
        self.page_info.config(text=info_text)

    def go_first(self, values, table):
        self.current_page = 1
        self.update_view(values, table)

    def go_prev(self, values, table):
        if self.current_page > 1:
            self.current_page -= 1
            self.update_view(values, table)
        else:
            self.message("Отрицательных страниц не существует ")  

    def go_next(self, values, table):
        if self.current_page < self.get_total_pages(values):
            self.current_page += 1
            self.update_view(values, table)
        else:
            self.message("Нельзя перейти на несуществующую старницу")              

    def go_last(self, values, table):
        self.current_page = self.get_total_pages(values)
        self.update_view(values, table)
    
    def add(self) -> None:
        try:
            self.add_callback((self.faculty.get(), self.department_name.get(), self.teachers_name.get(),  self.academic_title.get(), self.academic_degree.get(), self.work_experience.get()))
        except:
            self.message("Стаж должен быть числом")
        self.add_window.destroy()
        
    def set_callbacks(self, add_func, delete_func, find_func, exit_func, xml_func, bz_func) -> None:
        self.add_callback=add_func
        self.delete_callback=delete_func  
        self.find_callback=find_func    
        self.exit_callback=exit_func 
        self.xml_callback=xml_func
        self.bz_callback=bz_func
        self.wnd.protocol("WM_DELETE_WINDOW", self.exit_callback)        
            
    def new_add_window(self) -> None:
        # Создаём новое окно
        self.add_window = Toplevel(self.wnd)
        self.add_window.title("Окно добавления")
        self.add_window.geometry("900x400") 
        self.add_window.transient(self.wnd)
        self.add_window.grab_set()
    
        # Инструкция для пользователя
        Label(
            self.add_window,
            text="Правила добавления:\n"
                 "В каждое поле впишите информацию.\n"
                 "Возможные учёные звания: Кандидат наук, Доктор наук.\n"
                 "Возможные учёные степени: Доцент, Профессор.",
            justify=LEFT,
            wraplength=700
        ).pack(pady=10, fill=X)
    
        # Панель для полей ввода – растягивается по горизонтали и вертикали
        input_frame = Frame(self.add_window)
        input_frame.pack(pady=20, fill=BOTH, expand=True)
    
        # Настройка сетки внутри input_frame для растяжения второй колонки
        input_frame.columnconfigure(1, weight=1)
    
        # Список меток и переменных, которые должны быть заранее инициализированы как StringVar()
        fields = [
            ("Факультет", self.faculty),
            ("Название кафедры", self.department_name),
            ("ФИО преподавателя", self.teachers_name),
            ("Учёное звание", self.academic_title),
            ("Учёная степень", self.academic_degree),
            ("Стаж работы (лет)", self.work_experience)
        ]
    
        # Создаём поля ввода с метками – каждая надпись выравнивается по правому краю, поле ввода растягивается
        for i, (label_text, var) in enumerate(fields):
            Label(input_frame, text=label_text).grid(row=i, column=0, sticky="e", padx=10, pady=5)
            Entry(input_frame, textvariable=var, width=50)\
                .grid(row=i, column=1, sticky="ew", padx=10, pady=5)
    
        # Панель для кнопок – размещается в нижней части окна и растягивается по ширине
        button_frame = Frame(self.add_window)
        button_frame.pack(side=BOTTOM, pady=20, fill=BOTH)
    
        # Настройка сетки для равномерного распределения кнопок
        button_frame.columnconfigure(0, weight=1)
        button_frame.columnconfigure(1, weight=1)
    
        # Кнопка "Добавить" – растягивается по горизонтали в ячейке
        btn_add = Button(button_frame, text="Добавить", width=15, height=2, command=self.add)
        btn_add.grid(row=0, column=0, padx=10, pady=5, sticky="ew")
    
        # Кнопка "Выход" – растягивается по горизонтали в ячейке
        btn_exit = Button(button_frame, text="Выход", width=15, height=2, command=self.add_window.destroy)
        btn_exit.grid(row=0, column=1, padx=10, pady=5, sticky="ew")
    
        # Ожидание закрытия add_window перед продолжением кода
        self.wnd.wait_window(self.add_window)  
        
    def change(self, evt) -> None:
        if self.cb.get()=="ФИО преподавателя и/или наименование кафедры":
            self.txt1.set("ФИО преподавателя")
            self.txt2.set("Наименование кафедры")
        elif self.cb.get()=="Учёное звание и факультет":
            self.txt1.set("Учёное звание")
            self.txt2.set("Факультет")
        else:
            self.txt1.set("Нижний предел стажа работы")
            self.txt2.set("Верхний предел стажа работы") 
        
    def delete(self) -> None:
        self.delete_callback([self.cb.get(), self.input_txt1.get(), self.input_txt2.get()])

    def find(self) -> None:
        self.find_callback([self.cb.get(), self.input_txt1.get(), self.input_txt2.get()])
        
    def new_df_window(self) -> None:
        df_window = Toplevel(self.wnd)
        df_window.title("Окно")
        df_window.geometry("900x400")
        df_window.transient(self.wnd)
        df_window.grab_set()
    
        # Центральная панель (слева - комбобокс, справа - поля ввода)
        center_frame = Frame(df_window)
        center_frame.pack(fill=BOTH, expand=True, padx=20, pady=10)
    
        # === Слева: выпадающий список ===
        combobox_frame = Frame(center_frame)
        combobox_frame.pack(side=LEFT, fill=Y, padx=20)
    
        cb_values = [
            "ФИО преподавателя и/или наименование кафедры",
            "Учёное звание и факультет",
            "Стаж работы (верхний и нижний пределы)"
        ]
        
        self.txt1.set("ФИО преподавателя")
        self.txt2.set("Наименование кафедры")
    
        Label(combobox_frame, text="Выберите условие поиска:").pack(anchor="w")
        self.cb = Combobox(combobox_frame, state="readonly")
        self.cb.configure(values=cb_values)
        self.cb.current(0)
        self.cb.bind("<<ComboboxSelected>>", self.change)
        self.cb.pack(fill=X, pady=10)
    
        # === Справа: поля ввода ===
        input_frame = Frame(center_frame)
        input_frame.pack(side=RIGHT, fill=BOTH, expand=True)
    
        Label(input_frame, textvariable=self.txt1).grid(row=0, column=0, sticky="w", padx=10, pady=5)
        Entry(input_frame, textvariable=self.input_txt1, width=40).grid(row=0, column=1, sticky="ew", padx=10, pady=5)
    
        Label(input_frame, textvariable=self.txt2).grid(row=1, column=0, sticky="w", padx=10, pady=5)
        Entry(input_frame, textvariable=self.input_txt2, width=40).grid(row=1, column=1, sticky="ew", padx=10, pady=5)
    
        input_frame.columnconfigure(1, weight=1)
        # === Снизу: кнопки ===
        button_frame = Frame(df_window)
        button_frame.pack(side=BOTTOM, fill=X, pady=20)
    
        # Вложенный фрейм для выравнивания кнопок по центру
        inner_button_frame = Frame(button_frame)
        inner_button_frame.pack(anchor="center")  # Центрирование по ширине        
        return df_window, inner_button_frame


    def new_delete_window(self) -> None:
        self.delete_window, inner_button_frame = self.new_df_window()
        
        Button(inner_button_frame, text="Удалить", width=20, command=self.delete, height=2).pack(side=LEFT, padx=20)
        Button(inner_button_frame, text="Выход", width=20, command=self.delete_window.destroy, height=2).pack(side=LEFT, padx=20)

        # Ожидание закрытия окна
        self.wnd.wait_window(self.delete_window)
        
    def new_find_window(self) -> None:
        self.find_window, inner_button_frame  = self.new_df_window()
        
        self.find_window.geometry("1920x800")
        
        self.current_page = 1
        
        self.find_result=[]
        
        self.find_table=self.table_creation(self.find_result,self.find_window, 150, True)
        
        Button(inner_button_frame, text="Найти", width=20, command=self.find, height=2).pack(side=LEFT, padx=20)
        Button(inner_button_frame, text="Выход", width=20, command=self.find_window.destroy, height=2).pack(side=LEFT, padx=20)

        # Ожидание закрытия окна
        self.wnd.wait_window(self.find_window)        

    def set_vars(self) -> None:
        self.faculty=StringVar()
        self.department_name=StringVar()
        self.teachers_name=StringVar()
        self.academic_title=StringVar()
        self.academic_degree=StringVar()
        self.work_experience=IntVar()
        self.txt1=StringVar()
        self.txt2=StringVar()
        self.input_txt1=StringVar()
        self.input_txt2=StringVar()
        self.per_page = 10
        self.current_page = 1        
            
    def buttons_creation(self) -> None:
        self.buttons_frame=Frame(self.wnd, bd=3, relief=RAISED)
        self.buttons_frame.place(x=0, y=500, width=1920, height=200)
        
        self.button_add=Button(self.buttons_frame, text="Добавить", command=self.new_add_window, width=15, height=2)
        self.button_add.pack(side=LEFT, padx=10, pady=5, expand=True, fill=X)
        
        self.button_delete=Button(self.buttons_frame, text="Удалить", command=self.new_delete_window, width=15, height=2)
        self.button_delete.pack(side=LEFT, padx=10, pady=5, expand=True, fill=X)
        
        self.button_find=Button(self.buttons_frame, text="Найти", command=self.new_find_window, width=15, height=2)
        self.button_find.pack(side=LEFT, padx=10, pady=5, expand=True, fill=X)
        
        self.button_info=Button(self.buttons_frame, text="Отображение в виде древа", command=self.leaf_display, width=15, height=2)
        self.button_info.pack(side=LEFT, padx=10, pady=5, expand=True, fill=X)    
        
        self.button_info=Button(self.buttons_frame, text="Файл для сохранения", command=self.open_file, width=15, height=2)
        self.button_info.pack(side=LEFT, padx=10, pady=5, expand=True, fill=X)
        
        self.button_exit=Button(self.buttons_frame, text="Выйти", command=self.correct_exit, width=15, height=2)
        self.button_exit.pack(side=LEFT, padx=10, pady=5, expand=True, fill=X)        

    def correct_exit(self) -> None:
        self.exit_callback()

    def message(self, message) -> None:
        showinfo("Ошибка", message)
    
    def update_table(self, table_values: list[tuple[str, str, str, str, str, str, int]]=[], find=False) -> None:
        if not find:
            table_ref=self.table_ref
            self.table_val = table_values
        else:
            table_ref=self.find_table
            self.find_result=table_values
        self.current_page = 1
        self.update_view(table_values, table_ref)

    def run(self):
        self.wnd.mainloop()
            

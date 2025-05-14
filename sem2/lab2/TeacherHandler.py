import xml.sax

class TeacherHandler(xml.sax.ContentHandler):
    def __init__(self):
        super().__init__()
        self.teachers = []  # List to hold resulting tuples
        self.current_data = ''
        self.current_teacher = {}

    def startElement(self, name, attrs):
        # Called at the start of each element
        if name == 'Преподаватель':
            # Initialize storage for a new teacher
            self.current_teacher = {}
        # Track which tag we're inside
        self.current_data = name

    def characters(self, content):
        # Called for character data within an element
        if self.current_data in (
            'Факультет', 'Кафедра', 'ФИО',
            'УчёнаяСтепень', 'УчёноеЗвание', 'Стаж'
        ):
            text = content.strip()
            if text:
                # Accumulate text in case of multiple calls
                existing = self.current_teacher.get(self.current_data, '')
                self.current_teacher[self.current_data] = existing + text

    def endElement(self, name):
        # Called at the end of each element
        if name == 'Преподаватель':
            # Build tuple in the required order and append
            faculty = self.current_teacher.get('Факультет', '')
            department = self.current_teacher.get('Кафедра', '')
            fio = self.current_teacher.get('ФИО', '')
            degree = self.current_teacher.get('УчёнаяСтепень', '')
            title = self.current_teacher.get('УчёноеЗвание', '')
            try:
                experience = int(self.current_teacher.get('Стаж', '0'))
            except ValueError:
                experience = 0

            self.teachers.append(
                (faculty, department, fio, degree, title, experience)
            )
        # Reset current data tag
        self.current_data = ''
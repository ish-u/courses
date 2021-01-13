class Student:
    def __init__(self,name,subject_1,subject_2,subject_3):
        self.name = name
        self.subject_1 = subject_1
        self.subject_2 = subject_2
        self.subject_3 = subject_3
        self.average = (subject_1 + subject_2 + subject_3)/3
    
    def __del__(self):
        print('Deleting Object')
    
    def show(self):
        print(f'''
Name : {self.name}
Subject 1 : {self.subject_1}
Subject 2 : {self.subject_2}
Subject 3 : {self.subject_3}
Average : {self.average}
''')


def main():
    name = input("Name : ")
    sub1 = int(input("Subject 1 : "))
    sub2 = int(input("Subject 2 : "))
    sub3 = int(input("Subject 3 : "))
    student = Student(name,sub1,sub2,sub3)
    student.show()
    del student

if __name__ == "__main__":
    main()
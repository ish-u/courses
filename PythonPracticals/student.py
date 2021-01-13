class Student:
    def __init__(self,name,roll_no,year):
        self.name = name
        self.roll_no = roll_no
        self.year = year
    
    def __del__(self):
        print('Deleting Object',self.__str__())
    
    def __str__(self):
        return str(self.name + " " + self.roll_no + " " + self.year)



def main():
    Students = []
    while True:
        inp = str(input('> '))
        if inp == 'write':
            try:
                name = str(input("Name : "))
                year = str(input("Year : "))
                roll_no = str(input("Roll Number : "))
                s = Student(name,roll_no,year)
                Students.append(s)
            except TypeError:
                print("Invalid Input")
        elif inp == 'read':
            q = str(input('Enter Roll Number : '))
            for student in Students:
                if student.roll_no == q:
                    print(student)
        elif inp == 'delete':
            q = str(input('Enter Roll Number : '))
            for student in Students:
                if student.roll_no == q:
                    del student
        elif inp == 'exit':
            break

if __name__ == "__main__":
    main()
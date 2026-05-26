class Student:
    def study(self):
        print("studying")

class Teacher:
    def teach(self):
        print("teaching")

def main():
    student = Student()
    classroom = [Student(), Student(), Teacher(), Student(), Student()]

# 어떤 클래스의 instance인지 확인
    print(isinstance(student, Student))
    print(isinstance(student, int))
# 모든 python의 클래스는 object를 상속받음
    print(isinstance(student, object))

    print(isinstance(1, object))
    print(isinstance([1, 2, 3, student], object))

    for person in classroom:
        if isinstance(person, Student):
            person.study()
        if isinstance(person, Teacher):
            person.teach()
        person.study()
# AttributeError: 'Teacher' object has no attribute 'study'

if __name__ == "__main__":
    main()
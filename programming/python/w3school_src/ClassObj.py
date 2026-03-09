# define ClassA
class Person:
    ID = 0
    age = 0
    name = ""

    def __init__(myself, ID, age, name):  # like constructor
        myself.ID = ID
        myself.age = age
        myself.name = name

    def funInfo(myself):  # if using properties of class, func need self paramenter
        print("ID: " + str(myself.ID))
        print("name: " + str(myself.name))
        print("age: " + str(myself.age))


# Using ClassA
"""
objClassA1 = ClassA(4,5)
objClassA2 = ClassA(2,3)
objClassA1.x1 = 4
objClassA1.x2 = 6
print("objClassA1: " +str(objClassA1.funClassA1()))
print("objClassA2: " +str(objClassA2.funClassA1()))
"""


class Student(Person):
    MSSV = 0
    classNum = 0

    def __init__(self, ID, age, name, MSSV, classNum):
        # Person.__init__(self, ID, age, name)
        super().__init__(ID, age, name)
        self.MSSV = MSSV
        self.classNum = classNum

    def funIntroduce(self):  # self
        print("A student MSSV: " + str(self.MSSV))
        print("A student classNum: " + str(self.classNum))


std1 = Student(1, 39, "Harry", 1413091, 1)

std1.funIntroduce()
std1.funInfo()


# class Number
class Numbers:
    def __iter__(self):
        self.a = 1
        return self

    def __next__(self):
        if self.a <= 10:
            x = self.a
            self.a += 1
            return x
        else:
            raise StopIteration


classNum = Numbers()
iterNum = iter(classNum)  # iter an object

for i in iterNum:  # it auto run in a len of iter
    if i % 3 == 0:
        print(i)

### Example:
## mymodule.py
## In file: work.py. Import file by code:
## `import mymodule`
##  Using alias: `import mymodule as md`
## Import only something from mymodule. Code:
## `from mymodule import person1`
import platform

x = dir(platform)
print(x)

"""
# Module:
platform
datetime
json
Regular Expressions => import read
# try except:
try:
except:
"""

"""
#File handling:
w  write, create file
a  append, create file
r  read, error if file not exist
x  create file, error if file not exist

t text
b binary

f = open("file.txt","rt")
f.read()
f.read(5)
f.readline()
f.write() # a, w
f.close()
#remove file:
import os
if os.path.exists("file.txt"):
	os.remove("file.txt")
os.rmdir("myfolder")

"""

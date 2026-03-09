# variables...
print("Hello!")

if 1 > 2:
    print("Impossiple")
else:
    print("Maybe like that")

x = 5
x = "Hello , work"

# you do quite good. Let's effort! ^^

x, y, z = "Harry", "Ronnie", "Hermionie"
print(x)
print(y)
print(z)

a = b = c = "Hogwart"
print(a)
print(b)
print(c)

print("They used to study in " + a)
print(x + "," + y + "and" + z)

# function
a = 1
b = 1
c = "Hi!"


def myFun():
    global globalVar
    if a == b:
        globalVar = c + " Python is easy."
    else:
        globalVar = "What do you thing?"
    print(globalVar)


myFun()
print("They think: " + globalVar)

# data type
x = "Hello"
print(type(x))

x = 1.2e100
y = 12e5
z = 5e3
t = 1j

import random

print("Random number is " + str(random.randrange(2, 100)))
# Or we can use format() functioin

u = int(2.5)
print(u)

# string
x = """ I have been heard a symphony
Before all I heard was silient"""

print(x)

y = """Rhapsody for you and me
Every melody is timeless"""

print(y)
print(x[1])
print(y[7:12])
print(y[-2:-5])
print(len(x))
print(len(y))
print(x.strip())
# others: low(), upper()
print(x.replace("a", "i"))
if "melody" in y:
    print("Have melody")
elif "you" in y:
    print("Have you")
elif "me" in y:
    pass  # mean that do nothing


x = "I have {} computer and {} cat"
y = 1
z = 2
print(x.format(z, y))

# boool
print(1 > 2)
# false values
bool(False)
bool(None)
bool(0)
bool([])
bool(())
bool({})

# operators:
# python list: list, tuple, set, dictionaries
# list: list with negative index
x = ["fish", "fruit", "rice"]
x.insert(1, "vegetable")
print(x)
x.remove("fish")  # same: del
print(x)
x.pop()
print(x)
del x[0]  # or can use to delete a list
print(x)
# use clear to clear a list
y = x.copy()
z = list(x)
t = z + y
u = "vegetable"
t.append(u)
print(t)
v = "fish"
t.extend(v)  # add element
print(t)

# [list]
# (tuple) is list that we can not modify
# {set}: a collection that is not unorder and unindex. you can not change but you can:
#    add() or update() item
#    remove() or discard() item. If item does not exit discard will not raise error and remove() will raise error
#    you can pop(), clear(), del element or `set` list.
#    you can use union() or update() to join 2 list
# {dict}: unoderer, changable, indexed list
#    remove item by pop(itemkey) , or popitem() to remove the last item
#    you can clear(), del() list, you can del() list element
#    it can be like nested

dict = {"key": "value", "fish": "in the river"}

print(dict["key"])
print(dict.get("fish"))
dict["key"] = "key value"
print(dict)

for x, y in dict.items():
    print(x, y)
dict["fruit"] = "in tree"
print(dict)


list = """
#[list]
#(tuple) is list that we can not modify
#{set}: a collection that is not unorder and unindex. you can not change but you can:
#    add() or update() item
#    remove() or discard() item. If item does not exit discard will not raise error and remove() will raise error
#    you can pop(), clear(), del element or `set` list.
#    you can use union() or update() to join 2 list
# {dict}: unoderer, changable, indexed list
#    remove item by pop(itemkey) , or popitem() to remove the last item
#    you can clear(), del() list, you can del() list element
#    it can be like nested
"""
print(list)

# LOOP
# nested loop
# While loop
i = 1
while i < 20:
    if i % 2 == 0:
        print("i = " + str(i))
    elif i % 21 == 0:
        print("end game")
        break
    else:
        print("continue game")
        i += 1
        continue
    print("inscrease game")
    i += 1
else:
    print("i no longer < 20")

# For loop
# using for..in..range: range(number), range(startValue,endValue,inscrease)
# else:, pass like while loop


# Function:
def funArgurments(fname, fage, fschool="Hogwart"):
    print("Your name: " + fname)
    print("Your age: " + str(fage))


funArgurments("Harry Potter", 39)


# if you don't know, how many argument you will use. Please use *
def funArbitrary(*_vars):
    print("Your name is " + str(_vars[1]))


def funArbitrary2(food):
    for i in food:
        print(i)
    return len(food)


def funRecursion(fvar):
    if fvar > 0:
        result = 20 + funRecursion(fvar - 1)
        print(result)
    else:
        return 0
    return result


funArbitrary("Harry", "Ginny", "Ron", "Hermionie")
funArgurments(fname="Ron", fage=39)
funArgurments(fname="Bill", fage=20, fschool="Havard")
x = ["fish", "vegetable", "rice", "meat", "fruit"]
print("Amount of food: " + str(funArbitrary2(x)))
y = 20
print("Recursion of y = " + str(funRecursion(20)))


# LAMDA
# Syntax lamda function: lamda arguments : expression
def funLambda(fvar1, fvar2):
    return lambda fvar1, fvar2: fvar1 * fvar2


twelveTimes = funLambda(12, 12)  # return lambda
print("twelveTimes " + str(twelveTimes))
print("twelveTimes of 31 " + str(twelveTimes(31, 31)))  # using lambda

# ARRAY: use Python list instead
# remove(), append(), pop(), clear(), del, copy(), insert()...

# Iterator
# Python list is iterable object

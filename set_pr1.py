# To create ADT that implement the "set" concept. a. Add (new Element) -Place a value into the set , b. Remove (element) Remove the value c. Contains (element) Return true if element is in collection, d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection, e. Intersection of two sets , f. Union of two sets, g. Difference between two sets, h. Subset
from itertools import combinations

s1 = []
s2 = []
sub = []
inter = []
diff = []
n1 = int(input("Enter total elements in set 1:"))
n2 = int(input("Enter total elements in set 2:"))

print("\nEnter elemets in the set1")
for i in range(0, n1):
    x = input("Enter element:")
    s1.append(x)

print("\nEnter elemets in the set2")
for i in range(0, n2):
    x = input("Enter element:")
    s2.append(x)

class set_prog:
    def add(self, x, s):
        s.append(x)
        return s
    
    def rem(self, x, s):
        s.remove(x)
        return s
    
    def find(self, x, s):
        if x in s:
            return True
        else:
            return False
    
    def siz(self, s):
        return len(s)
    
    def inter(self, x, y):
        for i in x:
            for j in y:
                if i == j:
                    inter.append(i)
        return inter
    
    def uni(self, x, y):
        return x+y
    
    def dif(self, x, y):
        for i in x:
            if i not in y:
                diff.append(i)
        return diff
    
    def sub(self, x):
        for i in range(0, len(x) + 1):
            s = list(combinations(x, i))
            sub.append(s)
        print(sub)
        return

p = set_prog()
while True:
    print("\n!=========MENU=========!")
    print("1. Add element")
    print("2. Remove element")
    print("3. Check element")
    print("4. Check size")
    print("5. Intersection")
    print("6. Union")
    print("7. Difference")
    print("8. Subset")
    print("9. Exit")

    ch = int(input("Enter Your Choice:"))
    
    if ch == 1:
        while True:
            print("\n!=========ADD=========!")
            print("1. Set1")
            print("2. Set2")
            print("3. Exit")
            c = int(input("Enter your choice:"))

            if c == 1:
                x = input("Enter element to be added in the set:")
                print("Set 1 after adding element: ", p.add(x, s1))
            elif c == 2:
                x = input("Enter element to be added in the set:")
                print("Set 2 after adding element: ", p.add(x, s2))
            elif c == 3:
                break
            else:
                print("!! Alert - INVALID CHOICE")

    elif ch == 2:
        while True:
            print("\n!=========REMOVE=========!")
            print("1. Set1")
            print("2. Set2")
            print("3. Exit")
            c = int(input("Enter your choice:"))

            if c == 1:
                x = input("Enter element to be removed from the set:")
                print("Set 1 after removing element:", p.rem(x, s1))

            elif c == 2:
                x = input("Enter element to be removed from the set:")
                print("Set 2 after removing element:", p.rem(x, s2))
            elif c == 3:
                break
            else:
                print("!! Alert - INVALID CHOICE")

    elif ch == 3:
        while True:
            print("\n!=========CHECK=========!")
            print("1. Check element in Set1")
            print("2. Check element in Set2")
            print("3. Exit")
            c = int(input("Enter your choice:"))

            if c == 1:
                x = input("Enter element to be searched in the set:")
                if p.find(x, s1):
                    print("Element found in Set1")
                else:
                    print("Element not found in Set1")

            elif c == 2:
                x = input("Enter element to be searched in the set:")
                if p.find(x, s2):
                    print("Element found in Set2")
                else:
                    print("Element not found in Set2")

            elif c == 3:
                break
            
            else:
                print("!! Alert - INVALID CHOICE")

    elif ch == 4:
        while True:
            print("\n!=========SIZE=========!")
            print("1. Set1")
            print("2. Set2")
            print("3. Exit")
            c = int(input("Enter your choice:"))

            if c == 1:
                print("Length of Set1 is: ", p.siz(s1))
            elif c == 2:
                print("Length of Set2 is: ", p.siz(s2))
            elif c == 3:
                break
            else:
                print("!! Alert - INVALID CHOICE")
    
    elif ch == 5:
        print("\n!=========INTERSECTION=========!")
        print("Intersection of two sets are:", p.inter(s1, s2))

    elif ch == 6:
        print("\n!=========UNION=========!")
        print("Union of two sets are:", p.uni(s1, s2))

    elif ch == 7:
        print("\n!=========DIFFERENCE=========!")
        print("Difference of two sets are:", p.dif(s1, s2))
    
    elif ch == 8:
        print("\n!=========SUBSET=========!")
        print("1. Set 1")
        print("2. Set 2")
        print("3. Exit")
        c = int(input("Enter your choice:"))

        if c == 1:
            print("Subset of Set 1:")
            p.sub(s1)
        elif c == 2:
            print("Subset of Set 2:")
            p.sub(s2)
        elif c == 3:
            break
        else:
            print("!! Alert - INVALID CHOICE")

    elif ch == 9:
        print("!!!!Thank You!!!!")
        break

    else:
        print("!! Alert - INVALID CHOICE")
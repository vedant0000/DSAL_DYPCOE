class double:
    def __init__(self, size):
        self.hashtable = [None] * size
        self.size = size
        self.prime = 0
   
    def h1(self, data):
        return data%self.size
       
    def h2(self, data):
        if self.size != 1:
            self.prime = self.size - 1
        else:
            self.prime = self.size
           
        return self.prime - (data%self.prime)
       
    def double_hashing(self, key1, key2, data):
        for i in range(0, self.size):
            if self.hashtable[i] == None:
                self.hashtable[(key1 + (i * key2)) % self.size] = data
                break

class quadratic:
    def __init__(self, size):
        self.hashtable = [None] * size
        self.size = size
       
    def hash(self, data):
        return data%self.size
       
    def quad_hashing(self, data):
        for i in range(0, self.size):
            quad = (hash(data) + (i*i)) % self.size
            if self.hashtable[quad] == None:
                self.hashtable[quad] = data
                break

while True:
    print("!===MENU===!")
    print("1. Double Hashing")
    print("2. Quadratic Probing")
    print("3. Exit")
    ch = int(input("Enter your choice:"))
   
    if ch == 1:
        size = int(input("Enter size of the table:"))
        d = double(size)
        while True:
            print("!===DOUBLE HASHING===!")
            print("1. Add")
            print("2. Display")
            print("3. Exit")
           
            ch = int(input("Enter your choice:"))
           
            if ch == 1:
                data = int(input("Enter telephone number:"))
                d.double_hashing(d.h1(data), d.h2(data), data)
                print("===Data Added Successfully===")
            elif ch == 2:
                print("===Data Displayed Successfully===")
                print(d.hashtable)
            elif ch == 3:
                break
            else:
                print("!!! ENTER VALID CHOICE !!!")
   
    elif ch == 2:
        size = int(input("Enter size of the table:"))
        q = quadratic(size)
       
        while True:
            print("!===QUADRATIC PROBING===!")
            print("1. Add")
            print("2. Display")
            print("3. Exit")
           
            ch = int(input("Enter your choice:"))
           
            if ch == 1:
                data = int(input("Enter telephone number:"))
                q.quad_hashing(data)
                print("===Data Added Successfully===")
            elif ch == 2:
                print("===Data Displayed Successfully===")
                print(q.hashtable)
            elif ch == 3:
                break
            else:
                print("!!! ENTER VALID CHOICE !!!")
    elif ch == 3:
        break
    else:
        print("!!! ENTER VALID CHOICE !!!")

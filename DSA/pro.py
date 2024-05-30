# Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client’s telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone numbers.

import array as hashtable 
size=int(input("Enter Size of telephone book Entries:"))


hashtable=hashtable.array('i',[-1]*size)



def display():
    for i in range (0,size):
        print("Index[",i,"]=",hashtable[i],"\n") #'-1' indicates empty
       
def insert():
  
    list = input("Enter 8 digit number to insert in Telephone book:  ")
    list = list.split() #splited each value by split()
    
    for num in list:
        num = int(num)
        choice=0
        print("Which Collision Handling Technique do you want to use?")
        print("1) Linear Probing")
        print("2) Quadraic Probing")
        choice=int(input())
        #Linear Probing
        if(choice==1):
            key=num%size
            if(hashtable[key]==-1): #Insert if base address is empty
                hashtable[key]=num
            else:                 #Insert if base address is not empty
                i = (key + 1) % size
                while i != key:
                    if hashtable[i] == -1:
                        hashtable[i] = num
                        return
                    i = (i + 1) % size
                print("Hashtable Overflow")

        #Quadratic Probing
        elif(choice==2):       
            key = num % size
            if hashtable[key] == -1: #Insert if base address is empty
                hashtable[key] = num
            else:                #Insert if base address is not empty
                i = 1
                while i < size:
                    next_key = (key + i*i) % size
                    
                    if hashtable[next_key] == -1:
                        hashtable[next_key] = num
                        break
                    i += 1
                    
                    if i == size:
                        print("Hashtable Overflow")
        else:
            print("Enter Valid Input")


def delete():
     num=int(input("Enter number to delete from Telephone Book:"))
     for i in range (0,size):
       if(num==hashtable[i]):
         hashtable[i]=-1


def search():
    num = int(input("Enter number to search from telephone book:"))
    key = num % size
    i = 0
    while True:
        next_key = (key + i*i) % size
        if hashtable[next_key] == num:
            print("Number found at index", next_key)
            return
        elif hashtable[next_key] == -1 or next_key == key:
            print("Number not found in hash table")
            return
        i += 1


print("=========Telephone Book Database=========")
choice = 0
while True:
    print("******************")
    print("1) Insert        *")
    print("2) Delete        *")
    print("3) Search        *")
    print("4) Display       *")
    print("5) Exit          *")
    print("******************")
    choice = int(input())
    if choice == 1:
        insert()
    elif choice == 2:
        delete()
    elif choice == 3:
        search()
    elif choice == 4:
        display()
    elif choice == 5:
        break
    else:
        print("Enter Valid Choice")

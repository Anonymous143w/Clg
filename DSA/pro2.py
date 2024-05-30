#To create ADT that implement the “set” concept. a. Add (new Element) -Place a value into the set, b. Remove (element) Remove the value, c. Contains (element) Return true if element is in collection, d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection, e. Intersection of two sets, f. Union of two sets, g. Difference between two sets, h. Subset.

#Operations on Set
#Function for finding element from set
def contains(s):
    el1=input("Enter Element to search from Set: ")
    l1 = list(s)
    flag=1
    for i in range(len(l1)):
        if(l1[i]==el1):
            print("Element Found")
            flag=0
            break
    if(flag==1):
        print("Element Not Found")


#Two empty set initialization
s1=set()
s2=set()


print("===============Operations on Set==================")
choice = 0
while True:
    print("Enter Your Choice:")
    print("1) ADD")
    print("2) REMOVE")
    print("3) CONTAINS")
    print("4) OPERATIONS")
    print("5) DISPLAY")
    print("6) EXIT")
    choice = int(input())
    if choice == 1:
        #Add
        t=1
        while(t):
            n=int(input("Insert in Set 1 or 2:"))
            if(n==1):
                el1=input("Enter Element in Set 1: ")
                s1.add(el1)
            else:
                el2=input("Enter Element in Set 2: ")
                s2.add(el2)
            t=int(input("Press 1 to insert more: "))
    elif choice == 2:
        #remove
        n=int(input("Remove from Set 1 or 2:"))
        if(n==1):
            el1=input("Enter Element to remove from Set 1: ")
            s1.remove(el1)
        else:
            el2=input("Enter Element to remove from Set 2: ")
            s2.remove(el2)
    elif choice == 3:
        #contains
        n=int(input("Find from Set 1 or 2:"))
        if(n==1):
            contains(s1)
        elif(n==2):
            contains(s2)
        else:
            print("Enter valid Choice!")
            
    elif choice == 4:
        # union
        print("Union :", s1 | s2)
        # intersection
        print("\nIntersection :", s1 & s2)
        # difference
        print("\nDifference of Set1-Set2:", s1 - s2)
        print("Difference of Set2-Set1:", s2 - s1)
        # symmetric difference
        print("\nSymmetric difference :", s1 ^ s2)
        if(s1.issubset(s2)):
            print("\nSet 1 is Subset of Set 2")
        elif(s2.issubset(s1)):
            print("\nSet 2 is Subset of Set 1")
        else:
            print("\nBoth are Disjoint Sets")
    elif choice == 5:
        print("Set 1:",s1)
        print("Set 2:",s2)
    elif choice == 6:
        break
    else:
        print("Enter Valid Choice")
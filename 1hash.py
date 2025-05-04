def insert_linear(ht, n):
    key = int(input("Enter telephone no: "))
    loc = key % n
    if ht[loc] == -1:
        ht[loc] = key
    else:
        cnt = 0
        while ht[loc] != -1:
            cnt += 1
            loc = (loc + 1) % n
            if cnt == n:
                print("Hash Table is full")
                break
        ht[loc] = key

def find_linear(ht, n):
    key = int(input("Enter telephone no to find: "))
    loc = key % n
    cnt = 0
    while ht[loc] != -1:
        if ht[loc] == key:
            print("Key found at location", loc)
            break
        loc = (loc + 1) % n
        cnt += 1
        if cnt == n:
            break
    else:
        print("Key not found in the hash table.")

def remove_linear(ht, n):
    key = int(input("Enter telephone no to be removed: "))
    loc = key % n
    cnt = 0
    while ht[loc] != -1:
        if ht[loc] == key:
            print("Key found. Removing key.")
            ht[loc] = -1
            return
        loc = (loc + 1) % n
        cnt += 1
        if cnt == n:
            break
    else:
        print("Key not found.")

# Quadratic Probing
def insert_quadratic(ht, n):
    key = int(input("Enter telephone no: "))
    loc = key % n
    i = 1
    cnt = 0
    while ht[loc] != -1:
        loc = (key + (i**2 % n)) % n
        i += 1
        cnt += 1
        if cnt == n:
            print("Hash Table is full. Cannot insert the key.")
            return
    ht[loc] = key
    print(f"Key {key} inserted at position {loc}.")
    print(cnt)

def find_quadratic(ht, n):
    key = int(input("Enter telephone no to find: "))
    loc = key % n
    i = 1
    cnt = 0
    while ht[loc] != -1:
        if ht[loc] == key:
            print(f"Key {key} found at location {loc}.")
            return
        loc = (key + (i**2 % n)) % n
        i += 1
        cnt += 1
        if cnt == n:
            break
    print("Key not found in the hash table.")

def remove_quadratic(ht, n):
    key = int(input("Enter telephone no to be removed: "))
    loc = key % n
    i = 1
    cnt = 0
    while ht[loc] != -1:
        if ht[loc] == key:
            print(f"Key {key} found at location {loc}. Removing key.")
            ht[loc] = -1
            return
        loc = key + (i**2 % n)
        i += 1
        cnt += 1
        if cnt == n:
            break
    print("Key not found in the hash table.")
   
def display(ht):
    print("Hash Table:")
    print(ht)


def main():
    n = int(input("Enter hash table size: "))
    ht = [-1] * n

    while True:
        print("\nMenu")
        print("1. Insert (Linear Probing)")
        print("2. Insert (Quadratic Probing)")
        print("3. Display")
        print("4. Find (Linear Probing)")
        print("5. Find (Quadratic Probing)")
        print("6. Remove (Linear Probing)")
        print("7. Remove (Quadratic Probing)")
        print("8. Exit")
        ch = int(input("Enter Choice: "))
 
        if ch == 1:
            insert_linear(ht, n)
        elif ch == 2:
            insert_quadratic(ht, n)
        elif ch == 3:
            display(ht)
        elif ch == 4:
            find_linear(ht, n)
        elif ch == 5:
            find_quadratic(ht, n)
        elif ch == 6:
            remove_linear(ht, n)
        elif ch == 7:
            remove_quadratic(ht, n)
        elif ch == 8:
            break
        else:
            print("Invalid choice. Try again.")

main()

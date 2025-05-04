from set_operations import SetADT

def main():
    set1 = SetADT()

    # Input size and elements for the set
    size = int(input("Enter the number of elements: "))
    for i in range(size):
        el = int(input("Enter the Element: "))
        set1.add_element(el)

    while True:
        # Menu options
        print("\n***********Menu*************")
        print("x--------------------------x")
        print("|1. Add Element            |")
        print("|2. Remove Element         |")
        print("|3. Contains Element       |")
        print("|4. Size                   |")
        print("|5. Intersection of sets   |")
        print("|6. Union of sets          |")
        print("|7. Difference of sets     |")
        print("|8. Check Subset           |")
        print("|9. Iterator               |")
        print("|10. Exit                  |")
        print("x--------------------------x\n")
        
        choice = int(input("Enter Your Choice: "))
        
        if choice == 1:
            addEl = int(input("Enter number to add: "))
            set1.add_element(addEl)
            print(f"Updated Set: {set1.get_set()}\n")
        
        elif choice == 2:
            removeEl = int(input("Enter the number to delete from set: "))
            set1.remove_element(removeEl)
            print(f"Updated Set: {set1.get_set()}\n")
        
        elif choice == 3:
            element = int(input("Enter the element to check: "))
            if set1.contains_element(element):
                print(f"Element {element} is present in the set.\n")
            else:
                print(f"Element {element} is not found in the set.\n")
        
        elif choice == 4:
            print(f"The size of the set is: {set1.size()}\n")
        
        elif choice == 5:
            set2 = SetADT()
            set_size = int(input("Enter the size of the second set: "))
            for i in range(set_size):
                el = int(input(f"Enter element {i + 1} of second set: "))
                set2.add_element(el)
            print(f"Intersection: {set1.intersection(set2)}\n")
        
        elif choice == 6:
            set2 = SetADT()
            set_size = int(input("Enter the size of the second set: "))
            for i in range(set_size):
                el = int(input(f"Enter element {i + 1} of second set: "))
                set2.add_element(el)
            print(f"Union: {set1.union(set2)}\n")
        
        elif choice == 7:
            set2 = SetADT()
            set_size = int(input("Enter the size of the second set: "))
            for i in range(set_size):
                el = int(input(f"Enter element {i + 1} of second set: "))
                set2.add_element(el)
            print(f"Difference: {set1.difference(set2)}\n")
        
        elif choice == 8:
            set2 = SetADT()
            set_size = int(input("Enter the size of the second set: "))
            for i in range(set_size):
                el = int(input(f"Enter element {i + 1} of second set: "))
                set2.add_element(el)
            if set1.is_subset(set2):
                print(f"{set1.get_set()} is a subset of {set2.get_set()}\n")
            else:
                print(f"{set1.get_set()} is not a subset of {set2.get_set()}\n")
        
        elif choice == 9:
            print("Iterating through the set:")
            set1.iterate()
        
        elif choice == 10:
            print("Exiting program.")
            break
        
        else:
            print("Invalid choice. Please try again.")

# Run the main function
if __name__ == "__main__":
    main()





##set_operations.py

class SetADT:
    def __init__(self):
        self.set_elements = []

    def add_element(self, element):
        """Add an element to the set if it's not already present."""
        if element not in self.set_elements:
            self.set_elements.append(element)
        else:
            print(f"Element {element} is already in the set.")

    def remove_element(self, element):
        """Remove an element from the set if it exists."""
        if element in self.set_elements:
            self.set_elements.remove(element)
        else:
            print(f"Element {element} not found in the set.")

    def contains_element(self, element):
        """Check if an element exists in the set."""
        return element in self.set_elements

    def size(self):
        """Return the size of the set."""
        return len(self.set_elements)

    def intersection(self, other_set):
        """Return the intersection of two sets."""
        intersection_set = []
        for el in self.set_elements:
            if el in other_set.set_elements:
                intersection_set.append(el)
        return intersection_set

    def union(self, other_set):
        """Return the union of two sets."""
        union_set = self.set_elements.copy()
        for el in other_set.set_elements:
            if el not in union_set:
                union_set.append(el)
        return union_set

    def difference(self, other_set):
        """Return the difference of two sets."""
        difference_set = []
        for el in self.set_elements:
            if el not in other_set.set_elements:
                difference_set.append(el)
        return difference_set

    def is_subset(self, other_set):
        """Check if the current set is a subset of another set."""
        return all(el in other_set.set_elements for el in self.set_elements)

    def iterate(self):
        """Iterator for the set elements."""
        for element in self.set_elements:
            print(element)

    def get_set(self):
        """Return the elements of the set."""
        return self.set_elements

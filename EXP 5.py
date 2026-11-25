size = 10
parking = [-1] * size

def park_vehicle(vehicle):
    index = vehicle % size
    while parking[index] != -1:
        index = (index + 1) % size
    parking[index] = vehicle
    print("Vehicle", vehicle, "parked at slot", index)

def display():
    print("\nParking Slot Status:")
    for i in range(size):
        print("Slot", i, ":", parking[i])

n = int(input("Enter number of vehicles: "))
for i in range(n):
    vehicle = int(input("Enter vehicle number: "))
    park_vehicle(vehicle)

display()

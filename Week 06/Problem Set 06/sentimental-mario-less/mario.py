def valid(height):
     if height.isdigit():
          if int(height) > 0 and int(height) < 9:
               return True
          else:
            return False
     else:
          return False

height = input("Height: ")

while not valid(height):
     height = input("Height: ")

height = int(height)
for i in range(height):
        for j in range(height - (i + 1)):
            print(" ", end = "")
        for j in range(i + 1):
            print("#", end = "")
        print()
import math
def print_formatted(number):
    binary_string = ""
    decimal_string = ""
    octal_string = ""
    hex_string = ""
    width = math.floor(math.log(number, 2))  + 1
    for i in range(1, number + 1):
        decimal_string = "{0:d}".format(i).rjust(width, " ")
        octal_string = "{0:o}".format(i).rjust(width, " ")
        hex_string = "{0:X}".format(i).rjust(width, " ")
        binary_string = "{0:b}".format(i).rjust(width," ")
        print(decimal_string, octal_string, hex_string , binary_string)
if __name__ == "__main__":
    N = int(input())
    print_formatted(N)
# spreadsheet column ID MARKS CLASS NAME (in any order)
# first parse the string to create the namedtuple
from collections import namedtuple

N = int(input())

column = input()
data = ",".join(column.split())
Student = namedtuple('Student', data)

dataset = []
for i in range(N):
    stu_data = input().split()
    dataset.append(Student(*stu_data))

average  = 0
for i range(len(dataset)):
    average += int(dataset[i].MARKS)
print(average // len(dataset))




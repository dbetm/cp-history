if __name__ == '__main__':
    students = []
    for _ in range(int(input())):
        student = []
        name = input()
        score = float(input())
        student.append(name)
        student.append(score)
        students.append(student)
    students = sorted(students, key=lambda student: student[1])
    res_names = []
    lowest = students[0][1]
    second_lowest = 0
    flag = False
    for i in range(len(students)):
        if(students[i][1] == lowest):
            continue
        elif(flag and students[i][1] == second_lowest):
            res_names.append(students[i][0])
        elif(not flag):
            flag = True
            second_lowest = students[i][1]
            res_names.append(students[i][0])
        else:
            break
    res_names = sorted(res_names)
    for name in res_names:
        print(name)

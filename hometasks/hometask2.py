def stable_matching(student_prefs, hospital_prefs, capacity):
    n = len(student_prefs)
    m = len(hospital_prefs)

    hospital_rank = []
    for h in range(m):
        rank = {}
        for i in range(len(hospital_prefs[h])):
            student = hospital_prefs[h][i]
            rank[student] = i
        hospital_rank.append(rank)

    match_student = [-1] * n
    match_hospital = [[] for _ in range(m)]
    next_choice = [0] * n

    free_students = []
    for i in range(n):
        free_students.append(i)

    while len(free_students) > 0:
        s = free_students.pop(0)

        if next_choice[s] >= len(student_prefs[s]):
            continue

        h = student_prefs[s][next_choice[s]]
        next_choice[s] += 1

        if len(match_hospital[h]) < capacity[h]:
            match_hospital[h].append(s)
            match_student[s] = h
        else:
            worst = match_hospital[h][0]
            for student in match_hospital[h]:
                if hospital_rank[h][student] > hospital_rank[h][worst]:
                    worst = student

            if hospital_rank[h][s] < hospital_rank[h][worst]:
                match_hospital[h].remove(worst)
                match_hospital[h].append(s)
                match_student[s] = h
                match_student[worst] = -1
                free_students.append(worst)
            else:
                free_students.append(s)

    return match_student

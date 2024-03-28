# solved
# tags: implementation


def stableInternships(interns, teams):
    """Proposal
    Time: O(n^2)
    Space: O(n^2)
    """
    n = len(interns)
    teams_map = list()

    for _interns in teams:
        tmp = dict()
        for pos, intern in enumerate(_interns):
            tmp[intern] = pos
        teams_map.append(tmp)

    answers = dict()
    free_interns = list(range(n))
    current_intern_choices = [0 for _ in range(n)]

    while len(free_interns) > 0:
        intern = free_interns.pop()
        rank_idx = current_intern_choices[intern]
        team_choosen = interns[intern][rank_idx]
        current_intern_choices[intern] += 1

        if team_choosen in answers:
            current_intern_for_that_team = answers[team_choosen]
            if teams_map[team_choosen][intern] < teams_map[team_choosen][current_intern_for_that_team]:
                answers[team_choosen] = intern
                free_interns.append(current_intern_for_that_team)
            else:
                free_interns.append(intern)
        else:
            answers[team_choosen] = intern

    return [[intern, team] for team, intern in answers.items()]


def stableInternships2(interns, teams):
    """My solution - don't work for all cases (12/13)
    Time: O(n^2)
    Space: O(n^2)
    """
    n = len(interns)
    teams_map = list()

    for _interns in teams:
        tmp = dict()
        for pos, intern in enumerate(_interns):
            tmp[intern] = pos
        teams_map.append(tmp)

    selected_interns = set()
    selected_teams = set()
    answers = list()

    for col in range(n):
        selection = dict()
        for intern in range(n):
            if intern in selected_interns:
                continue

            team = interns[intern][col]
            
            if team in selected_teams:
                continue

            if selection.get(team) is not None:
                current_intern = selection[team]
                # print("current_intern: ", current_intern, ", intern: ", intern)
                if teams_map[team][intern] < teams_map[team][current_intern]:
                    selection[team] = intern
            else:
                selection[team] = intern

        for _team, _intern in selection.items():
            answers.append([_intern, _team])
            selected_interns.add(_intern)
            selected_teams.add(_team)
        
        if len(answers) == n:
            break

    return answers


if __name__ == "__main__":
    n = int(input())
    interns = list()
    teams = list()

    for _ in range(n):
        tmp = list(map(int, input("").split(" ")))
        interns.append(tmp)

    for _ in range(n):
        tmp = list(map(int, input("").split(" ")))
        teams.append(tmp)
    

    print(stableInternships(interns, teams))

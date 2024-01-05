# solved
# tags: implementation, hashTables


def tournamentWinner(competitions, results):
    """My solution
    Time: O(n)
    Space: O(k)

    n=number of competitions
    k=number of teams
    """
    winner_points = 0
    winner_name = ""
    scores = dict()

    for idx, result in enumerate(results):
        winner = competitions[idx][0] if result == 1 else competitions[idx][1]

        if winner in scores:
            scores[winner] += 3
        else:
            scores[winner] = 3
        
        if scores[winner] > winner_points:
            winner_points = scores[winner]
            winner_name = winner

    return winner_name



if __name__ == "__main__":
    num_competitions = int(input())
    competitions = list()

    for _ in range(num_competitions):
        competition = list(input().split(" "))
        competitions.append(competition)

    results = list(map(int, input().rstrip().split(" ")))

    print(tournamentWinner(competitions, results))